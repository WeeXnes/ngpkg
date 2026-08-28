#!/usr/bin/env python3
# ==============================================================================
# ngpkg Build Framework (ngpkg-build)
# Modular, Standalone Package Build System & Repository Generator for OpenNGFW
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

# Auto-detect cross-compiler toolchain
def detect_toolchain():
    # 1. Check explicit environment variables
    env_cc = os.getenv("CROSS_CC")
    env_strip = os.getenv("CROSS_STRIP")
    if env_cc and os.path.isfile(env_cc):
        return Path(env_cc), Path(env_strip) if env_strip else Path(env_cc).with_name(Path(env_cc).name.replace("-gcc", "-strip"))

    # 2. Check candidate paths
    candidates = [
        Path("/home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-gcc"),
        NGPKG_ROOT.parent / "AnbergearOS" / "build" / "r6300v2" / "host" / "bin" / "arm-buildroot-linux-musleabi-gcc",
        NGPKG_ROOT.parent / "OpenNGFW" / "build" / "r6300v2" / "host" / "bin" / "arm-buildroot-linux-musleabi-gcc",
    ]
    for cc in candidates:
        if cc.is_file():
            strip = cc.with_name(cc.name.replace("-gcc", "-strip"))
            return cc, strip

    # 3. Check system PATH
    for name in ["arm-buildroot-linux-musleabi-gcc", "arm-linux-musleabi-gcc", "arm-linux-gnueabihf-gcc"]:
        p = shutil.which(name)
        if p:
            strip = shutil.which(name.replace("-gcc", "-strip")) or "strip"
            return Path(p), Path(strip)

    # 4. Fallback to host gcc
    return Path(shutil.which("gcc") or "/usr/bin/gcc"), Path(shutil.which("strip") or "/usr/bin/strip")


CROSS_CC, STRIP_TOOL = detect_toolchain()
CROSS_HOST = CROSS_CC.name.replace("-gcc", "") if "-gcc" in CROSS_CC.name else "arm-buildroot-linux-musleabi"


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
    if STRIP_TOOL and Path(STRIP_TOOL).exists():
        subprocess.run([str(STRIP_TOOL), "--strip-all"], check=False, stderr=subprocess.DEVNULL)
    else:
        subprocess.run(["strip", "--strip-unneeded", str(path)], check=False, stderr=subprocess.DEVNULL)


def package_payload(pkg_name, version, description, stage_dir, category="utilities"):
    """Creates .ngpkg archive and backwards compatible .apkg symlinks."""
    REPO_DIR.mkdir(parents=True, exist_ok=True)
    pkg_file = REPO_DIR / f"{pkg_name}-{version}.ngpkg"
    apkg_file = REPO_DIR / f"{pkg_name}-{version}.apkg"

    # Strip all binaries in staged directory (skip non-ELF or wrapper scripts)
    for root, _, files in os.walk(stage_dir):
        for f in files:
            p = Path(root) / f
            if not p.is_symlink() and any(k in str(p) for k in ["/bin/", "/sbin/", "/lib/", "/libexec/"]):
                if p.suffix in [".o", ".a"]:
                    continue
                if p.stat().st_size > 4:
                    with open(p, "rb") as check_f:
                        header = check_f.read(4)
                        if header == b"\x7fELF":
                            if STRIP_TOOL and Path(STRIP_TOOL).exists():
                                strip_flag = "--strip-unneeded" if ".so" in p.name else "--strip-all"
                                subprocess.run([str(STRIP_TOOL), strip_flag, str(p)], check=False, stderr=subprocess.DEVNULL)

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

    aliases = {
        "nodejs": ["node"],
        "v": ["vlang"],
    }
    for alias in aliases.get(pkg_name, []):
        for ext in ["ngpkg", "apkg"]:
            asym = REPO_DIR / f"{alias}.{ext}"
            if os.path.lexists(str(asym)):
                asym.unlink()
            os.symlink(f"{pkg_name}-{version}.ngpkg", asym)

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
    """Builds a single recipe into a package using its standalone build.sh script."""
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

    log(f"Building standalone recipe: \033[1;36m{name}\033[0m (\033[1;33mv{version}\033[0m)")

    stage_dir = Path(f"/tmp/ngpkg_stage_{name}")
    if stage_dir.exists():
        shutil.rmtree(stage_dir)
    stage_dir.mkdir(parents=True, exist_ok=True)

    build_script = recipe_dir / "build.sh"
    if not build_script.exists():
        error(f"build.sh missing in recipe directory: {recipe_dir}")
        return None

    os.chmod(build_script, 0o755)
    env = os.environ.copy()
    env.update({
        "PKG_NAME": name,
        "PKG_VERSION": version,
        "STAGE_DIR": str(stage_dir),
        "CROSS_CC": str(CROSS_CC),
        "CROSS_STRIP": str(STRIP_TOOL),
        "CROSS_HOST": str(CROSS_HOST),
        "RECIPE_DIR": str(recipe_dir),
        "NGPKG_ROOT": str(NGPKG_ROOT),
    })

    res = subprocess.run([str(build_script)], env=env, check=False)
    if res.returncode != 0:
        error(f"build.sh for {name} failed with exit code {res.returncode}")
        return None

    # Write manifest & package lifecycle hooks into stage
    meta_dir = stage_dir / "share" / "ngpkg" / name
    meta_dir.mkdir(parents=True, exist_ok=True)
    with open(meta_dir / "manifest.json", "w") as f:
        json.dump(meta, f, indent=2)

    # Copy optional lifecycle scripts if present in recipe
    for hook_name in ["install.sh", "uninstall.sh"]:
        hook_file = recipe_dir / hook_name
        if hook_file.exists():
            shutil.copy2(hook_file, meta_dir / hook_name)
            os.chmod(meta_dir / hook_name, 0o755)

    return package_payload(name, version, desc, stage_dir, category)


