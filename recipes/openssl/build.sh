#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/ssl" "${STAGE_DIR}/lib" "${STAGE_DIR}/include"

SRC_DIR="/tmp/openssl_build"
if [ ! -f "${SRC_DIR}/Configure" ]; then
    mkdir -p "${SRC_DIR}"
    curl -sSL "https://github.com/openssl/openssl/releases/download/openssl-3.3.1/openssl-3.3.1.tar.gz" | tar -xz -C "${SRC_DIR}" --strip-components=1
fi

cd "${SRC_DIR}"
make clean 2>/dev/null || true

CROSS_PREFIX="${CROSS_CC%-gcc}-"

./Configure linux-armv4 \
    --cross-compile-prefix="${CROSS_PREFIX}" \
    --prefix=/mnt/usb/opt \
    --openssldir=/mnt/usb/opt/ssl \
    -DOPENSSL_NO_ASYNC \
    -mfloat-abi=soft \
    -march=armv7-a \
    no-shared \
    no-tests \
    no-docs

make build_generated
make -j4 apps/openssl

cp apps/openssl "${STAGE_DIR}/bin/openssl"
${CROSS_CC%-gcc}-strip "${STAGE_DIR}/bin/openssl"

cp apps/openssl.cnf "${STAGE_DIR}/ssl/openssl.cnf"
mkdir -p "${STAGE_DIR}/ssl/certs" "${STAGE_DIR}/ssl/private"

echo "  [✓] OpenSSL 3.3.1 staged successfully."
