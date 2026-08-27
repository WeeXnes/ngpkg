#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for GNU Screen
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc" "${STAGE_DIR}/lib"

CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
SCREEN_TAR="${CACHE_DIR}/screen-4.9.1.tar.gz"
SCREEN_SRC="${CACHE_DIR}/screen-4.9.1"

if [ ! -f "${SCREEN_TAR}" ]; then
    echo "  [*] Downloading GNU Screen 4.9.1 source archive..."
    curl -fsSL "https://ftp.gnu.org/gnu/screen/screen-4.9.1.tar.gz" -o "${SCREEN_TAR}" 2>/dev/null || \
    wget -q -O "${SCREEN_TAR}" "https://ftp.gnu.org/gnu/screen/screen-4.9.1.tar.gz"
fi

if [ ! -d "${SCREEN_SRC}" ]; then
    echo "  [*] Extracting screen-4.9.1..."
    tar -xzf "${SCREEN_TAR}" -C "${CACHE_DIR}"
fi

BUILD_DIR="${CACHE_DIR}/build_screen"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if [ ! -f "Makefile" ]; then
    echo "  [*] Configuring screen 4.9.1..."
    "${SCREEN_SRC}/configure" \
        --host="${CROSS_HOST:-arm-buildroot-linux-musleabi}" \
        --prefix=/mnt/usb/opt \
        --enable-colors256 \
        --enable-rxvt_osc \
        --with-sys-screenrc=/mnt/usb/opt/etc/screenrc \
        CC="${CROSS_CC}" \
        CFLAGS="-O2 -pipe" \
        LIBS="-lncurses" \
        > /dev/null 2>&1
fi

echo "  [*] Compiling screen..."
make -j"$(nproc)" > /dev/null 2>&1

cp -f "${BUILD_DIR}/screen" "${STAGE_DIR}/bin/screen"
chmod 755 "${STAGE_DIR}/bin/screen"

if [ -f "${SCREEN_SRC}/etc/screenrc" ]; then
    cp -f "${SCREEN_SRC}/etc/screenrc" "${STAGE_DIR}/etc/screenrc"
fi

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libncurses; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi
