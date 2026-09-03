#!/bin/sh
set -e

mkdir -p /mnt/usb/netboot/tftp \
         /mnt/usb/netboot/www \
         /mnt/usb/isos \
         /mnt/usb/opt/etc/systemd/system \
         /etc/systemd/system 2>/dev/null || true

# Copy default bootloaders if missing in tftp directory
if [ -d /mnt/usb/opt/share/netboot/tftp ]; then
    cp -rn /mnt/usb/opt/share/netboot/tftp/* /mnt/usb/netboot/tftp/ 2>/dev/null || true
fi

# Ensure root ownership
chown -R 0:0 /mnt/usb/netboot /mnt/usb/opt/share/netboot 2>/dev/null || true

# Link systemd unit file
ln -sf /mnt/usb/opt/etc/systemd/system/netboot.service /etc/systemd/system/netboot.service 2>/dev/null || true

# Initialize configuration and generate initial boot.ipxe
/mnt/usb/opt/bin/netboot gen-ipxe >/dev/null 2>&1 || true

echo "OpenNGFW Netboot & ISO Server installed successfully."
echo "Store ISO images in: /mnt/usb/isos/"
echo "Manage service via: systemctl {start|stop|restart|status} netboot"
