#!/bin/sh
set -e

# Stop service using systemctl
systemctl stop syncthing 2>/dev/null || true
killall syncthing.bin syncthing 2>/dev/null || true

# Remove unit file link and runtime pid
rm -f /etc/systemd/system/syncthing.service /var/run/syncthing.pid 2>/dev/null || true
