#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/sbin" "${STAGE_DIR}/lib" "${STAGE_DIR}/etc/ufw" "${STAGE_DIR}/etc/default"

# 1. Copy python3 runtime if built in Buildroot
for py_dir in "${BUILDROOT_DIR}/build"/python3-*; do
    if [ -d "${py_dir}" ] && [ -f "${py_dir}/python" ]; then
        cp -f "${py_dir}/python" "${STAGE_DIR}/bin/python3"
        if [ -d "${py_dir}/Lib" ]; then
            mkdir -p "${STAGE_DIR}/lib/python3.11"
            cp -r "${py_dir}/Lib"/* "${STAGE_DIR}/lib/python3.11/" 2>/dev/null || true
        fi
        if [ -d "${py_dir}/build/lib.linux-arm-3.11" ]; then
            mkdir -p "${STAGE_DIR}/lib/python3.11/lib-dynload"
            cp -r "${py_dir}/build/lib.linux-arm-3.11"/* "${STAGE_DIR}/lib/python3.11/lib-dynload/" 2>/dev/null || true
        fi
        break
    fi
done

# Copy libpython and libffi
for sdir in "${BUILDROOT_DIR}/staging/usr/lib" "${BUILDROOT_DIR}/target/usr/lib"; do
    if [ -d "$sdir" ]; then
        for lib in libpython3 libffi; do
            cp -P "${sdir}/${lib}"* "${STAGE_DIR}/lib/" 2>/dev/null || true
        done
    fi
done

# 2. Build and copy UFW
UFW_TAR="/tmp/ufw-0.36.2.tar.gz"
UFW_SRC="/tmp/ufw_test/ufw-0.36.2"
if [ ! -f "${UFW_TAR}" ]; then
    curl -fsSL "https://launchpad.net/ufw/0.36/0.36.2/+download/ufw-0.36.2.tar.gz" -o "${UFW_TAR}" 2>/dev/null || \
    wget -q -O "${UFW_TAR}" "https://launchpad.net/ufw/0.36/0.36.2/+download/ufw-0.36.2.tar.gz"
fi
if [ ! -d "${UFW_SRC}" ]; then
    mkdir -p "/tmp/ufw_test"
    tar -xzf "${UFW_TAR}" -C "/tmp/ufw_test"
fi

cd "${UFW_SRC}"
python3 ./setup.py build --build-base=/tmp/ufw_bld --build-lib=/tmp/ufw_lib 2>/dev/null || true
python3 ./setup.py install --prefix="/mnt/usb/opt" --root="${STAGE_DIR}" 2>/dev/null || true

if [ -d "${STAGE_DIR}/mnt/usb/opt" ]; then
    cp -r "${STAGE_DIR}/mnt/usb/opt"/* "${STAGE_DIR}/"
    rm -rf "${STAGE_DIR}/mnt"
fi
