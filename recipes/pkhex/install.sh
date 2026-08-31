#!/bin/sh
set -e

mkdir -p /mnt/usb/opt/share/pkhex/public /var/log /var/run /etc/systemd/system 2>/dev/null || true

# Register systemd unit file with OpenNGFW systemctl
ln -sf /mnt/usb/opt/etc/systemd/system/pkhex.service /etc/systemd/system/pkhex.service 2>/dev/null || true

echo "PKHeX.Everywhere installed successfully."
echo "Manage service via: systemctl {start|stop|restart|status} pkhex"
echo "Web UI available at: http://$(hostname -I 2>/dev/null | awk '{print $1}' || echo 'router-ip'):5062/"
