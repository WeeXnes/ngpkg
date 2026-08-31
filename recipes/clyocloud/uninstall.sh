#!/bin/sh
set -e

# Stop service using systemctl
systemctl stop clyocloud 2>/dev/null || true
clyocloud stop 2>/dev/null || true

# Remove unit file link and runtime pid
rm -f /etc/systemd/system/clyocloud.service /var/run/clyocloud.pid 2>/dev/null || true
