#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for GNU Bash
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib"

CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
BASH_TAR="${CACHE_DIR}/bash-5.2.21.tar.gz"
BASH_SRC="${CACHE_DIR}/bash-5.2.21"

if [ ! -f "${BASH_TAR}" ]; then
    echo "  [*] Downloading GNU bash 5.2.21 source archive..."
    curl -fsSL "https://ftp.gnu.org/gnu/bash/bash-5.2.21.tar.gz" -o "${BASH_TAR}" 2>/dev/null || \
    wget -q -O "${BASH_TAR}" "https://ftp.gnu.org/gnu/bash/bash-5.2.21.tar.gz"
fi

if [ ! -d "${BASH_SRC}" ]; then
    echo "  [*] Extracting bash-5.2.21..."
    tar -xzf "${BASH_TAR}" -C "${CACHE_DIR}"
fi

BUILD_DIR="${CACHE_DIR}/build_bash"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

if [ ! -f "Makefile" ]; then
    echo "  [*] Configuring bash 5.2.21..."
    bash_cv_getcwd_malloc=yes \
    bash_cv_job_control_missing=present \
    bash_cv_sys_named_pipes=present \
    bash_cv_func_sigsetjmp=present \
    bash_cv_printf_a_format=yes \
    CC_FOR_BUILD="gcc -std=gnu89" \
    "${BASH_SRC}/configure" \
        --host="${CROSS_HOST:-arm-buildroot-linux-musleabi}" \
        --prefix=/mnt/usb/opt \
        --without-bash-malloc \
        --disable-nls \
        CC="${CROSS_CC}" \
        CFLAGS="-O2 -pipe" \
        > /dev/null 2>&1
fi

echo "  [*] Compiling bash..."
make -j"$(nproc)" > /dev/null 2>&1

cp -f "${BUILD_DIR}/bash" "${STAGE_DIR}/bin/bash"
chmod 755 "${STAGE_DIR}/bin/bash"

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libreadline libhistory libncurses; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi
