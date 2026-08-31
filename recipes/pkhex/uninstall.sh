#!/bin/sh
set -e

# Stop service using systemctl
systemctl stop pkhex 2>/dev/null || true
killall pkhex-server 2>/dev/null || true

# Remove unit file link and runtime pid
rm -f /etc/systemd/system/pkhex.service /var/run/pkhex.pid 2>/dev/null || true
