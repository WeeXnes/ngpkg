#!/usr/bin/env bash
# ==============================================================================
# Standalone Recipe Build Script for ngpkg
# Available Environment Variables:
#   $PKG_NAME        - Package name
#   $PKG_VERSION     - Package version
#   $STAGE_DIR       - Root destination directory (will be packaged into .ngpkg)
#   $CROSS_CC        - ARM Cross-compiler executable path
#   $CROSS_STRIP     - ARM Cross-strip tool executable path
#   $CROSS_HOST      - Target architecture triple (e.g. arm-buildroot-linux-musleabi)
#   $RECIPE_DIR      - Path to the recipe directory
#   $NGPKG_ROOT      - Root directory of the ngpkg repository
# ==============================================================================

set -euo pipefail

echo "[*] Building ${PKG_NAME} ${PKG_VERSION}..."

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc"

# Example 1: Compile from C source
# ${CROSS_CC} -O2 -pipe "${RECIPE_DIR}/src/main.c" -o "${STAGE_DIR}/bin/${PKG_NAME}"

# Example 2: Download upstream tarball and compile
# curl -fsSL "https://example.com/${PKG_NAME}-${PKG_VERSION}.tar.gz" -o "/tmp/${PKG_NAME}.tar.gz"
# tar -xzf "/tmp/${PKG_NAME}.tar.gz" -C /tmp/
# cd "/tmp/${PKG_NAME}-${PKG_VERSION}" && ./configure --host="${CROSS_HOST}" --prefix=/mnt/usb/opt
# make -j$(nproc) && make install DESTDIR="${STAGE_DIR}"

echo "[+] Staged files for ${PKG_NAME}:"
ls -la "${STAGE_DIR}/bin" 2>/dev/null || true
