#!/bin/sh
# Pre-remove hook for netboot
systemctl stop netboot 2>/dev/null || true
killall -9 dnsmasq netboot-httpd 2>/dev/null || true
rm -f /etc/systemd/system/netboot.service
