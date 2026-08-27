#!/usr/bin/env python3
# ==============================================================================
# ngpkg Build Framework (ngpkg-build)
# Modular package build system & repository generator for OpenNGFW
# ==============================================================================

import argparse
import json
import os
import shutil
import subprocess
import sys
import tarfile
from pathlib import Path

FRAMEWORK_DIR = Path(__file__).resolve().parent
NGPKG_ROOT = FRAMEWORK_DIR.parent
RECIPES_DIR = NGPKG_ROOT / "recipes"
REPO_DIR = NGPKG_ROOT / "repo" / "packages"
TEMPLATES_DIR = FRAMEWORK_DIR / "templates"

# Auto-detect OpenNGFW Buildroot path (sibling directory or standard path)
CANDIDATE_BUILDROOT_DIRS = [
    NGPKG_ROOT.parent / "AnbergearOS" / "build" / "r6300v2",
    NGPKG_ROOT.parent / "OpenNGFW" / "build" / "r6300v2",
    NGPKG_ROOT / "buildroot_target",
    Path("/home/weexnes/AnbergearOS/build/r6300v2")
]

BUILD_DIR = None
for c in CANDIDATE_BUILDROOT_DIRS:
    if c.exists() and (c / "host" / "bin").exists():
        BUILD_DIR = c
        break

if not BUILD_DIR:
    BUILD_DIR = CANDIDATE_BUILDROOT_DIRS[0]

STRIP_TOOL = BUILD_DIR / "host" / "bin" / "arm-buildroot-linux-musleabi-strip"
CROSS_CC = BUILD_DIR / "host" / "bin" / "arm-buildroot-linux-musleabi-gcc"


def log(msg, symbol="*"):
    print(f"\033[1;34m[{symbol}]\033[0m {msg}")


def success(msg):
    print(f"\033[1;32m[✓]\033[0m {msg}")


def warn(msg):
    print(f"\033[1;33m[!]\033[0m {msg}")


def error(msg):
    print(f"\033[1;31m[✗]\033[0m {msg}", file=sys.stderr)


def strip_file(path):
    if os.path.islink(path) or not os.path.exists(path):
        return
    if STRIP_TOOL.exists():
        subprocess.run([str(STRIP_TOOL), "--strip-all", str(path)], check=False, stderr=subprocess.DEVNULL)
    else:
        subprocess.run(["strip", "--strip-unneeded", str(path)], check=False, stderr=subprocess.DEVNULL)


def copy_library(lib_pattern, dest_lib_dir):
    """Copies library and its symlink chain from Buildroot staging/target."""
    os.makedirs(dest_lib_dir, exist_ok=True)
    search_dirs = [
        BUILD_DIR / "staging" / "usr" / "lib",
        BUILD_DIR / "staging" / "lib",
        BUILD_DIR / "target" / "lib",
        BUILD_DIR / "target" / "usr" / "lib",
    ]
    found = False
    for sdir in search_dirs:
        if not sdir.exists():
            continue
        for f in os.listdir(sdir):
            if f.startswith(lib_pattern):
                src = sdir / f
                dest = Path(dest_lib_dir) / f
                if src.is_symlink():
                    target = os.readlink(src)
                    if os.path.lexists(str(dest)):
                        dest.unlink()
                    os.symlink(target, dest)
                else:
                    shutil.copy2(src, dest)
                    strip_file(dest)
                found = True
    if not found:
        warn(f"Shared library '{lib_pattern}' not found in Buildroot search paths.")


def package_payload(pkg_name, version, description, stage_dir, category="utilities"):
    """Creates .ngpkg archive and backwards compatible .apkg symlinks."""
    REPO_DIR.mkdir(parents=True, exist_ok=True)
    pkg_file = REPO_DIR / f"{pkg_name}-{version}.ngpkg"
    apkg_file = REPO_DIR / f"{pkg_name}-{version}.apkg"

    # Strip all binaries in staged directory
    for root, _, files in os.walk(stage_dir):
        for f in files:
            p = Path(root) / f
            if not p.is_symlink():
                # Check if executable or in bin/sbin/lib
                if any(k in str(p) for k in ["/bin/", "/sbin/", "/lib/"]):
                    strip_file(p)

    with tarfile.open(pkg_file, "w:gz") as tar:
        for item in os.listdir(stage_dir):
            tar.add(os.path.join(stage_dir, item), arcname=item)

    # Symlinks for backwards compatibility and unversioned requests
    if os.path.lexists(str(apkg_file)):
        apkg_file.unlink()
    os.symlink(f"{pkg_name}-{version}.ngpkg", apkg_file)

    for ext in ["ngpkg", "apkg"]:
        sym = REPO_DIR / f"{pkg_name}.{ext}"
        if os.path.lexists(str(sym)):
            sym.unlink()
        os.symlink(f"{pkg_name}-{version}.ngpkg", sym)

    sz_bytes = pkg_file.stat().st_size
    sz_str = f"{sz_bytes/(1024*1024):.1f}MB" if sz_bytes > 1024 * 1024 else f"{sz_bytes/1024:.0f}KB"

    success(f"Built \033[1;36m{pkg_name}\033[0m \033[1;33mv{version}\033[0m ({sz_str}) -> {pkg_file.name}")
    return {
        "name": pkg_name,
        "version": version,
        "size": sz_str,
        "size_bytes": sz_bytes,
        "description": description,
        "category": category,
        "filename": f"{pkg_name}-{version}.ngpkg",
    }


