#!/usr/bin/env bash
# ==============================================================================
# Recipe Build Script: yt-dlp
# Modern CLI video/audio downloader for OpenNGFW
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" \
         "${STAGE_DIR}/share/yt-dlp"

DOWNLOAD_URL="https://github.com/yt-dlp/yt-dlp/releases/download/2025.02.19/yt-dlp"
CACHED_BIN="/tmp/ngpkg_sources/yt-dlp-2025.02.19"

if [ ! -f "${CACHED_BIN}" ]; then
    echo "  [*] Downloading yt-dlp standalone payload..."
    mkdir -p "$(dirname "${CACHED_BIN}")"
    curl -fsSL -o "${CACHED_BIN}" "${DOWNLOAD_URL}" || wget -qO "${CACHED_BIN}" "${DOWNLOAD_URL}"
fi

echo "  [*] Staging yt-dlp executable..."
cp "${CACHED_BIN}" "${STAGE_DIR}/share/yt-dlp/yt-dlp"
chmod 755 "${STAGE_DIR}/share/yt-dlp/yt-dlp"

echo "  [*] Generating execution wrapper..."
cat << 'EOF' > "${STAGE_DIR}/bin/yt-dlp"
#!/bin/sh
export PATH="/mnt/usb/opt/bin:/root/.ngpkg-bin:/usr/bin:/bin:$PATH"
export LD_LIBRARY_PATH="/mnt/usb/opt/lib:$LD_LIBRARY_PATH"
export PYTHONUNBUFFERED=1
exec python3 /mnt/usb/opt/share/yt-dlp/yt-dlp "$@"
EOF
chmod 755 "${STAGE_DIR}/bin/yt-dlp"

echo "  [✓] yt-dlp staged successfully."
