#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/share/btop"
CACHE_TAR="/tmp/btop-1.4.7-arm.tar.gz"
if [ ! -f "${CACHE_TAR}" ]; then
    curl -fsSL "https://github.com/aristocratos/btop/releases/download/v1.4.7/btop-armv7-unknown-linux-musleabi.tar.gz" -o "${CACHE_TAR}" 2>/dev/null || \
    wget -q -O "${CACHE_TAR}" "https://github.com/aristocratos/btop/releases/download/v1.4.7/btop-armv7-unknown-linux-musleabi.tar.gz"
fi
TMP_D=$(mktemp -d)
tar -xzf "${CACHE_TAR}" -C "${TMP_D}"
cp -f "${TMP_D}/btop/bin/btop" "${STAGE_DIR}/bin/btop-bin"
chmod 755 "${STAGE_DIR}/bin/btop-bin"

cat << 'WRAPPER' > "${STAGE_DIR}/bin/btop"
#!/bin/sh
if [ -t 0 ]; then
    stty cols 120 rows 35 2>/dev/null || true
    export COLUMNS="${COLUMNS:-120}"
    export LINES="${LINES:-35}"
fi
exec /mnt/usb/opt/bin/btop-bin "$@"
WRAPPER
chmod 755 "${STAGE_DIR}/bin/btop"

if [ -d "${TMP_D}/btop/share/btop/themes" ]; then
    cp -r "${TMP_D}/btop/share/btop/themes" "${STAGE_DIR}/share/btop/"
fi
rm -rf "${TMP_D}"
