#!/bin/sh
set -e

mkdir -p /mnt/usb/opt/etc/syncthing /mnt/usb/syncthing /var/log /var/run /etc/systemd/system 2>/dev/null || true

# Register systemd unit file with OpenNGFW systemctl
ln -sf /mnt/usb/opt/etc/systemd/system/syncthing.service /etc/systemd/system/syncthing.service 2>/dev/null || true

echo "Syncthing installed successfully."
echo "Manage service via: systemctl {start|stop|restart|status} syncthing"
