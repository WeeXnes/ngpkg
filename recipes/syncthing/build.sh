#!/usr/bin/env bash
# ==============================================================================
# Syncthing Package Build Script for OpenNGFW (ARMv7 Cortex-A9 / musl)
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc/profile.d" "${STAGE_DIR}/etc/syncthing" "${STAGE_DIR}/etc/systemd/system"

VERSION="${PKG_VERSION}"
TARBALL_URL="https://github.com/syncthing/syncthing/releases/download/v${VERSION}/syncthing-linux-arm-v${VERSION}.tar.gz"
CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
CACHE_FILE="${CACHE_DIR}/syncthing-linux-arm-v${VERSION}.tar.gz"

if [ ! -f "${CACHE_FILE}" ]; then
    echo "  [*] Downloading Syncthing v${VERSION}..."
    curl -fsSL -o "${CACHE_FILE}" "${TARBALL_URL}" || wget -qO "${CACHE_FILE}" "${TARBALL_URL}"
fi

TMP_DIR="/tmp/syncthing_extract_$$"
mkdir -p "${TMP_DIR}"
tar -xzf "${CACHE_FILE}" -C "${TMP_DIR}"

cp "${TMP_DIR}/syncthing-linux-arm-v${VERSION}/syncthing" "${STAGE_DIR}/bin/syncthing.bin"
chmod 755 "${STAGE_DIR}/bin/syncthing.bin"
rm -rf "${TMP_DIR}"

# Strip binary
if [ -n "${CROSS_STRIP:-}" ]; then
    ${CROSS_STRIP} "${STAGE_DIR}/bin/syncthing.bin" 2>/dev/null || true
fi

# Create standalone CLI wrapper in /mnt/usb/opt/bin/syncthing
cat << 'EOF' > "${STAGE_DIR}/bin/syncthing"
#!/bin/sh
CONFIG_DIR="/mnt/usb/opt/etc/syncthing"
DATA_DIR="/mnt/usb/syncthing"
mkdir -p "${CONFIG_DIR}" "${DATA_DIR}" 2>/dev/null || true

exec /mnt/usb/opt/bin/syncthing.bin --home="${CONFIG_DIR}" --gui-address="0.0.0.0:8384" "$@"
EOF
chmod 755 "${STAGE_DIR}/bin/syncthing"

# Create systemd service unit file for OpenNGFW systemctl
cat << 'EOF_UNIT' > "${STAGE_DIR}/etc/systemd/system/syncthing.service"
[Unit]
Description=Syncthing - Continuous File Synchronization
Documentation=man:syncthing(1)
After=network.target

[Service]
ExecStart=/mnt/usb/opt/bin/syncthing.bin --home=/mnt/usb/opt/etc/syncthing --gui-address=0.0.0.0:8384 --no-browser --logfile=/var/log/syncthing.log
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
EOF_UNIT
chmod 644 "${STAGE_DIR}/etc/systemd/system/syncthing.service"

echo "  [✓] Syncthing staged successfully with systemd unit."
