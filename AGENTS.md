# OpenNGFW Package Manager (`ngpkg`) - AI Agent Packaging & Development Guide

> **Target Audience:** Autonomous AI agents and developers creating, modifying, or cross-compiling packages for OpenNGFW routers.

---

## 1. Architectural Principles & Repository Boundaries

1. **Primary Workspace:** All `ngpkg` development, client/server code, and recipe authoring **must strictly take place inside `~/ngpkg`**.
2. **Downstream Firmware Cache:** `AnbergearOS/dl/ngpkg` is a read-only build mirror used by Buildroot firmware generation (`post-build.sh`). Never edit files inside `AnbergearOS/dl/`.
3. **Target Router Environment:**
   * **Hardware:** Broadcom BCM4708 / ARMv7-A Dual-Core Cortex-A9 (e.g., Netgear R6300v2).
   * **C Standard Library:** `musl` libc (embedded, lightweight).
   * **Installation Prefix:** Persistent USB storage mounted at `/mnt/usb/opt`.
   * **User Executables:** Symlinked automatically to `$HOME/.ngpkg-bin/` and `/root/.ngpkg-bin/`.
   * **Firmware Constraints:** Read-only rootfs in RAM; binaries MUST NOT write directly into `/usr/` or `/etc/` at runtime unless symlinked.

---

## 2. Recipe Structure & File Layout

Every package recipe resides in `recipes/<package-name>/` and adheres to this structure:

```text
recipes/<package-name>/
├── recipe.json        # [Mandatory] Package metadata manifest
├── build.sh           # [Mandatory] Cross-compilation & staging script
├── uninstall.sh       # [Optional] Router-side pre-remove teardown hook
└── install.sh         # [Optional] Router-side post-install setup hook
```

---

## 3. `recipe.json` Schema Specification

```json
{
  "name": "example-app",
  "version": "1.0.0",
  "description": "Short, clear description of the application for CLI and web UI",
  "category": "utilities",
  "license": "MIT",
  "homepage": "https://example.com",
  "type": "source",
  "binaries": [
    "bin/example-app"
  ],
  "dependencies": [],
  "hooks": {
    "post_install": "install.sh",
    "pre_remove": "uninstall.sh"
  }
}
```

### Standard Categories
* `utilities` - General tools (`nano`, `htop`, `screen`, `btop`)
* `development` - Compilers, interpreters, runtime environments (`nodejs`, `v`, `git`)
* `networking` - Network daemons and VPN tools (`netclient`, `ufw`)
* `servers` - Lightweight service daemons (`bareiron`)

---

## 4. Cross-Compilation & Staging Rules

### Environment Variables Provided to `build.sh`
When `framework/ngpkg_build.py` runs `build.sh`, the following environment variables are exported:

| Variable | Description | Example |
| :--- | :--- | :--- |
| `STAGE_DIR` | Absolute path to temporary package root hierarchy | `/tmp/ngpkg_stage_nano` |
| `CROSS_CC` | Cross-compiler executable | `.../arm-buildroot-linux-musleabi-gcc` |
| `CROSS_STRIP` | Cross-toolchain strip utility | `.../arm-buildroot-linux-musleabi-strip` |
| `CROSS_HOST` | GNU target triplet | `arm-buildroot-linux-musleabi` |
| `PKG_NAME` | Name from `recipe.json` | `nano` |
| `PKG_VERSION` | Version from `recipe.json` | `7.2` |
| `RECIPE_DIR` | Absolute path to current recipe directory | `~/ngpkg/recipes/nano` |
| `NGPKG_ROOT` | Absolute path to repository root | `~/ngpkg` |

### Critical Staging Guidelines for Agents

1. **Target Directory Structure:**
   * Binaries: `${STAGE_DIR}/bin/`
   * System Binaries: `${STAGE_DIR}/sbin/`
   * Shared Libraries: `${STAGE_DIR}/lib/`
   * Configuration: `${STAGE_DIR}/etc/`
   * Profile Environment Scripts: `${STAGE_DIR}/etc/profile.d/`
