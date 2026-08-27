# Adding Packages to ngpkg

## Recipe Directory Layout

Each package recipe resides in `recipes/<name>/`:
- `recipe.json`: Metadata manifest
- `build.sh`: Cross-compilation and staging script

## Creating a New Recipe

Run the scaffolding command:
```bash
python3 framework/ngpkg_build.py new myapp
```

### Manifest Example (`recipe.json`)
```json
{
  "name": "myapp",
  "version": "1.0.0",
  "description": "Application description",
  "category": "utilities",
  "license": "MIT",
  "homepage": "https://example.com",
  "type": "source",
  "binaries": [
    "bin/myapp"
  ]
}
```

### Build Script Example (`build.sh`)
```bash
#!/usr/bin/env bash
set -euo pipefail

STAGE="${STAGE_DIR}"
mkdir -p "${STAGE}/bin"

# Compile or stage application files
${CROSS_CC:-arm-buildroot-linux-musleabi-gcc} -O2 src/main.c -o "${STAGE}/bin/myapp"
${CROSS_STRIP:-arm-buildroot-linux-musleabi-strip} --strip-all "${STAGE}/bin/myapp"
```

## Building and Validation

```bash
# Validate recipe schema
python3 framework/ngpkg_build.py validate recipes/myapp

# Build individual package
python3 framework/ngpkg_build.py build myapp

# Build all packages and generate repository index
python3 framework/ngpkg_build.py build-all
```
