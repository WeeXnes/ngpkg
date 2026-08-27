# Introduction to ngpkg

Welcome to the **ngpkg** (Netgear Package Manager) documentation. `ngpkg` is a standalone, lightweight package manager built specifically for **OpenNGFW** (Open Netgear Firmware) embedded Linux systems.

## Purpose

Embedded routers such as the Netgear R6300v2 operate with constrained onboard NAND flash memory (32 MB OS partition). Installing large userspace software (utilities, monitoring tools, shells, network services) directly to onboard flash risks filling or degrading the NAND storage.

`ngpkg` decouples application software from the base firmware by deploying packages to persistent external USB storage (`/mnt/usb/opt/`) and symlinking binaries to `$HOME/.ngpkg-bin/`.

## Key Capabilities

- **Zero Runtime Dependencies**: The client is written in V and translated into a standalone ANSI C file (`client/ngpkg.c`). It compiles against `musl` libc with no external shared library requirements.
- **Standalone Build Framework**: Packages are authored as standalone bash build scripts and JSON metadata manifests (`recipes/<name>/`).
- **Resilient Extraction**: Uses a multi-tier decompression routine capable of handling BusyBox `tar` and standard GNU `tar`.
- **Integrated Repository Server**: Includes an embedded HTTP repository daemon (`server/pkg_server.v`) providing index distribution and file serving.
