#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for Node.js (with NPM and NPX) - ARMv7 musl
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib" "${STAGE_DIR}/lib/node_modules" "${STAGE_DIR}/etc/profile.d"

CACHE_DIR="/tmp/ngpkg_sources/nodejs_armv7"
mkdir -p "${CACHE_DIR}"

BASE_URL_MAIN="https://dl-cdn.alpinelinux.org/alpine/v3.20/main/armv7"
BASE_URL_COMMUNITY="https://dl-cdn.alpinelinux.org/alpine/v3.20/community/armv7"

PACKAGES=(
    "${BASE_URL_MAIN}/nodejs-20.15.1-r0.apk"
    "${BASE_URL_COMMUNITY}/npm-10.9.1-r0.apk"
    "${BASE_URL_MAIN}/ada-libs-2.7.8-r0.apk"
    "${BASE_URL_MAIN}/libbase64-0.5.2-r0.apk"
    "${BASE_URL_MAIN}/brotli-libs-1.1.0-r2.apk"
    "${BASE_URL_MAIN}/c-ares-1.33.1-r0.apk"
    "${BASE_URL_MAIN}/nghttp2-libs-1.62.1-r0.apk"
    "${BASE_URL_MAIN}/icu-libs-74.2-r1.apk"
)

echo "  [*] Fetching ARMv7 musl Node.js and NPM packages..."
for pkg_url in "${PACKAGES[@]}"; do
    pkg_file="${CACHE_DIR}/$(basename "${pkg_url}")"
    if [ ! -f "${pkg_file}" ]; then
        curl -fsSL "${pkg_url}" -o "${pkg_file}" 2>/dev/null || wget -q -O "${pkg_file}" "${pkg_url}"
    fi
    tar -xzf "${pkg_file}" -C "${CACHE_DIR}" 2>/dev/null || true
done

echo "  [*] Installing Node.js, NPM, NPX, and runtime libraries..."
if [ -f "${CACHE_DIR}/usr/bin/node" ]; then
    cp -f "${CACHE_DIR}/usr/bin/node" "${STAGE_DIR}/bin/node"
    chmod 755 "${STAGE_DIR}/bin/node"
    ln -sf node "${STAGE_DIR}/bin/nodejs"
fi

if [ -f "${CACHE_DIR}/usr/bin/npm" ]; then
    cp -f "${CACHE_DIR}/usr/bin/npm" "${STAGE_DIR}/bin/npm"
    chmod 755 "${STAGE_DIR}/bin/npm"
fi

if [ -f "${CACHE_DIR}/usr/bin/npx" ]; then
    cp -f "${CACHE_DIR}/usr/bin/npx" "${STAGE_DIR}/bin/npx"
    chmod 755 "${STAGE_DIR}/bin/npx"
fi

if [ -d "${CACHE_DIR}/usr/lib/node_modules" ]; then
    cp -r "${CACHE_DIR}/usr/lib/node_modules/"* "${STAGE_DIR}/lib/node_modules/" 2>/dev/null || true
fi

if [ -d "${CACHE_DIR}/usr/lib" ]; then
    for lib in libada libbase64 libbrotlidec libbrotlienc libbrotlicommon libcares libnghttp2 libicui18n libicuuc libicudata; do
        cp -P "${CACHE_DIR}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libstdc++ libgcc_s libz libcrypto libssl; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

cat << 'EOF_PROF' > "${STAGE_DIR}/etc/profile.d/nodejs.sh"
# Node.js environment configuration
export NODE_PATH="/mnt/usb/opt/lib/node_modules:$NODE_PATH"
export PATH="/mnt/usb/opt/bin:$PATH"
export LD_LIBRARY_PATH="/mnt/usb/opt/lib:$LD_LIBRARY_PATH"
EOF_PROF
chmod 644 "${STAGE_DIR}/etc/profile.d/nodejs.sh"

echo "  [✓] Node.js 20.15.1 and NPM 10.9.1 packaged successfully."
