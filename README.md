# ngpkg

Netgear package manager for [OpenNGFW](https://code.weexnes.dev/OpenNGFW): userspace apps on persistent USB storage, without using onboard flash.

[![License](https://img.shields.io/badge/license-MIT-000000?style=flat-square&labelColor=1f1f1f)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-OpenNGFW%20%C2%B7%20Linux%20ARMv7-000000?style=flat-square&labelColor=1f1f1f)](https://code.weexnes.dev/OpenNGFW/ngpkg)
[![Stack](https://img.shields.io/badge/stack-V-000000?style=flat-square&labelColor=1f1f1f)](https://vlang.io)

`ngpkg` is a standalone package manager for OpenNGFW (embedded Linux router operating systems). It lets routers run
userspace applications such as `bash`, `nano`, `htop`, `btop`, `screen`, `git`, `ufw`, `netclient` and `bareiron`,
installed on persistent USB storage (`/mnt/usb/opt`).

## Features

- **Zero runtime dependencies:** the client is written in V and translated to standalone C (`client/ngpkg.c`). It compiles against `musl` libc with no external library dependencies.
- **Persistent storage integration:** installs binaries to `/mnt/usb/opt` and manages symlinks in `$HOME/.ngpkg-bin/` and `/root/.ngpkg-bin/`.
- **Standalone recipe framework:** each package is defined by a `recipe.json` manifest and a standalone `build.sh` script.
- **Universal BusyBox extraction:** a multi-tier extraction pipeline compatible with BusyBox `tar` and GNU `tar`.
- **Package repository server:** a built-in HTTP server (`server/pkg_server.v`) providing package distribution and metadata APIs.

## Usage

### 1. Configure the repository

On the OpenNGFW router:

```bash
export REPO_URL="http://<SERVER_IP>:8000/packages"
pkg update
```

### 2. Commands

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

### Adding packages (recipe framework)

Each package in `recipes/<name>/` consists of two files:

- `recipe.json`: package metadata manifest
- `build.sh`: standalone cross-compilation and packaging script

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

### Building packages

```bash
# Build a single package
python3 framework/ngpkg_build.py build myapp

# Build all packages and generate the repository index
python3 framework/ngpkg_build.py build-all
```

## Build from source

```bash
# Build native host client, server, and package recipes
make

# Build ARM target client using the cross-toolchain
make client-arm

# Start the repository server on port 8000
make serve
```

## Project structure

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

## License

MIT License. See [LICENSE](LICENSE).
