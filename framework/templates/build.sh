#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for Example App
# Target: ARMv7 Cortex-A9 (musl)
# ==============================================================================
set -euo pipefail

# 1. Prepare stage directories (Installs to /mnt/usb/opt hierarchy)
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib" "${STAGE_DIR}/etc" "${STAGE_DIR}/etc/profile.d"

# 2. Compile or download application
echo "  [*] Compiling ${PKG_NAME} ${PKG_VERSION} with ${CROSS_CC}..."
${CROSS_CC} -O2 -pipe src/main.c -o "${STAGE_DIR}/bin/${PKG_NAME}"

# 3. Strip binary for minimal storage footprint
if [ -n "${CROSS_STRIP:-}" ] && [ -x "${CROSS_STRIP:-}" ]; then
    ${CROSS_STRIP} --strip-all "${STAGE_DIR}/bin/${PKG_NAME}" 2>/dev/null || true
fi
chmod 755 "${STAGE_DIR}/bin/${PKG_NAME}"

# 4. Copy shared library dependencies from toolchain sysroot if needed
SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libstdc++ libgcc_s; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

echo "  [✓] ${PKG_NAME} ${PKG_VERSION} packaged successfully."
