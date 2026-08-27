#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for UFW (Uncomplicated Firewall)
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/sbin" "${STAGE_DIR}/lib" "${STAGE_DIR}/etc/ufw" "${STAGE_DIR}/etc/default"

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"

# 1. Stage python runtime from sysroot if available
if [ -n "${SYSROOT}" ] && [ -d "${SYSROOT}/usr/lib/python3.11" ]; then
    if [ -f "${SYSROOT}/usr/bin/python3.11" ]; then
        cp -f "${SYSROOT}/usr/bin/python3.11" "${STAGE_DIR}/bin/python3"
        chmod 755 "${STAGE_DIR}/bin/python3"
    fi
    mkdir -p "${STAGE_DIR}/lib/python3.11"
    cp -r "${SYSROOT}/usr/lib/python3.11"/* "${STAGE_DIR}/lib/python3.11/" 2>/dev/null || true
    for lib in libpython3 libffi; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

# 2. Build UFW
CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
UFW_TAR="${CACHE_DIR}/ufw-0.36.2.tar.gz"
UFW_SRC="${CACHE_DIR}/ufw-0.36.2"

if [ ! -f "${UFW_TAR}" ]; then
    echo "  [*] Downloading UFW 0.36.2..."
    curl -fsSL "https://launchpad.net/ufw/0.36/0.36.2/+download/ufw-0.36.2.tar.gz" -o "${UFW_TAR}" 2>/dev/null || \
    wget -q -O "${UFW_TAR}" "https://launchpad.net/ufw/0.36/0.36.2/+download/ufw-0.36.2.tar.gz"
fi

if [ ! -d "${UFW_SRC}" ]; then
    echo "  [*] Extracting ufw-0.36.2..."
    tar -xzf "${UFW_TAR}" -C "${CACHE_DIR}"
fi

cd "${UFW_SRC}"
python3 ./setup.py build --build-base=/tmp/ufw_bld --build-lib=/tmp/ufw_lib > /dev/null 2>&1 || true
python3 ./setup.py install --prefix="/mnt/usb/opt" --root="${STAGE_DIR}" > /dev/null 2>&1 || true

if [ -d "${STAGE_DIR}/mnt/usb/opt" ]; then
    cp -r "${STAGE_DIR}/mnt/usb/opt"/* "${STAGE_DIR}/"
    rm -rf "${STAGE_DIR}/mnt"
fi
