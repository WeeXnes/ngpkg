#!/usr/bin/env bash
# ==============================================================================
# Standalone Recipe Build Script: Python 3 (Native ARMv7 Soft-Float Musl Edition)
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" \
         "${STAGE_DIR}/lib" \
         "${STAGE_DIR}/lib/python3.11/lib-dynload"

PY_BUILD_DIR="/home/weexnes/AnbergearOS/build/r6300v2/build/python3-3.11.10"
SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || echo '')"
REAL_CC="${CROSS_CC}.br_real"
if [ ! -f "${REAL_CC}" ]; then
    REAL_CC="${CROSS_CC}"
fi

echo "  [*] Compiling missing native C extensions (zlib, _ssl, _hashopenssl, unicodedata, pyexpat)..."
# 1. Compile zlib module
"${REAL_CC}" -shared -fPIC -O2 --sysroot="${SYSROOT}" \
    -I"${PY_BUILD_DIR}/Include" -I"${PY_BUILD_DIR}/Include/internal" -I"${PY_BUILD_DIR}" -I"${PY_BUILD_DIR}/Modules" \
    "${PY_BUILD_DIR}/Modules/zlibmodule.c" -lz \
    -o "${STAGE_DIR}/lib/python3.11/lib-dynload/zlib.cpython-311-arm-linux-gnueabi.so"

# 2. Compile _ssl module
"${REAL_CC}" -shared -fPIC -O2 --sysroot="${SYSROOT}" \
    -I"${PY_BUILD_DIR}/Include" -I"${PY_BUILD_DIR}/Include/internal" -I"${PY_BUILD_DIR}" -I"${PY_BUILD_DIR}/Modules" \
    "${PY_BUILD_DIR}/Modules/_ssl.c" -lssl -lcrypto \
    -o "${STAGE_DIR}/lib/python3.11/lib-dynload/_ssl.cpython-311-arm-linux-gnueabi.so"

# 3. Compile _hashopenssl module
"${REAL_CC}" -shared -fPIC -O2 --sysroot="${SYSROOT}" \
    -I"${PY_BUILD_DIR}/Include" -I"${PY_BUILD_DIR}/Include/internal" -I"${PY_BUILD_DIR}" -I"${PY_BUILD_DIR}/Modules" \
    "${PY_BUILD_DIR}/Modules/_hashopenssl.c" -lssl -lcrypto \
    -o "${STAGE_DIR}/lib/python3.11/lib-dynload/_hashopenssl.cpython-311-arm-linux-gnueabi.so"

# 4. Compile unicodedata module
"${REAL_CC}" -shared -fPIC -O2 --sysroot="${SYSROOT}" \
    -I"${PY_BUILD_DIR}/Include" -I"${PY_BUILD_DIR}/Include/internal" -I"${PY_BUILD_DIR}" -I"${PY_BUILD_DIR}/Modules" \
    "${PY_BUILD_DIR}/Modules/unicodedata.c" \
    -o "${STAGE_DIR}/lib/python3.11/lib-dynload/unicodedata.cpython-311-arm-linux-gnueabi.so"

# 5. Compile pyexpat module
"${REAL_CC}" -shared -fPIC -O2 --sysroot="${SYSROOT}" \
    -I"${PY_BUILD_DIR}/Include" -I"${PY_BUILD_DIR}/Include/internal" -I"${PY_BUILD_DIR}" -I"${PY_BUILD_DIR}/Modules" -I"${PY_BUILD_DIR}/Modules/expat" \
    "${PY_BUILD_DIR}/Modules/pyexpat.c" "${PY_BUILD_DIR}/Modules/expat/xmlparse.c" "${PY_BUILD_DIR}/Modules/expat/xmlrole.c" "${PY_BUILD_DIR}/Modules/expat/xmltok.c" \
    -DHAVE_EXPAT_CONFIG_H \
    -o "${STAGE_DIR}/lib/python3.11/lib-dynload/pyexpat.cpython-311-arm-linux-gnueabi.so"

echo "  [*] Staging native Python 3 executable and dynamic libraries..."
cp -f "${PY_BUILD_DIR}/python" "${STAGE_DIR}/bin/python3.11.bin"
cp -f "${PY_BUILD_DIR}/libpython3.11.so.1.0" "${STAGE_DIR}/lib/"
ln -sf libpython3.11.so.1.0 "${STAGE_DIR}/lib/libpython3.11.so"
ln -sf libpython3.11.so.1.0 "${STAGE_DIR}/lib/libpython3.so"

echo "  [*] Staging compiled extension modules..."
if [ -d "${PY_BUILD_DIR}/build/lib.linux-arm-3.11" ]; then
    cp -f "${PY_BUILD_DIR}/build/lib.linux-arm-3.11"/*.so "${STAGE_DIR}/lib/python3.11/lib-dynload/"
fi

echo "  [*] Staging Python 3 standard library..."
cp -rf "${PY_BUILD_DIR}/Lib"/* "${STAGE_DIR}/lib/python3.11/"
# Remove test directories to save space
rm -rf "${STAGE_DIR}/lib/python3.11/test" "${STAGE_DIR}/lib/python3.11/ctypes/test" "${STAGE_DIR}/lib/python3.11/unittest/test"

# Copy sysroot SSL/crypto and zlib shared libraries
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libssl libcrypto libz libffi; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

echo "  [*] Stripping all ELF binaries and modules..."
${CROSS_STRIP} --strip-all "${STAGE_DIR}/bin/python3.11.bin" 2>/dev/null || true
find "${STAGE_DIR}/lib" -type f -name "*.so*" -exec ${CROSS_STRIP} --strip-all {} + 2>/dev/null || true

echo "  [*] Generating environment wrapper..."
cat << 'EOF' > "${STAGE_DIR}/bin/python3"
#!/bin/sh
export PATH="/mnt/usb/opt/bin:/root/.ngpkg-bin:/usr/bin:/bin:$PATH"
export LD_LIBRARY_PATH="/mnt/usb/opt/lib:$LD_LIBRARY_PATH"
export PYTHONHOME="/mnt/usb/opt"
exec /mnt/usb/opt/bin/python3.11.bin "$@"
EOF
chmod 755 "${STAGE_DIR}/bin/python3"
ln -sf python3 "${STAGE_DIR}/bin/python"

echo "  [✓] Native Python 3 package staged successfully."