def resolve_recipe_dir(recipe_input):
    p = Path(recipe_input)
    if p.is_absolute() and p.is_dir():
        return p
    if (NGPKG_ROOT / p).is_dir():
        return NGPKG_ROOT / p
    if (RECIPES_DIR / p).is_dir():
        return RECIPES_DIR / p
    if p.is_dir():
        return p.resolve()
    return RECIPES_DIR / recipe_input

def build_recipe(recipe_name_or_path):
    """Builds a single recipe into a package."""
    recipe_dir = resolve_recipe_dir(recipe_name_or_path)

    manifest_file = recipe_dir / "recipe.json"
    if not manifest_file.exists():
        error(f"Recipe manifest not found at: {manifest_file}")
        return None

    with open(manifest_file, "r") as f:
        meta = json.load(f)

    name = meta["name"]
    version = meta["version"]
    desc = meta.get("description", "")
    category = meta.get("category", "utilities")
    pkg_type = meta.get("type", "custom")

    log(f"Processing recipe: \033[1;36m{name}\033[0m (\033[1;33mv{version}\033[0m, type: {pkg_type})")

    stage_dir = Path(f"/tmp/ngpkg_stage_{name}")
    if stage_dir.exists():
        shutil.rmtree(stage_dir)
    stage_dir.mkdir(parents=True, exist_ok=True)

    # 1. Handle build hook script if present
    build_script = recipe_dir / "build.sh"
    if build_script.exists():
        os.chmod(build_script, 0o755)
        env = os.environ.copy()
        env.update({
            "PKG_NAME": name,
            "PKG_VERSION": version,
            "STAGE_DIR": str(stage_dir),
            "CROSS_CC": str(CROSS_CC),
            "CROSS_STRIP": str(STRIP_TOOL),
            "BUILDROOT_DIR": str(BUILD_DIR),
            "RECIPE_DIR": str(recipe_dir),
            "NGPKG_ROOT": str(NGPKG_ROOT),
        })
        res = subprocess.run([str(build_script)], env=env, check=False)
        if res.returncode != 0:
            error(f"build.sh for {name} failed with exit code {res.returncode}")
            return None

    # 2. Handle built-in recipe types if build.sh didn't populate everything
    if pkg_type == "buildroot":
        br_pkg = meta.get("buildroot_package", name)
        # Search for binaries in Buildroot build dir or target dir
        for b in meta.get("binaries", []):
            dest_b = stage_dir / b
            dest_b.parent.mkdir(parents=True, exist_ok=True)
            found = False
            bin_name = Path(b).name
            for p in (BUILD_DIR / "build").glob(f"{br_pkg}*/{bin_name}"):
                if p.is_file() and os.access(p, os.X_OK):
                    shutil.copy2(p, dest_b)
                    found = True
                    break
            if not found:
                for p in (BUILD_DIR / "build").glob(f"{br_pkg}*/**/{bin_name}"):
                    if p.is_file() and os.access(p, os.X_OK):
                        shutil.copy2(p, dest_b)
                        found = True
                        break
            if not found:
                for target_path in [BUILD_DIR / "target" / b, BUILD_DIR / "staging" / "usr" / b, BUILD_DIR / "target" / "usr" / b]:
                    if target_path.exists():
                        shutil.copy2(target_path, dest_b)
                        found = True
                        break
            if not found and not dest_b.exists():
                warn(f"Binary '{b}' not found for package '{name}'")

        # Copy required libraries
        for lib in meta.get("libraries", []):
            copy_library(lib, stage_dir / "lib")

        # Copy config files
        for cfg in meta.get("config_files", []):
            dest_c = stage_dir / cfg
            dest_c.parent.mkdir(parents=True, exist_ok=True)
            for p in (BUILD_DIR / "build").glob(f"{br_pkg}*/{Path(cfg).name}"):
                if p.is_file():
                    shutil.copy2(p, dest_c)
                    break

    # Copy metadata into package
    meta_dir = stage_dir / "share" / "ngpkg"
    meta_dir.mkdir(parents=True, exist_ok=True)
    with open(meta_dir / "manifest.json", "w") as f:
        json.dump(meta, f, indent=2)

    return package_payload(name, version, desc, stage_dir, category)


def update_repository_index(entries):
    """Generates index.txt and index.json in repo/packages."""
    REPO_DIR.mkdir(parents=True, exist_ok=True)
    index_txt = REPO_DIR / "index.txt"
    index_json = REPO_DIR / "index.json"

    # 1. index.txt (name|version|size|description)
    with open(index_txt, "w") as f:
        for e in entries:
            f.write(f"{e['name']}|{e['version']}|{e['size']}|{e['description']}|{e['category']}\n")

    # 2. index.json (rich metadata)
    with open(index_json, "w") as f:
        json.dump({
            "schema_version": "1.0",
            "package_count": len(entries),
            "packages": entries
        }, f, indent=2)

    success(f"Generated repository index at: \033[1;36m{index_txt}\033[0m ({len(entries)} packages)")


