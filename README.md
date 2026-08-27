# ngpkg - Netgear Package Manager for OpenNGFW

[![Platform](https://img.shields.io/badge/platform-OpenNGFW%20%7C%20Linux%20ARMv7-cyan.svg)](https://code.weexnes.dev/OpenNGFW/ngpkg)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Built With V](https://img.shields.io/badge/built%20with-Vlang-blue.svg)](https://vlang.io)

`ngpkg` is a standalone package manager designed for OpenNGFW (embedded Linux router operating systems). It enables routers to run userspace applications (such as `bash`, `nano`, `htop`, `btop`, `screen`, `git`, `ufw`, `netclient`, `bareiron`) installed on persistent USB storage (`/mnt/usb/opt`) without utilizing onboard flash memory.

---

## Features

- **Zero Runtime Dependencies**: The client is written in V and translated to standalone C (`client/ngpkg.c`). It compiles against `musl` libc with no external library dependencies.
- **Persistent Storage Integration**: Installs binaries to `/mnt/usb/opt` and automatically manages symlinks in `$HOME/.ngpkg-bin/` and `/root/.ngpkg-bin/`.
- **Standalone Recipe Framework**: Each package is defined by a `recipe.json` manifest and a standalone `build.sh` script.
- **Universal BusyBox Extraction**: Multi-tier extraction pipeline compatible with BusyBox `tar` and GNU `tar`.
- **Package Repository Server**: Built-in HTTP server (`server/pkg_server.v`) providing package distribution and metadata APIs.

---

## Router Usage

### 1. Configure Repository
On the OpenNGFW router:
```bash
export REPO_URL="http://<SERVER_IP>:8000/packages"
pkg update
```

### 2. Available Commands
```bash
# Update local package index
pkg update

# List available and installed packages
pkg list

# Search packages
pkg search <query>

# Show package metadata and installed file list
pkg info <package>

# Install a package to /mnt/usb/opt
pkg install <package>

# Remove a package and clean symlinks
pkg remove <package>

# Show storage breakdown and installation status
pkg status
```

---

## Adding Packages (Recipe Framework)

Each package in `recipes/<name>/` consists of two files:
- `recipe.json`: Package metadata manifest
- `build.sh`: Standalone cross-compilation and packaging script

### Creating a Recipe

Scaffold a new recipe:
```bash
python3 framework/ngpkg_build.py new <name>
```

Example `recipes/myapp/recipe.json`:
```json
{
  "name": "myapp",
  "version": "1.0.0",
  "description": "Utility description",
  "category": "utilities",
  "license": "MIT",
  "homepage": "https://example.com",
  "type": "source",
  "binaries": [
    "bin/myapp"
  ]
}
```

Example `recipes/myapp/build.sh`:
```bash
#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin"

# Cross-compile or download application
${CROSS_CC:-arm-buildroot-linux-musleabi-gcc} -O2 src/main.c -o "${STAGE_DIR}/bin/myapp"
${CROSS_STRIP:-arm-buildroot-linux-musleabi-strip} --strip-all "${STAGE_DIR}/bin/myapp"
```

### Building Packages

```bash
# Build a single package
python3 framework/ngpkg_build.py build myapp

# Build all packages and generate repository index
python3 framework/ngpkg_build.py build-all
```

---

## Repository Structure

```text
ngpkg/
├── client/              # Client source code (ngpkg.v and standalone ngpkg.c)
├── server/              # Package repository server (pkg_server.v)
├── framework/           # Recipe build orchestration engine (ngpkg_build.py)
├── recipes/             # Standalone package build recipes
├── repo/packages/       # Built .ngpkg archives and index metadata
├── docs/                # Developer and CLI documentation
├── Makefile             # Workspace build targets
└── README.md            # Project overview
```

---

## Local Compilation

```bash
# Build native host client, server, and package recipes
make

# Build ARM target client using cross-toolchain
make client-arm

# Start repository server on port 8000
make serve
```

---

## License

MIT License.
