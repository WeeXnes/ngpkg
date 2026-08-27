#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for GNU Nano
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib"

CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
NANO_TAR="${CACHE_DIR}/nano-7.2.tar.xz"
NANO_SRC="${CACHE_DIR}/nano-7.2"

if [ ! -f "${NANO_TAR}" ]; then
    echo "  [*] Downloading GNU nano 7.2 source archive..."
    curl -fsSL "https://ftp.gnu.org/gnu/nano/nano-7.2.tar.xz" -o "${NANO_TAR}" 2>/dev/null || \
    wget -q -O "${NANO_TAR}" "https://ftp.gnu.org/gnu/nano/nano-7.2.tar.xz"
fi

if [ ! -d "${NANO_SRC}" ]; then
    echo "  [*] Extracting nano-7.2..."
    tar -xJf "${NANO_TAR}" -C "${CACHE_DIR}"
fi

BUILD_DIR="${CACHE_DIR}/build_nano"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if [ ! -f "Makefile" ]; then
    echo "  [*] Configuring nano 7.2..."
    "${NANO_SRC}/configure" \
        --host="${CROSS_HOST:-arm-buildroot-linux-musleabi}" \
        --prefix=/mnt/usb/opt \
        --disable-nls \
        --disable-speller \
        --enable-color \
        --enable-nanorc \
        CC="${CROSS_CC}" \
        CFLAGS="-O2 -pipe" \
        NCURSES_LIBS="-lncurses" \
        NCURSESW_LIBS="-lncurses" \
        > /dev/null 2>&1
fi

echo "  [*] Compiling nano..."
make LIBS="-lncurses" -j"$(nproc)" > /dev/null 2>&1

cp -f "${BUILD_DIR}/src/nano" "${STAGE_DIR}/bin/nano"
chmod 755 "${STAGE_DIR}/bin/nano"

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libncurses; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi
