#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/sbin" "${STAGE_DIR}/etc/init.d" "${STAGE_DIR}/etc/samba"
mkdir -p "${STAGE_DIR}/samba-sysroot"

CACHE_DIR="/tmp/samba_build"
mkdir -p "${CACHE_DIR}"

echo "  [*] Ensuring all Debian armel binary packages are fetched..."
python3 - << 'PYEOF'
import os, subprocess, urllib.request, gzip
from pathlib import Path

cache_dir = Path("/tmp/samba_build")
stage_sysroot = Path(os.environ["STAGE_DIR"]) / "samba-sysroot"
stage_sysroot.mkdir(parents=True, exist_ok=True)

url = "http://ftp.de.debian.org/debian/dists/bookworm/main/binary-armel/Packages.gz"
req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
with urllib.request.urlopen(req) as resp:
    data = gzip.decompress(resp.read()).decode("utf-8", errors="ignore")

pkg_map = {}
for entry in data.split("\n\n"):
    pkg = {}
    for line in entry.splitlines():
        if ":" in line and not line.startswith(" "):
            k, v = line.split(":", 1)
            pkg[k.strip()] = v.strip()
    if "Package" in pkg:
        pkg_map[pkg["Package"]] = pkg

needed_debs = """libarchive13 libxml2 samba smbclient samba-common samba-common-bin samba-libs libc6 libgcc-s1 libstdc++6 libatomic1 libacl1 libaudit1 libaudit-common libavahi-client3 libavahi-common3 libavahi-common-data libbsd0 libbz2-1.0 libcap-ng0 libcap2 libcom-err2 libcrypt1 libcups2 libdb5.3 libdbus-1-3 libexpat1 libffi8 libgcrypt20 libgmp10 libgnutls30 libgpg-error0 libgssapi-krb5-2 libhogweed6 libicu72 libidn2-0 libjansson4 libk5crypto3 libkeyutils1 libkrb5-3 libkrb5support0 libldap-2.5-0 libldb2 liblz4-1 liblzma5 libmd0 libncurses6 libncursesw6 libnettle8 libnsl2 libp11-kit0 libpam0g libpcre2-8-0 libpopt0 libreadline8 libsasl2-2 libselinux1 libsepol2 libssl3 libsystemd0 libtalloc2 libtasn1-6 libtdb1 libtevent0 libtinfo6 libtirpc-common libtirpc3 libunistring2 libunwind8 libuuid1 libwbclient0 libzstd1 zlib1g""".split()

mirror = "http://ftp.de.debian.org/debian"

for name in needed_debs:
    if name not in pkg_map:
        continue
    rel_path = pkg_map[name]["Filename"]
    deb_name = os.path.basename(rel_path)
    deb_file = cache_dir / deb_name
    if not deb_file.exists():
        print(f"    Downloading {name}...")
        urllib.request.urlretrieve(f"{mirror}/{rel_path}", deb_file)

    extract_tmp = cache_dir / f"extract_{deb_name}"
    extract_tmp.mkdir(exist_ok=True)
    subprocess.run(["ar", "x", str(deb_file)], cwd=extract_tmp, check=True)
    for f in extract_tmp.iterdir():
        if f.name.startswith("data.tar"):
            subprocess.run(["tar", "-xf", str(f), "-C", str(stage_sysroot)], check=True)
    subprocess.run(["rm", "-rf", str(extract_tmp)], check=True)

print("  [✓] Packages extracted to stage sysroot.")
PYEOF

# Clean up unwanted directories in sysroot
echo "  [*] Pruning unnecessary documentation and headers..."
rm -rf "${STAGE_DIR}/samba-sysroot/usr/share/man" \
       "${STAGE_DIR}/samba-sysroot/usr/share/doc" \
       "${STAGE_DIR}/samba-sysroot/usr/share/locale" \
       "${STAGE_DIR}/samba-sysroot/usr/include" 2>/dev/null || true

# Generate wrapper scripts for all samba binaries
SAMBA_BINS=(
    "smbd"
    "nmbd"
    "testparm"
    "smbclient"
    "smbpasswd"
    "smbstatus"
    "smbcontrol"
    "nmblookup"
    "pdbedit"
    "smbget"
)

echo "  [*] Creating binary wrappers..."
for bin_name in "${SAMBA_BINS[@]}"; do
    cat << 'EOF_WRAP' > "${STAGE_DIR}/bin/${bin_name}"
#!/bin/sh
OPT="/mnt/usb/opt"
SYSROOT="${OPT}/samba-sysroot"
LD_SO="${SYSROOT}/lib/arm-linux-gnueabi/ld-linux.so.3"

# Ensure all runtime state and configuration paths exist with correct permissions
mkdir -p /etc/samba /run/samba /var/lib/samba /var/cache/samba /var/log/samba /var/lib/samba/private /var/lock/subsys /mnt/usb/PS2SMB 2>/dev/null || true
chmod 755 /run/samba /var/lib/samba /var/cache/samba /var/log/samba 2>/dev/null || true

