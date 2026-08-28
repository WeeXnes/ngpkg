#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/lib/tcc" "${STAGE_DIR}/include"

SRC_DIR="/tmp/tinycc"
if [ ! -d "${SRC_DIR}/.git" ]; then
    git clone --depth 1 https://repo.or.cz/tinycc.git "${SRC_DIR}"
fi

cd "${SRC_DIR}"
make clean 2>/dev/null || true

./configure \
    --prefix=/mnt/usb/opt \
    --cross-prefix="${CROSS_CC%-gcc}-" \
    --cpu=armv7-a \
    --crtprefix="/mnt/usb/opt/lib:/mnt/usb/opt/lib/tcc:/usr/lib:/lib" \
    --sysincludepaths="/mnt/usb/opt/lib/tcc/include:/mnt/usb/opt/include:/usr/include" \
    --libpaths="/mnt/usb/opt/lib/tcc:/mnt/usb/opt/lib:/usr/lib:/lib" \
    --extra-cflags="-mfloat-abi=soft -march=armv7-a -O2" \
    --disable-static

# Build host helper c2str.exe with native host gcc
gcc -DC2STR conftest.c -o c2str.exe
chmod +x c2str.exe

# Build libtcc1.a directly using cross-gcc
cd lib
"${CROSS_CC}" -mfloat-abi=soft -march=armv7-a -O2 -c libtcc1.c -o libtcc1.o -I..
"${CROSS_CC}" -mfloat-abi=soft -march=armv7-a -O2 -c armeabi.c -o armeabi.o -I..
"${CROSS_CC%-gcc}-ar" rcs libtcc1.a libtcc1.o armeabi.o
cd ..

make tcc libtcc.so
make install DESTDIR="${STAGE_DIR}/dest"

cp -a "${STAGE_DIR}/dest/mnt/usb/opt/"* "${STAGE_DIR}/"
rm -rf "${STAGE_DIR}/dest"

# Copy Musl C-runtime startup objects & standard headers for native compilation
SYSROOT_DIR="$(${CROSS_CC} -print-sysroot)"
mkdir -p "${STAGE_DIR}/lib/tcc/include" "${STAGE_DIR}/lib" "${STAGE_DIR}/include"

cp -f lib/libtcc1.a "${STAGE_DIR}/lib/tcc/"

# Create dummy static archives for musl-integrated libraries
for dummy in m pthread dl rt resolv crypt util xnet socket; do
    "${CROSS_CC%-gcc}-ar" cr "${STAGE_DIR}/lib/lib${dummy}.a" 2>/dev/null || true
    "${CROSS_CC%-gcc}-ar" cr "${STAGE_DIR}/lib/tcc/lib${dummy}.a" 2>/dev/null || true
done

for dir in "${STAGE_DIR}/lib" "${STAGE_DIR}/lib/tcc"; do
    cp -f "${SYSROOT_DIR}/usr/lib/crt1.o" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/crti.o" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/crtn.o" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/Scrt1.o" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/rcrt1.o" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/libc.so" "${dir}/" 2>/dev/null || true
    cp -f "${SYSROOT_DIR}/usr/lib/libc.a" "${dir}/" 2>/dev/null || true
done

cp -r "${SYSROOT_DIR}/usr/include/"* "${STAGE_DIR}/include/" 2>/dev/null || true
cp -r "${SYSROOT_DIR}/usr/include/"* "${STAGE_DIR}/lib/tcc/include/" 2>/dev/null || true

echo "  [✓] TinyCC staged successfully."
