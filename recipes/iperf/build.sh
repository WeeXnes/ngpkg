#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin"

SRC_DIR="/tmp/iperf-3.17.1"
if [ ! -d "${SRC_DIR}" ]; then
    curl -sSL "https://github.com/esnet/iperf/releases/download/3.17.1/iperf-3.17.1.tar.gz" | tar -xz -C /tmp/
fi

cd "${SRC_DIR}"
make clean 2>/dev/null || true

HOST_TRIPLET="$(${CROSS_CC} -dumpmachine)"

./configure \
    --host="${HOST_TRIPLET}" \
    --prefix=/mnt/usb/opt \
    --disable-shared \
    --enable-static \
    --without-openssl \
    CC="${CROSS_CC}" \
    CFLAGS="-mfloat-abi=soft -march=armv7-a -O2"

make -j2
cp -f src/iperf3 "${STAGE_DIR}/bin/iperf3"
chmod 755 "${STAGE_DIR}/bin/iperf3"
ln -sf iperf3 "${STAGE_DIR}/bin/iperf"

echo "  [✓] iperf3 staged successfully."
