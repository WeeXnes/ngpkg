#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/toolchain"

if [ -d "/tmp/gcc_stage/usr/bin" ]; then
    echo "  [*] Packaging GCC/G++ toolchain..."
    cp -a /tmp/gcc_stage/* "${STAGE_DIR}/toolchain/"
    mkdir -p "${STAGE_DIR}/toolchain/arm-linux-gnueabi"
    ln -sf ../usr/lib/arm-linux-gnueabi "${STAGE_DIR}/toolchain/arm-linux-gnueabi/lib"
    mkdir -p "${STAGE_DIR}/toolchain/usr/arm-linux-gnueabi"
    ln -sf ../lib/arm-linux-gnueabi "${STAGE_DIR}/toolchain/usr/arm-linux-gnueabi/lib"
    ln -sf /tmp "${STAGE_DIR}/toolchain/tmp"
fi

cat << 'EOF_GCC' > "${STAGE_DIR}/bin/gcc"
#!/bin/sh
TOOLCHAIN="/mnt/usb/opt/toolchain"
[ ! -L /lib/ld-linux.so.3 ] && ln -sf "${TOOLCHAIN}/lib/arm-linux-gnueabi/ld-linux.so.3" /lib/ld-linux.so.3 2>/dev/null || true
export LD_LIBRARY_PATH="${TOOLCHAIN}/lib:${TOOLCHAIN}/lib/arm-linux-gnueabi:${TOOLCHAIN}/usr/lib:${TOOLCHAIN}/usr/lib/arm-linux-gnueabi:${LD_LIBRARY_PATH:-}"
export PATH="${TOOLCHAIN}/usr/bin:${TOOLCHAIN}/bin:${PATH}"
exec ${TOOLCHAIN}/lib/arm-linux-gnueabi/ld-linux.so.3 --library-path "$LD_LIBRARY_PATH" \
    ${TOOLCHAIN}/usr/bin/arm-linux-gnueabi-gcc-12 \
    --sysroot="${TOOLCHAIN}" \
    -Wl,--disable-new-dtags \
    -Wl,-rpath="${TOOLCHAIN}/usr/lib/arm-linux-gnueabi" \
    -Wl,-rpath="${TOOLCHAIN}/lib/arm-linux-gnueabi" \
    "$@"
EOF_GCC
chmod 755 "${STAGE_DIR}/bin/gcc"

cat << 'EOF_GPP' > "${STAGE_DIR}/bin/g++"
#!/bin/sh
TOOLCHAIN="/mnt/usb/opt/toolchain"
[ ! -L /lib/ld-linux.so.3 ] && ln -sf "${TOOLCHAIN}/lib/arm-linux-gnueabi/ld-linux.so.3" /lib/ld-linux.so.3 2>/dev/null || true
export LD_LIBRARY_PATH="${TOOLCHAIN}/lib:${TOOLCHAIN}/lib/arm-linux-gnueabi:${TOOLCHAIN}/usr/lib:${TOOLCHAIN}/usr/lib/arm-linux-gnueabi:${LD_LIBRARY_PATH:-}"
export PATH="${TOOLCHAIN}/usr/bin:${TOOLCHAIN}/bin:${PATH}"
exec ${TOOLCHAIN}/lib/arm-linux-gnueabi/ld-linux.so.3 --library-path "$LD_LIBRARY_PATH" \
    ${TOOLCHAIN}/usr/bin/arm-linux-gnueabi-g++-12 \
    --sysroot="${TOOLCHAIN}" \
    -Wl,--disable-new-dtags \
    -Wl,-rpath="${TOOLCHAIN}/usr/lib/arm-linux-gnueabi" \
    -Wl,-rpath="${TOOLCHAIN}/lib/arm-linux-gnueabi" \
    "$@"
EOF_GPP
chmod 755 "${STAGE_DIR}/bin/g++"

ln -sf g++ "${STAGE_DIR}/bin/c++"

for bin in as ld ar nm strip cpp; do
    cat << EOF_BIN > "${STAGE_DIR}/bin/${bin}"
#!/bin/sh
TOOLCHAIN="/mnt/usb/opt/toolchain"
export LD_LIBRARY_PATH="\${TOOLCHAIN}/lib:\${TOOLCHAIN}/lib/arm-linux-gnueabi:\${TOOLCHAIN}/usr/lib:\${TOOLCHAIN}/usr/lib/arm-linux-gnueabi:\${LD_LIBRARY_PATH:-}"
export PATH="\${TOOLCHAIN}/usr/bin:\${TOOLCHAIN}/bin:\${PATH}"
exec \${TOOLCHAIN}/lib/arm-linux-gnueabi/ld-linux.so.3 --library-path "\$LD_LIBRARY_PATH" \${TOOLCHAIN}/usr/bin/${bin} "\$@"
EOF_BIN
    chmod 755 "${STAGE_DIR}/bin/${bin}"
done

echo "  [✓] GCC & G++ suite staged successfully."