def cmd_build_all():
    """Scans and builds all recipes in recipes/ directory."""
    if not RECIPES_DIR.exists():
        error(f"Recipes directory does not exist: {RECIPES_DIR}")
        return 1

    entries = []
    recipes = sorted([d.name for d in RECIPES_DIR.iterdir() if d.is_dir() and (d / "recipe.json").exists()])

    log(f"Discovered {len(recipes)} package recipes in {RECIPES_DIR}")
    for r in recipes:
        info = build_recipe(r)
        if info:
            entries.append(info)

    update_repository_index(entries)
    print("\n=======================================================================")
    print(f"  🎉 Built {len(entries)}/{len(recipes)} OpenNGFW Packages Successfully!")
    print(f"  Repository location: {REPO_DIR}")
    print("=======================================================================")
    return 0


def cmd_new(pkg_name):
    """Generates a new package recipe scaffold."""
    target_dir = RECIPES_DIR / pkg_name
    if target_dir.exists():
        error(f"Recipe '{pkg_name}' already exists at {target_dir}")
        return 1

    target_dir.mkdir(parents=True, exist_ok=True)
    with open(TEMPLATES_DIR / "recipe.json", "r") as f:
        tpl = f.read()

    tpl = tpl.replace("example-app", pkg_name).replace("example", pkg_name)
    with open(target_dir / "recipe.json", "w") as f:
        f.write(tpl)

    shutil.copy2(TEMPLATES_DIR / "build.sh", target_dir / "build.sh")
    os.chmod(target_dir / "build.sh", 0o755)

    success(f"Created new package recipe scaffold at \033[1;36m{target_dir}\033[0m")
    print("Files created:")
    print(f"  - {target_dir}/recipe.json  (Package metadata & dependencies)")
    print(f"  - {target_dir}/build.sh     (Build hook script)")
    return 0


def cmd_validate(recipe_name):
    """Validates a recipe's schema and files."""
    recipe_dir = resolve_recipe_dir(recipe_name)
    manifest = recipe_dir / "recipe.json"
    if not manifest.exists():
        error(f"recipe.json missing in {recipe_dir}")
        return 1

    try:
        with open(manifest, "r") as f:
            data = json.load(f)
    except Exception as e:
        error(f"Invalid JSON in {manifest}: {e}")
        return 1

    required_fields = ["name", "version", "description", "category", "type"]
    missing = [k for k in required_fields if k not in data]
    if missing:
        error(f"Missing required fields in recipe.json: {', '.join(missing)}")
        return 1

    success(f"Recipe '{data['name']}' ({data['version']}) validation PASSED!")
    return 0


def cmd_list_recipes():
    """Lists all available package recipes."""
    if not RECIPES_DIR.exists():
        print("No recipes found.")
        return 0

    print(f"\n{'Recipe':<16} {'Version':<10} {'Category':<14} {'Type':<12} Description")
    print("-" * 80)
    for r in sorted(RECIPES_DIR.iterdir()):
        if r.is_dir() and (r / "recipe.json").exists():
            try:
                with open(r / "recipe.json", "r") as f:
                    d = json.load(f)
                print(f"\033[1;36m{d.get('name', r.name):<16}\033[0m {d.get('version', '-'):<10} \033[1;35m{d.get('category', 'general'):<14}\033[0m {d.get('type', 'custom'):<12} {d.get('description', '')[:35]}")
            except Exception:
                print(f"{r.name:<16} [Invalid recipe.json]")
    print("")
    return 0


def main():
    parser = argparse.ArgumentParser(description="ngpkg Build Framework - OpenNGFW Package Builder")
    subparsers = parser.add_subparsers(dest="command", help="Command to run")

    # new
    p_new = subparsers.add_parser("new", help="Create a new package recipe scaffold")
    p_new.add_argument("name", help="Package name (e.g. redis, ripgrep)")

    # build
    p_build = subparsers.add_parser("build", help="Build an individual package recipe")
    p_build.add_argument("recipe", help="Recipe name or directory path")

    # build-all
    subparsers.add_parser("build-all", help="Build all recipes and generate repository index")

    # validate
    p_val = subparsers.add_parser("validate", help="Validate a recipe manifest")
    p_val.add_argument("recipe", help="Recipe name or directory path")

    # list
    subparsers.add_parser("list", help="List all available recipes")

    args = parser.parse_args()

    if args.command == "new":
        sys.exit(cmd_new(args.name))
    elif args.command == "build":
        info = build_recipe(args.recipe)
        sys.exit(0 if info else 1)
    elif args.command == "build-all":
        sys.exit(cmd_build_all())
    elif args.command == "validate":
        sys.exit(cmd_validate(args.recipe))
    elif args.command == "list":
        sys.exit(cmd_list_recipes())
    else:
        parser.print_help()
        sys.exit(0)


if __name__ == "__main__":
    main()
