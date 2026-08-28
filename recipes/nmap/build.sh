#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/share/nmap" "${STAGE_DIR}/nmap-sysroot/usr/lib" "${STAGE_DIR}/nmap-sysroot/lib"
TMP_STAGE="/tmp/nmap_deb_stage"
mkdir -p "${TMP_STAGE}/rootfs"

DEBIAN_MIRROR="http://ftp.de.debian.org/debian"

DEBS=(
    "pool/main/n/nmap/nmap_7.93+dfsg1-1_armel.deb"
    "pool/main/n/nmap/ncat_7.93+dfsg1-1_armel.deb"
    "pool/main/n/nmap/nmap-common_7.93+dfsg1-1_all.deb"
    "pool/main/d/dbus/libdbus-1-3_1.14.10-1~deb12u1_armel.deb"
    "pool/main/libp/libpcap/libpcap0.8_1.10.3-1_armel.deb"
    "pool/main/l/lua5.3/liblua5.3-0_5.3.6-2_armel.deb"
    "pool/main/l/lua-lpeg/lua-lpeg_1.0.2-2_armel.deb"
    "pool/main/libl/liblinear/liblinear4_2.3.0+dfsg-5_armel.deb"
    "pool/main/l/lapack/libblas3_3.11.0-2_armel.deb"
    "pool/main/g/gcc-12/libgfortran5_12.2.0-14+deb12u1_armel.deb"
    "pool/main/libs/libssh2/libssh2-1_1.10.0-3+b1_armel.deb"
    "pool/main/p/pcre3/libpcre3_8.39-15_armel.deb"
    "pool/main/p/pcre2/libpcre2-8-0_10.42-1_armel.deb"
    "pool/main/o/openssl/libssl3_3.0.20-1~deb12u2_armel.deb"
    "pool/main/z/zlib/zlib1g_1.2.13.dfsg-1_armel.deb"
    "pool/main/s/systemd/libsystemd0_252.39-1~deb12u2_armel.deb"
    "pool/main/l/lz4/liblz4-1_1.9.4-1_armel.deb"
    "pool/main/libc/libcap2/libcap2_2.66-4+deb12u3+b1_armel.deb"
    "pool/main/libg/libgcrypt20/libgcrypt20_1.10.1-3+deb12u1_armel.deb"
    "pool/main/libg/libgpg-error/libgpg-error0_1.46-1_armel.deb"
    "pool/main/libz/libzstd/libzstd1_1.5.4+dfsg2-5_armel.deb"
    "pool/main/x/xz-utils/liblzma5_5.4.1-1+deb12u1_armel.deb"
    "pool/main/g/gcc-12/libstdc++6_12.2.0-14+deb12u1_armel.deb"
    "pool/main/g/gcc-12/libgcc-s1_12.2.0-14+deb12u1_armel.deb"
    "pool/main/g/gcc-12/libatomic1_12.2.0-14+deb12u1_armel.deb"
    "pool/main/g/glibc/libc6_2.36-9+deb12u14_armel.deb"
)

echo "  [*] Fetching Debian Bookworm armel binaries..."
python3 - << PYEOF
import urllib.request, subprocess, os
from pathlib import Path

tmp_stage = Path("${TMP_STAGE}")
rootfs = tmp_stage / "rootfs"
rootfs.mkdir(parents=True, exist_ok=True)

mirror = "${DEBIAN_MIRROR}"
debs = """${DEBS[*]}""".split()

for deb_rel in debs:
    deb_name = os.path.basename(deb_rel)
    deb_file = tmp_stage / deb_name
    if not deb_file.exists():
        url = f"{mirror}/{deb_rel}"
        print(f"    Downloading {deb_name}...")
        urllib.request.urlretrieve(url, deb_file)
    
    subprocess.run(["ar", "x", str(deb_file)], cwd=tmp_stage, check=True)
    for f in tmp_stage.iterdir():
        if f.name.startswith("data.tar"):
            subprocess.run(["tar", "-xf", str(f), "-C", str(rootfs)], check=True)
            f.unlink()
        elif f.name.startswith("control.tar") or f.name == "debian-binary":
            f.unlink()
PYEOF

# Copy binaries
for b in nmap ncat; do
    if [ -f "${TMP_STAGE}/rootfs/usr/bin/${b}" ]; then
        cp -f "${TMP_STAGE}/rootfs/usr/bin/${b}" "${STAGE_DIR}/bin/${b}-real"
        chmod 755 "${STAGE_DIR}/bin/${b}-real"
    fi
done

# Copy isolated sysroot for nmap
cp -a "${TMP_STAGE}/rootfs/lib" "${STAGE_DIR}/nmap-sysroot/" 2>/dev/null || true
cp -a "${TMP_STAGE}/rootfs/usr/lib" "${STAGE_DIR}/nmap-sysroot/usr/" 2>/dev/null || true

# Copy nmap share data (scripts, signatures, services)
if [ -d "${TMP_STAGE}/rootfs/usr/share/nmap" ]; then
    cp -a "${TMP_STAGE}/rootfs/usr/share/nmap"/* "${STAGE_DIR}/share/nmap/"
fi

# Create self-contained launcher wrappers
for b in nmap ncat; do
    cat << 'EOF_WRAP' > "${STAGE_DIR}/bin/${b}"
#!/bin/sh
OPT="/mnt/usb/opt"
SYSROOT="${OPT}/nmap-sysroot"
LD_PATHS="${SYSROOT}/usr/lib/arm-linux-gnueabi:${SYSROOT}/lib/arm-linux-gnueabi:${SYSROOT}/usr/lib:${SYSROOT}/lib:${SYSROOT}/usr/lib/arm-linux-gnueabi/blas:${SYSROOT}/usr/lib/arm-linux-gnueabi/lua/5.3"
export NMAPDIR="${OPT}/share/nmap"
b="$(basename "$0")"
if [ "$b" = "nmap" ]; then
    exec ${SYSROOT}/lib/arm-linux-gnueabi/ld-linux.so.3 --library-path "${LD_PATHS}" "${OPT}/bin/${b}-real" --datadir "${OPT}/share/nmap" "$@"
else
    exec ${SYSROOT}/lib/arm-linux-gnueabi/ld-linux.so.3 --library-path "${LD_PATHS}" "${OPT}/bin/${b}-real" "$@"
fi
EOF_WRAP
    chmod 755 "${STAGE_DIR}/bin/${b}"
done

echo "  [✓] Nmap suite staged into isolated sysroot successfully."
