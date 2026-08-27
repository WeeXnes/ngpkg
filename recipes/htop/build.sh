#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for htop
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib"

CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
HTOP_TAR="${CACHE_DIR}/htop-3.3.0.tar.xz"
HTOP_SRC="${CACHE_DIR}/htop-3.3.0"

if [ ! -f "${HTOP_TAR}" ]; then
    echo "  [*] Downloading htop 3.3.0 source archive..."
    curl -fsSL "https://github.com/htop-dev/htop/releases/download/3.3.0/htop-3.3.0.tar.xz" -o "${HTOP_TAR}" 2>/dev/null || \
    wget -q -O "${HTOP_TAR}" "https://github.com/htop-dev/htop/releases/download/3.3.0/htop-3.3.0.tar.xz"
fi

if [ ! -d "${HTOP_SRC}" ]; then
    echo "  [*] Extracting htop-3.3.0..."
    tar -xJf "${HTOP_TAR}" -C "${CACHE_DIR}"
fi

BUILD_DIR="${CACHE_DIR}/build_htop"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if [ ! -f "Makefile" ]; then
    echo "  [*] Configuring htop 3.3.0..."
    "${HTOP_SRC}/configure" \
        --host="${CROSS_HOST:-arm-buildroot-linux-musleabi}" \
        --prefix=/mnt/usb/opt \
        --disable-unicode \
        --disable-sensors \
        --disable-capabilities \
        --disable-delayacct \
        --disable-openvz \
        --disable-vserver \
        CC="${CROSS_CC}" \
        CFLAGS="-O2 -pipe" \
        NCURSES_LIBS="-lncurses" \
        NCURSESW_LIBS="-lncurses" \
        > /dev/null 2>&1
fi

echo "  [*] Compiling htop..."
make LIBS="-lncurses" -j"$(nproc)" > /dev/null 2>&1

cp -f "${BUILD_DIR}/htop" "${STAGE_DIR}/bin/htop"
chmod 755 "${STAGE_DIR}/bin/htop"

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libncurses; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi
