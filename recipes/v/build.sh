#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for V Compiler (vlang) - ARMv7 musl
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib/vlang" "${STAGE_DIR}/etc/profile.d"

CACHE_DIR="/tmp/ngpkg_sources/vlang"
mkdir -p "${CACHE_DIR}"
cd "${CACHE_DIR}"

# 1. Fetch V repository and vc bootstrap if not already present
if [ ! -d "v/.git" ]; then
    echo "  [*] Cloning V compiler source repository..."
    git clone --depth 1 https://github.com/vlang/v.git "v"
else
    echo "  [*] Updating V compiler repository..."
    (cd "v" && git pull --ff-only 2>/dev/null || true)
fi

cd "${CACHE_DIR}/v"

if [ ! -d "vc/.git" ]; then
    echo "  [*] Cloning vc bootstrap repository..."
    git clone --depth 1 https://github.com/vlang/vc.git "vc"
else
    echo "  [*] Updating vc bootstrap repository..."
    (cd "vc" && git pull --ff-only 2>/dev/null || true)
fi

# 2. Compile ARM native V compiler binary from bootstrap C source
echo "  [*] Cross-compiling ARMv7 V compiler binary with ${CROSS_CC}..."
${CROSS_CC} -std=gnu99 -w -O1 -pipe -pie -fPIE vc/v.c -o "${STAGE_DIR}/lib/vlang/v" -lm -lpthread

if [ -n "${CROSS_STRIP:-}" ] && [ -x "${CROSS_STRIP:-}" ]; then
    ${CROSS_STRIP} --strip-all "${STAGE_DIR}/lib/vlang/v" 2>/dev/null || true
fi
chmod 755 "${STAGE_DIR}/lib/vlang/v"

# 3. Stage standard library (vlib), thirdparty headers, and compiler modules
echo "  [*] Staging vlib standard library, cmd modules, and thirdparty components..."
cp -r vlib "${STAGE_DIR}/lib/vlang/"
cp -r thirdparty "${STAGE_DIR}/lib/vlang/"
cp -r cmd "${STAGE_DIR}/lib/vlang/"
if [ -f "v.mod" ]; then
    cp -f "v.mod" "${STAGE_DIR}/lib/vlang/"
fi

# 4. Create executable wrapper in /mnt/usb/opt/bin/v
cat << 'EOF' > "${STAGE_DIR}/bin/v"
#!/bin/sh
# V Compiler wrapper for OpenNGFW / ngpkg
export VROOT="${VROOT:-/mnt/usb/opt/lib/vlang}"
export PATH="${VROOT}:${PATH}"

if [ ! -x "${VROOT}/v" ]; then
    echo "Error: V compiler binary not found at ${VROOT}/v" >&2
    exit 1
fi

exec "${VROOT}/v" "$@"
EOF
chmod 755 "${STAGE_DIR}/bin/v"

# 5. Shell profile integration
cat << 'EOF_PROF' > "${STAGE_DIR}/etc/profile.d/v.sh"
# V Compiler environment initialization
export VROOT="/mnt/usb/opt/lib/vlang"
export PATH="/mnt/usb/opt/bin:${VROOT}:$PATH"
EOF_PROF
chmod 644 "${STAGE_DIR}/etc/profile.d/v.sh"

echo "  [✓] V compiler ${PKG_VERSION:-0.5.2} packaged successfully."