def update_repository_index(entries):
    """Generates index.txt and index.json in repo/packages."""
    REPO_DIR.mkdir(parents=True, exist_ok=True)
    index_txt = REPO_DIR / "index.txt"
    index_json = REPO_DIR / "index.json"

    with open(index_txt, "w") as f:
        for e in entries:
            f.write(f"{e['name']}|{e['version']}|{e['size']}|{e['description']}|{e['category']}\n")

    with open(index_json, "w") as f:
        json.dump({
            "schema_version": "1.0",
            "package_count": len(entries),
            "packages": entries
        }, f, indent=2)

    success(f"Generated repository index at: \033[1;36m{index_txt}\033[0m ({len(entries)} packages)")


def cmd_clean():
    """Purges all compiled package archives and indexes."""
    if REPO_DIR.exists():
        for item in REPO_DIR.iterdir():
            if item.is_file() or item.is_symlink():
                item.unlink()
            elif item.is_dir():
                shutil.rmtree(item)
    success("Cleaned all previous packages from repo/packages/")
    return 0


def cmd_build_all():
    """Scans and builds all standalone recipes in recipes/ directory."""
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


def cmd_rebuild_all():
    """Clean slate rebuild: purges previous builds and builds all recipes from scratch."""
    log("Starting complete clean rebuild of all packages...")
    cmd_clean()
    return cmd_build_all()


def cmd_new(pkg_name):
    """Generates a new standalone package recipe scaffold."""
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

    shutil.copy2(TEMPLATES_DIR / "uninstall.sh", target_dir / "uninstall.sh")
    os.chmod(target_dir / "uninstall.sh", 0o755)

    success(f"Created new standalone package recipe at \033[1;36m{target_dir}\033[0m")
    print("Files created:")
    print(f"  - {target_dir}/recipe.json    (Package metadata manifest)")
    print(f"  - {target_dir}/build.sh       (Standalone cross-compilation script)")
    print(f"  - {target_dir}/uninstall.sh   (Router pre-remove cleanup hook)")
    return 0


def cmd_validate(recipe_name):
    """Validates a recipe's schema and files."""
    recipe_dir = resolve_recipe_dir(recipe_name)
    manifest = recipe_dir / "recipe.json"
    build_script = recipe_dir / "build.sh"

    if not manifest.exists():
        error(f"recipe.json missing in {recipe_dir}")
        return 1

    if not build_script.exists():
        error(f"build.sh missing in {recipe_dir}")
        return 1

    try:
        with open(manifest, "r") as f:
            data = json.load(f)
    except Exception as e:
        error(f"Invalid JSON in {manifest}: {e}")
        return 1

    required_fields = ["name", "version", "description", "category"]
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
    parser = argparse.ArgumentParser(description="ngpkg Build Framework - OpenNGFW Standalone Package Builder")
    subparsers = parser.add_subparsers(dest="command", help="Command to run")

    p_new = subparsers.add_parser("new", help="Create a new standalone package recipe scaffold")
    p_new.add_argument("name", help="Package name (e.g. redis, ripgrep)")

    p_build = subparsers.add_parser("build", help="Build an individual package recipe")
    p_build.add_argument("recipe", help="Recipe name or directory path")

    subparsers.add_parser("build-all", help="Build all standalone recipes and generate repository index")
    subparsers.add_parser("rebuild-all", help="Clean slate rebuild of all standalone recipes")
    subparsers.add_parser("clean", help="Clean all generated packages and indexes in repo/packages/")

    p_val = subparsers.add_parser("validate", help="Validate a recipe manifest and build.sh")
    p_val.add_argument("recipe", help="Recipe name or directory path")

    subparsers.add_parser("list", help="List all available recipes")

    args = parser.parse_args()

    if args.command == "new":
        sys.exit(cmd_new(args.name))
    elif args.command == "build":
        info = build_recipe(args.recipe)
        sys.exit(0 if info else 1)
    elif args.command == "build-all":
        sys.exit(cmd_build_all())
    elif args.command == "rebuild-all":
        sys.exit(cmd_rebuild_all())
    elif args.command == "clean":
        sys.exit(cmd_clean())
    elif args.command == "validate":
        sys.exit(cmd_validate(args.recipe))
    elif args.command == "list":
        sys.exit(cmd_list_recipes())
    else:
        parser.print_help()
        sys.exit(0)


if __name__ == "__main__":
    main()