# Ensure compatibility symlink for ld-linux if not present
if [ ! -e /lib/ld-linux.so.3 ]; then
    ln -sf "${LD_SO}" /lib/ld-linux.so.3 2>/dev/null || true
fi

LD_PATHS="${SYSROOT}/usr/lib/arm-linux-gnueabi/samba:${SYSROOT}/usr/lib/arm-linux-gnueabi:${SYSROOT}/lib/arm-linux-gnueabi:${SYSROOT}/usr/lib:${SYSROOT}/lib"

prog="$(basename "$0")"
if [ -f "${SYSROOT}/usr/sbin/${prog}" ]; then
    exec "${LD_SO}" --library-path "${LD_PATHS}" "${SYSROOT}/usr/sbin/${prog}" "$@"
else
    exec "${LD_SO}" --library-path "${LD_PATHS}" "${SYSROOT}/usr/bin/${prog}" "$@"
fi
EOF_WRAP
    chmod 755 "${STAGE_DIR}/bin/${bin_name}"

    if [[ "${bin_name}" =~ ^(smbd|nmbd)$ ]]; then
        ln -sf "../bin/${bin_name}" "${STAGE_DIR}/sbin/${bin_name}"
    fi
done

# Create PS2 configuration template
echo "  [*] Staging PS2-compatible Samba configuration template..."
cat << 'EOF_PS2' > "${STAGE_DIR}/etc/samba/smb.conf.ps2"
[global]
workgroup = WORKGROUP
server string = OpenNGFW PS2 SMB Server
netbios name = OPENNGFW
security = user
map to guest = Bad User
name resolve order = bcast host

server min protocol = LANMAN1
client min protocol = NT1
client max protocol = NT1

ntlm auth = yes
lanman auth = yes
client lanman auth = yes
client plaintext auth = yes
log level = 3

# Directory overrides
lock directory = /run/samba
state directory = /var/lib/samba
cache directory = /var/cache/samba
pid directory = /run/samba
private dir = /var/lib/samba/private

[PS2SMB]
path = /mnt/usb/PS2SMB
browseable = yes
read only = no
guest ok = yes
force user = root
EOF_PS2

cp "${STAGE_DIR}/etc/samba/smb.conf.ps2" "${STAGE_DIR}/etc/samba/smb.conf"

# Create SysV init script for OpenNGFW
echo "  [*] Creating SysV Init service script S91smb..."
cat << 'EOF_INIT' > "${STAGE_DIR}/etc/init.d/S91smb"
#!/bin/sh
# OpenNGFW Samba Service Init Script (smbd + nmbd)

DAEMON="/mnt/usb/opt/bin/smbd"
NMBD="/mnt/usb/opt/bin/nmbd"
CONF="/etc/samba/smb.conf"

init_env() {
    mkdir -p /etc/samba /run/samba /var/lib/samba /var/cache/samba /var/log/samba /var/lib/samba/private /mnt/usb/PS2SMB 2>/dev/null || true
    chmod 755 /run/samba /var/lib/samba /var/cache/samba /var/log/samba 2>/dev/null || true
    if [ ! -f "${CONF}" ]; then
        if [ -f /mnt/usb/opt/etc/samba/smb.conf.ps2 ]; then
            cp /mnt/usb/opt/etc/samba/smb.conf.ps2 "${CONF}"
        fi
    fi
}

start() {
    init_env
    printf "Starting Samba smbd: "
    "${DAEMON}" -D
    [ $? -eq 0 ] && echo "OK" || echo "FAIL"

    printf "Starting Samba nmbd: "
    "${NMBD}" -D
    [ $? -eq 0 ] && echo "OK" || echo "FAIL"
}

stop() {
    printf "Stopping Samba smbd: "
    killall smbd 2>/dev/null || true
    echo "OK"

    printf "Stopping Samba nmbd: "
    killall nmbd 2>/dev/null || true
    echo "OK"
}

status() {
    if pidof smbd >/dev/null; then
        echo "smbd is running (pid $(pidof smbd))"
    else
        echo "smbd is stopped"
    fi
    if pidof nmbd >/dev/null; then
        echo "nmbd is running (pid $(pidof nmbd))"
    else
        echo "nmbd is stopped"
    fi
}

case "$1" in
    start)
        start
        ;;
    stop)
        stop
        ;;
    restart)
        stop
        sleep 1
        start
        ;;
    status)
        status
        ;;
    *)
        echo "Usage: $0 {start|stop|restart|status}"
        exit 1
        ;;
esac
EOF_INIT
chmod 755 "${STAGE_DIR}/etc/init.d/S91smb"

echo "  [✓] Samba recipe staged successfully."