2. **Binary Stripping:**
   * Always run `${CROSS_STRIP} --strip-all <binary>` on all ELF binaries and `.so` files to keep package archives small.
3. **Shared Library Bundling:**
   * If a binary depends on standard runtime libraries (`libstdc++.so`, `libgcc_s.so`, `libncurses.so`), copy them from the compiler sysroot into `${STAGE_DIR}/lib/`:
   ```bash
   SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
   if [ -d "${SYSROOT}/usr/lib" ]; then
       for lib in libstdc++ libgcc_s; do
           cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
       done
   fi
   ```
4. **Handling Pre-Compiled ARMv7 Binaries (e.g., Alpine musl):**
   * Pre-compiled Alpine packages use `/lib/ld-musl-armhf.so.1`.
   * OpenNGFW rootfs provides `/lib/ld-musl-armhf.so.1 -> libc.so`.
   * In the recipe `build.sh`, write a shell wrapper in `bin/<app>` ensuring `LD_LIBRARY_PATH="/mnt/usb/opt/lib:$LD_LIBRARY_PATH"` is exported before launching the binary:
   ```bash
   cat << 'EOF' > "${STAGE_DIR}/bin/myapp"
   #!/bin/sh
   export LD_LIBRARY_PATH="/mnt/usb/opt/lib:$LD_LIBRARY_PATH"
   export PATH="/mnt/usb/opt/bin:$PATH"
   exec /mnt/usb/opt/bin/myapp.bin "$@"
   EOF
   chmod 755 "${STAGE_DIR}/bin/myapp"
   ```

---

## 5. Lifecycle Hooks (`install.sh` & `uninstall.sh`)

### `uninstall.sh` (Pre-Remove Hook)
Executed on the router by `pkg remove <name>` **before** deleting files.
```bash
#!/bin/sh
set -e
# Stop daemon if running
killall myapp 2>/dev/null || true
```

### `install.sh` (Post-Install Hook)
Executed on the router by `pkg install <name>` **after** unpacking files.
```bash
#!/bin/sh
set -e
# Create runtime directories or default state
mkdir -p /mnt/usb/opt/var/log/myapp 2>/dev/null || true
```

---

## 6. Step-by-Step Recipe Creation Workflow

```mermaid
flowchart LR
    Scaffold["1. make new PKG=app"] --> Edit["2. Edit recipe.json & build.sh"]
    Edit --> Validate["3. python3 ngpkg_build.py validate recipes/app"]
    Validate --> Build["4. python3 ngpkg_build.py build app"]
    Build --> Rebuild["5. make rebuild-all"]
    Rebuild --> Test["6. make test & make serve"]
```

### 1. Scaffold New Recipe
```bash
make new PKG=ripgrep
```

### 2. Implement `recipes/ripgrep/recipe.json` & `build.sh`
Fill in metadata, download source or binaries, cross-compile, strip, and stage into `${STAGE_DIR}`.

### 3. Validate
```bash
python3 framework/ngpkg_build.py validate recipes/ripgrep
```

### 4. Build Individual Package
```bash
python3 framework/ngpkg_build.py build ripgrep
```

### 5. Full Clean-Slate Rebuild
```bash
make rebuild-all
```

---

## 7. Testing & Verification Checklist for AI Agents

Before submitting code or finalizing packages, verify:
- [ ] `python3 framework/ngpkg_build.py validate recipes/<name>` passes with 0 errors.
- [ ] Binary files in package archive are verified ARM 32-bit ELF (`file` or `readelf -h`).
- [ ] Executable wrapper scripts have `chmod 755`.
- [ ] `make test` passes.
- [ ] Package archive is generated in `repo/packages/<name>-<version>.ngpkg`.
- [ ] `repo/packages/index.json` and `repo/packages/index.txt` contain the new entry.
