#!/bin/sh
set -e

mkdir -p /mnt/usb/clyocloud/data \
         /mnt/usb/clyocloud/movies \
         /mnt/usb/clyocloud/shows \
         /mnt/usb/clyocloud/thumbs \
         /mnt/usb/clyocloud/previews \
         /mnt/usb/clyocloud/logs \
         /etc/systemd/system \
         /var/run 2>/dev/null || true

# Register systemd unit file with OpenNGFW systemctl
ln -sf /mnt/usb/opt/etc/systemd/system/clyocloud.service /etc/systemd/system/clyocloud.service 2>/dev/null || true

echo "ClyoCloud installed successfully."
echo "Manage service via: systemctl {start|stop|restart|status} clyocloud"
echo "Add users via:      clyo-user-manager add <username> <password>"
