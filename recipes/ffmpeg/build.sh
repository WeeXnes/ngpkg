#!/usr/bin/env bash
# ==============================================================================
# Standalone Recipe Build Script: ffmpeg & ffprobe for OpenNGFW
# Statically linked ARM release binaries from John Van Sickle
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin"

CACHE_DIR="/tmp/ngpkg_sources/ffmpeg"
mkdir -p "${CACHE_DIR}"

STATIC_TAR="${CACHE_DIR}/ffmpeg-release-armel-static.tar.xz"
STATIC_URL="https://johnvansickle.com/ffmpeg/releases/ffmpeg-release-armel-static.tar.xz"

if [ ! -f "${STATIC_TAR}" ]; then
    echo "  [*] Downloading FFmpeg static ARM release..."
    curl -fsSL "${STATIC_URL}" -o "${STATIC_TAR}" 2>/dev/null || \
    wget -q -O "${STATIC_TAR}" "${STATIC_URL}"
fi

echo "  [*] Extracting ffmpeg and ffprobe binaries..."
TMP_EXTRACT=$(mktemp -d)
tar -xJf "${STATIC_TAR}" -C "${TMP_EXTRACT}"

# Find extracted binaries
FFMPEG_BIN=$(find "${TMP_EXTRACT}" -type f -name "ffmpeg" | head -n 1)
FFPROBE_BIN=$(find "${TMP_EXTRACT}" -type f -name "ffprobe" | head -n 1)

if [ -z "${FFMPEG_BIN}" ] || [ -z "${FFPROBE_BIN}" ]; then
    echo "  [✗] Error: Failed to find ffmpeg or ffprobe in extracted archive" >&2
    rm -rf "${TMP_EXTRACT}"
    exit 1
fi

cp -f "${FFMPEG_BIN}" "${STAGE_DIR}/bin/ffmpeg.bin"
cp -f "${FFPROBE_BIN}" "${STAGE_DIR}/bin/ffprobe.bin"
chmod 755 "${STAGE_DIR}/bin/ffmpeg.bin" "${STAGE_DIR}/bin/ffprobe.bin"

# Create clean execution wrappers
cat << 'EOF_FFMPEG' > "${STAGE_DIR}/bin/ffmpeg"
#!/bin/sh
export PATH="/mnt/usb/opt/bin:$PATH"
exec /mnt/usb/opt/bin/ffmpeg.bin "$@"
EOF_FFMPEG
chmod 755 "${STAGE_DIR}/bin/ffmpeg"

cat << 'EOF_FFPROBE' > "${STAGE_DIR}/bin/ffprobe"
#!/bin/sh
export PATH="/mnt/usb/opt/bin:$PATH"
exec /mnt/usb/opt/bin/ffprobe.bin "$@"
EOF_FFPROBE
chmod 755 "${STAGE_DIR}/bin/ffprobe"

rm -rf "${TMP_EXTRACT}"

echo "  [✓] FFmpeg and FFprobe staged successfully."
