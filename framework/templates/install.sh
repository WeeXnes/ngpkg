#!/bin/sh
# OpenNGFW Package Setup Hook
# Executed by 'pkg install <name>' on the router after payload extraction.
set -e

# Initialize configuration directories or state if needed
mkdir -p /mnt/usb/opt/etc/example-app 2>/dev/null || true
