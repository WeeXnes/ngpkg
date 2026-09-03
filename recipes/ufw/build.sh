#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/sbin" "${STAGE_DIR}/lib/python3.11/site-packages" "${STAGE_DIR}/etc/ufw/applications.d" "${STAGE_DIR}/etc/default" "${STAGE_DIR}/lib/ufw" "${STAGE_DIR}/share/ufw"

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
PATCHELF="/home/weexnes/AnbergearOS/build/r6300v2/host/bin/patchelf"

# 1. Stage Python 3.11 runtime from toolchain sysroot
if [ -n "${SYSROOT}" ] && [ -d "${SYSROOT}/usr/lib/python3.11" ]; then
    echo "  [*] Staging Python 3.11 runtime..."
    cp -f "${SYSROOT}/usr/bin/python3.11" "${STAGE_DIR}/bin/python3"
    ln -sf python3 "${STAGE_DIR}/bin/python"
    
    cp -P "${SYSROOT}/usr/lib"/libpython3*.so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    cp -P "${SYSROOT}/usr/lib"/libffi*.so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    
    # Copy stdlib, excluding tests and idlelib
    cp -r "${SYSROOT}/usr/lib/python3.11"/* "${STAGE_DIR}/lib/python3.11/" 2>/dev/null || true
    rm -rf "${STAGE_DIR}/lib/python3.11/test" "${STAGE_DIR}/lib/python3.11/idlelib"
    
    if [ -x "${PATCHELF}" ]; then
        "${PATCHELF}" --set-rpath "/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib" "${STAGE_DIR}/bin/python3" 2>/dev/null || true
        for so in "${STAGE_DIR}/lib"/libpython3*.so*; do
            [ -f "$so" ] && [ ! -L "$so" ] && "${PATCHELF}" --set-rpath "/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib" "$so" 2>/dev/null || true
        done
    fi
fi

# 2. Extract and stage UFW
CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
UFW_TAR="${CACHE_DIR}/ufw-0.36.2.tar.gz"
UFW_SRC="${CACHE_DIR}/ufw-0.36.2"

if [ ! -f "${UFW_TAR}" ]; then
    curl -fsSL "https://deb.debian.org/debian/pool/main/u/ufw/ufw_0.36.2.orig.tar.gz" -o "${UFW_TAR}" 2>/dev/null || \
    curl -fsSL "https://launchpad.net/ufw/0.36/0.36.2/+download/ufw-0.36.2.tar.gz" -o "${UFW_TAR}"
fi

if [ ! -d "${UFW_SRC}" ]; then
    tar -xzf "${UFW_TAR}" -C "${CACHE_DIR}"
fi

cd "${UFW_SRC}"

# Copy python module & replace template placeholders
mkdir -p "${STAGE_DIR}/lib/python3.11/site-packages/ufw"
cp -r src/*.py "${STAGE_DIR}/lib/python3.11/site-packages/ufw/"

sed -i "s%#CONFIG_PREFIX#%/etc%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"
sed -i "s%#STATE_PREFIX#%/mnt/usb/opt/lib/ufw%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"
sed -i "s%#PREFIX#%/mnt/usb/opt%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"
sed -i "s%#SHARE_DIR#%/mnt/usb/opt/share/ufw%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"
sed -i "s%#IPTABLES_DIR#%/usr/sbin%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"
sed -i "s%#VERSION#%0.36.2%g" "${STAGE_DIR}/lib/python3.11/site-packages/ufw/common.py"

# Copy configs and rules
cp conf/ufw.conf "${STAGE_DIR}/etc/ufw/" 2>/dev/null || true
cp conf/*.rules "${STAGE_DIR}/etc/ufw/" 2>/dev/null || true
cp conf/ufw.defaults "${STAGE_DIR}/etc/default/ufw" 2>/dev/null || true
cp conf/sysctl.conf "${STAGE_DIR}/etc/ufw/sysctl.conf" 2>/dev/null || true
sed -i "s%#CONFIG_PREFIX#%/etc%g" "${STAGE_DIR}/etc/default/ufw" 2>/dev/null || true
# Default to IPv4 on router
sed -i "s/IPV6=yes/IPV6=no/" "${STAGE_DIR}/etc/default/ufw" 2>/dev/null || true

# Copy init scripts and replace placeholders
cp -f staging/ufw-init "${STAGE_DIR}/lib/ufw/ufw-init" 2>/dev/null || cp -f src/ufw-init "${STAGE_DIR}/lib/ufw/ufw-init" 2>/dev/null || true
cp -f staging/ufw-init-functions "${STAGE_DIR}/lib/ufw/ufw-init-functions" 2>/dev/null || cp -f src/ufw-init-functions "${STAGE_DIR}/lib/ufw/ufw-init-functions" 2>/dev/null || true

sed -i "s%#STATE_PREFIX#%/mnt/usb/opt/lib/ufw%g" "${STAGE_DIR}/lib/ufw/ufw-init" "${STAGE_DIR}/lib/ufw/ufw-init-functions"
sed -i "s%#CONFIG_PREFIX#%/etc%g" "${STAGE_DIR}/lib/ufw/ufw-init" "${STAGE_DIR}/lib/ufw/ufw-init-functions"
sed -i "s%#PREFIX#%/mnt/usb/opt%g" "${STAGE_DIR}/lib/ufw/ufw-init" "${STAGE_DIR}/lib/ufw/ufw-init-functions"
sed -i "s%#IPTABLES_DIR#%/usr/sbin%g" "${STAGE_DIR}/lib/ufw/ufw-init" "${STAGE_DIR}/lib/ufw/ufw-init-functions"

# Stage main ufw python script (renamed to ufw-real to prevent shadowing the ufw package name)
cp -f src/ufw "${STAGE_DIR}/sbin/ufw-real"
sed -i "s%#CONFIG_PREFIX#%/etc%g" "${STAGE_DIR}/sbin/ufw-real"
sed -i "s%#STATE_PREFIX#%/mnt/usb/opt/lib/ufw%g" "${STAGE_DIR}/sbin/ufw-real"
sed -i "s%#PREFIX#%/mnt/usb/opt%g" "${STAGE_DIR}/sbin/ufw-real"
sed -i "s%#VERSION#%0.36.2%g" "${STAGE_DIR}/sbin/ufw-real"
chmod 755 "${STAGE_DIR}/sbin/ufw-real"

# Create portable wrapper for ufw in both bin/ and sbin/
cat << 'EOF_WRAPPER' > "${STAGE_DIR}/sbin/ufw"
#!/bin/sh
export PATH="/mnt/usb/opt/bin:/mnt/usb/opt/sbin:/usr/sbin:/usr/bin:/sbin:/bin:${PATH}"
export PYTHONHOME="/mnt/usb/opt"
export PYTHONPATH="/mnt/usb/opt/lib/python3.11/site-packages:/mnt/usb/opt/lib/python3.11:${PYTHONPATH:-}"
export LD_LIBRARY_PATH="/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib:${LD_LIBRARY_PATH:-}"

# Sync /etc/ufw and /etc/default/ufw from package if missing on the host
if [ ! -f /etc/default/ufw ] || [ ! -d /etc/ufw ]; then
    mkdir -p /etc/ufw /etc/default
    [ -d /mnt/usb/opt/etc/ufw ] && cp -rn /mnt/usb/opt/etc/ufw/* /etc/ufw/ 2>/dev/null || true
    [ -f /mnt/usb/opt/etc/default/ufw ] && cp -n /mnt/usb/opt/etc/default/ufw /etc/default/ufw 2>/dev/null || true
fi

# Ensure /mnt/usb/opt directories are root-owned to prevent UID warnings
if [ "$(id -u)" -eq 0 ]; then
    chown 0:0 /mnt/usb/opt /mnt/usb/opt/lib /mnt/usb/opt/sbin 2>/dev/null || true
fi

exec /mnt/usb/opt/bin/python3 /mnt/usb/opt/sbin/ufw-real "$@"
EOF_WRAPPER
chmod 755 "${STAGE_DIR}/sbin/ufw"

cp -f "${STAGE_DIR}/sbin/ufw" "${STAGE_DIR}/bin/ufw"

echo "  [✓] UFW and Python 3.11 runtime staged successfully."
