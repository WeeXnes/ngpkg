# Setup and Deployment Guide

## USB Storage Preparation

OpenNGFW automatically mounts the first partition of an attached USB storage drive to `/mnt/usb` and configures `/mnt/usb/opt` as the software root.

Format the USB drive with `ext4`:
```bash
mkfs.ext4 /dev/sda1
```

Insert the USB drive into the router. The `S30storage` service will detect and mount it at boot time.

## Router Configuration

Configure the repository endpoint by setting the `REPO_URL` variable:
```bash
export REPO_URL="http://192.168.1.100:8000/packages"
pkg update
```

To persist the repository URL across reboots, add it to `/etc/profile` or `/etc/zshrc`.

## Running the Repository Server

On your host machine or build server:
```bash
# Build packages and generate index
python3 framework/ngpkg_build.py build-all

# Start the repository server
make serve
# or
./tools/bin/pkg_server
```

The server listens on port 8000 by default and serves files from `repo/packages/`.
