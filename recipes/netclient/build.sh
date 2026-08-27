#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc/systemd/system"
CACHE_BIN="/tmp/netclient-linux-armv5"
if [ ! -f "${CACHE_BIN}" ]; then
    curl -fsSL "https://github.com/gravitl/netclient/releases/download/v1.1.0/netclient-linux-armv5" -o "${CACHE_BIN}" 2>/dev/null || \
    wget -q -O "${CACHE_BIN}" "https://github.com/gravitl/netclient/releases/download/v1.1.0/netclient-linux-armv5"
fi
cp -f "${CACHE_BIN}" "${STAGE_DIR}/bin/netclient"
chmod 755 "${STAGE_DIR}/bin/netclient"

cat << 'SERVICE' > "${STAGE_DIR}/etc/systemd/system/netclient.service"
[Unit]
Description=Netclient Daemon
After=network.target

[Service]
Type=simple
ExecStart=/mnt/usb/opt/bin/netclient daemon
Restart=always
RestartSec=5

[Install]
WantedBy=multi-user.target
SERVICE
