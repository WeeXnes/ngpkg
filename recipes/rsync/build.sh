#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin"

SRC_DIR="/tmp/rsync-3.3.0"
if [ ! -d "${SRC_DIR}" ]; then
    curl -sSL "https://download.samba.org/pub/rsync/src/rsync-3.3.0.tar.gz" | tar -xz -C /tmp/
fi

cd "${SRC_DIR}"
make clean 2>/dev/null || true

HOST_TRIPLET="$(${CROSS_CC} -dumpmachine)"

./configure \
    --host="${HOST_TRIPLET}" \
    --prefix=/mnt/usb/opt \
    --disable-debug \
    --disable-simd \
    --disable-asm \
    --disable-lz4 \
    --disable-zstd \
    --disable-xxhash \
    --disable-md2man \
    --disable-openssl \
    CC="${CROSS_CC}" \
    CFLAGS="-mfloat-abi=soft -march=armv7-a -O2"

make -j2
cp -f rsync "${STAGE_DIR}/bin/rsync"
chmod 755 "${STAGE_DIR}/bin/rsync"

echo "  [✓] rsync staged successfully."
