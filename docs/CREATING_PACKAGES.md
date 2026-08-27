# Developer Guide: Adding Applications to ngpkg

This guide walks you through authoring a new package recipe for OpenNGFW using the `ngpkg-build` framework.

---

## 1. Scaffold a New Recipe

Run the recipe generator:
```bash
python3 framework/ngpkg_build.py new mypkg
```
This generates:
- `recipes/mypkg/recipe.json`
- `recipes/mypkg/build.sh`

---

## 2. Recipe Types

### Type A: Binary Package (`type: "binary"`)
Best for applications with pre-built static ARMv7 binaries available on GitHub releases.

**`recipes/mypkg/recipe.json`**:
```json
{
  "name": "mypkg",
  "version": "1.0.0",
  "description": "Example binary application",
  "category": "utilities",
  "license": "MIT",
  "homepage": "https://github.com/user/mypkg",
  "type": "binary"
}
```

**`recipes/mypkg/build.sh`**:
```bash
#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin"

# Fetch release archive
curl -fsSL "https://github.com/user/mypkg/releases/download/v1.0.0/mypkg-armv7.tar.gz" -o /tmp/mypkg.tar.gz
tar -xzf /tmp/mypkg.tar.gz -C /tmp/

cp -f /tmp/mypkg/mypkg "${STAGE_DIR}/bin/mypkg"
chmod 755 "${STAGE_DIR}/bin/mypkg"
```

---

### Type B: Buildroot Integration (`type: "buildroot"`)
Best for packages that are compiled as part of the Buildroot toolchain.

**`recipes/mypkg/recipe.json`**:
```json
{
  "name": "htop",
  "version": "3.3.0",
  "description": "Interactive process viewer and system monitor",
  "category": "monitoring",
  "license": "GPL-2.0",
  "homepage": "https://htop.dev",
  "type": "buildroot",
  "buildroot_package": "htop",
  "binaries": [
    "bin/htop"
  ],
  "libraries": [
    "libncurses.so"
  ]
}
```
The framework automatically discovers the compiled binary in Buildroot's build directory, copies required shared libraries, strips debug symbols, and bundles the `.ngpkg`.

---

### Type C: C/C++ Source Compilation (`type: "source"`)
Best for single-file or lightweight C programs.

**`recipes/mypkg/build.sh`**:
```bash
#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin"

# Compile directly using cross-compiler
${CROSS_CC} -O3 -s src/main.c -o "${STAGE_DIR}/bin/mypkg"
```

---

## 3. Building and Validating

```bash
# Validate recipe JSON and structure
python3 framework/ngpkg_build.py validate recipes/mypkg

# Build only this recipe
python3 framework/ngpkg_build.py build mypkg

# Build all recipes & update index
python3 framework/ngpkg_build.py build-all
```

The output package will be generated at `repo/packages/mypkg-<version>.ngpkg`.
