# 🛡️ ngpkg — Next-Generation Package Manager for OpenNGFW

[![Platform](https://img.shields.io/badge/platform-OpenNGFW%20%7C%20Linux%20ARMv7-cyan.svg)](https://code.weexnes.dev/OpenNGFW/ngpkg)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Built With V](https://img.shields.io/badge/built%20with-Vlang-blue.svg)](https://vlang.io)

`ngpkg` is the high-performance, standalone package manager designed specifically for **OpenNGFW** (embedded Linux router operating systems). It enables routers to run rich userspace applications (like `nano`, `htop`, `btop`, `screen`, `git`, `ufw`, `netclient`, `bareiron`) off persistent USB storage (`/mnt/usb/opt`) without consuming precious onboard flash.

---

## 🌟 Key Features

- **Zero Runtime Dependencies**: Written in V and pre-translated to pure standard C (`ngpkg.c`). Runs on `musl` libc without dynamic dependencies.
- **Branded User Binaries**: Installs binary symlinks into `$HOME/.ngpkg-bin/` (and `/root/.ngpkg-bin/`), automatically integrated into `$PATH`.
- **Modular Recipe Framework**: Simple declarative `recipe.json` + `build.sh` system that lets anyone easily create and build new packages.
- **Universal BusyBox Extraction**: Resilient multi-tier decompression pipeline compatible with any BusyBox or GNU tar configuration.
- **High-Performance Repo Server**: Built-in Vlang HTTP server featuring a modern dark-mode glassmorphic dashboard.

---

## 🚀 Quick Start on Router

### 1. Configure Repository
On your OpenNGFW router:
```bash
export REPO_URL="http://<SERVER_IP>:8000/packages"
pkg update
```

### 2. Available Commands
```bash
# Update local index
pkg update

# List available & installed packages
pkg list

# Search for a package
pkg search wireguard

# Inspect package details & installed files
pkg info screen

# Install an application to /mnt/usb/opt
pkg install btop
pkg install screen
pkg install git

# Remove an application and clean symlinks
pkg remove btop

# Check USB storage and prefix status
pkg status
```

---

## 🛠️ Adding New Packages (Recipe Framework)

Adding a new application is as simple as running:

```bash
# Scaffold a new recipe
python3 framework/ngpkg_build.py new myapp
```

This creates `recipes/myapp/recipe.json`:
```json
{
  "name": "myapp",
  "version": "1.0.0",
  "description": "My awesome application",
  "category": "utilities",
  "license": "MIT",
  "homepage": "https://example.com",
  "type": "binary",
  "source": {
    "url": "https://github.com/user/myapp/releases/download/v1.0.0/myapp-armv7.tar.gz"
  },
  "binaries": [
    "bin/myapp"
  ]
}
```

Then build it:
```bash
# Build single recipe
python3 framework/ngpkg_build.py build myapp

# Or build all recipes & update index
python3 framework/ngpkg_build.py build-all
```

For detailed instructions, see [Creating Packages Guide](docs/CREATING_PACKAGES.md).

---

## 📂 Repository Structure

```text
ngpkg/
├── client/              # Client source tree (ngpkg.v & standalone ngpkg.c)
├── server/              # Package repository server (pkg_server.v)
├── framework/           # ngpkg-build CLI engine & recipe validator
├── recipes/             # Modular package recipes (nano, htop, btop, git, screen...)
├── repo/packages/       # Built .ngpkg archives and index.txt / index.json
├── docs/                # Comprehensive developer documentation
├── Makefile             # Workspace build orchestration
└── README.md            # Project overview
```

---

## ⚙️ Building the Toolchain Locally

```bash
# Build native client, server, and all package recipes
make

# Build ARM target client (requires Buildroot toolchain)
make client-arm

# Launch repository server & web dashboard on port 8000
make serve
```

---

## 📄 License
MIT License. Free and open source for the OpenNGFW community.
