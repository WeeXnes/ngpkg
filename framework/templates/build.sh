#!/usr/bin/env bash
# ==============================================================================
# Recipe Build Script Hook for ngpkg
# Available Environment Variables:
#   $PKG_NAME        - Package name
#   $PKG_VERSION     - Package version
#   $STAGE_DIR       - Root destination directory (will be packaged into .ngpkg)
#   $CROSS_CC        - ARM Cross-compiler (if available)
#   $CROSS_STRIP     - ARM Cross-strip tool (if available)
#   $BUILDROOT_DIR   - Buildroot output directory (e.g. build/r6300v2)
# ==============================================================================

set -euo pipefail

echo "[*] Building ${PKG_NAME} ${PKG_VERSION}..."

# Example: compile source
# ${CROSS_CC} -O2 -s src/main.c -o "${STAGE_DIR}/bin/${PKG_NAME}"

# Example: create config
# mkdir -p "${STAGE_DIR}/etc"
# cp example.conf "${STAGE_DIR}/etc/"

echo "[+] Staged files for ${PKG_NAME}:"
ls -la "${STAGE_DIR}/bin" 2>/dev/null || true
