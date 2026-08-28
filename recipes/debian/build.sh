#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/debian" "${STAGE_DIR}/share/ngpkg/debian"

CACHE_DIR="/tmp/debian_test/cache"
mkdir -p "${CACHE_DIR}"

echo "  [*] Fetching and assembling Debian Bookworm armel base system..."
python3 - << 'PYEOF'
import urllib.request, subprocess, os, gzip, shutil, tarfile
from pathlib import Path

stage = Path(os.environ["STAGE_DIR"]) / "debian"
cache = Path("/tmp/debian_test/cache")
cache.mkdir(parents=True, exist_ok=True)
stage.mkdir(parents=True, exist_ok=True)

pkgs_needed = """adduser apt base-files base-passwd bash bsdutils coreutils dash debconf debian-archive-keyring debianutils diffutils dpkg e2fsprogs findutils gcc-12-base gpgv grep gzip hostname init-system-helpers libacl1 libapt-pkg6.0 libattr1 libaudit-common libaudit1 libblkid1 libbz2-1.0 libc-bin libc6 libcap-ng0 libcap2 libcom-err2 libcrypt1 libdb5.3 libdebconfclient0 libext2fs2 libffi8 libgcc-s1 libgcrypt20 libgmp10 libgnutls30 libgpg-error0 libhogweed6 libidn2-0 liblz4-1 liblzma5 libmd0 libmount1 libnettle8 libp11-kit0 libpam-modules libpam-modules-bin libpam-runtime libpam0g libpcre2-8-0 libseccomp2 libselinux1 libsemanage-common libsemanage2 libsepol2 libsmartcols1 libss2 libstdc++6 libsystemd0 libtasn1-6 libtinfo6 libudev1 libunistring2 libuuid1 libxxhash0 libzstd1 login logsave mawk mount ncurses-base ncurses-bin passwd perl-base sed sysvinit-utils tar tzdata usr-is-merged util-linux util-linux-extra zlib1g""".split()

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

mirror = "http://ftp.de.debian.org/debian"

dpkg_dir = stage / "var/lib/dpkg"
dpkg_info = dpkg_dir / "info"
dpkg_dir.mkdir(parents=True, exist_ok=True)
dpkg_info.mkdir(parents=True, exist_ok=True)
status_entries = []

for name in pkgs_needed:
    if name not in pkg_map:
        continue
    rel = pkg_map[name]["Filename"]
    deb_name = os.path.basename(rel)
    deb_file = cache / deb_name
    if not deb_file.exists():
        print(f"    Downloading {deb_name}...")
        urllib.request.urlretrieve(f"{mirror}/{rel}", deb_file)

    # Extract deb contents
    ext_tmp = cache / f"ext_{deb_name}"
    ext_tmp.mkdir(exist_ok=True)
    subprocess.run(["ar", "x", str(deb_file)], cwd=ext_tmp, check=True)
    
    file_list = []
    actual_pkg_name = name
    for f in ext_tmp.iterdir():
        if f.name.startswith("data.tar"):
            with tarfile.open(f) as tf:
                for member in tf.getmembers():
                    p = member.name.lstrip(".")
                    if p and not p.startswith("/."):
                        file_list.append(p if p.startswith("/") else "/" + p)
            subprocess.run(["tar", "-xf", str(f), "-C", str(stage)], check=True)
        elif f.name.startswith("control.tar"):
            ctrl_tmp = ext_tmp / "ctrl_extract"
            ctrl_tmp.mkdir(exist_ok=True)
            subprocess.run(["tar", "-xf", str(f), "-C", str(ctrl_tmp)], check=True)
            ctrl_file = ctrl_tmp / "control"
            if ctrl_file.exists():
                lines = ctrl_file.read_text(encoding="utf-8", errors="ignore").splitlines()
                new_lines = []
                for line in lines:
                    if line.startswith("Package:"):
                        actual_pkg_name = line.split(":", 1)[1].strip()
                        new_lines.append(line)
                        new_lines.append("Status: install ok installed")
                    else:
                        new_lines.append(line)
                status_entries.append("\n".join(new_lines).strip() + "\n\n")

    # Write .list file
    if file_list:
        arch_suffix = ":armel" if pkg_map[name].get("Architecture") == "armel" else ""
        list_path = dpkg_info / f"{actual_pkg_name}{arch_suffix}.list"
        with open(list_path, "w", encoding="utf-8") as lf:
            for item in file_list:
                lf.write(item + "\n")
        # Also write unadorned list if architecture suffix was added
        if arch_suffix:
            with open(dpkg_info / f"{actual_pkg_name}.list", "w", encoding="utf-8") as lf:
                for item in file_list:
                    lf.write(item + "\n")

    shutil.rmtree(ext_tmp)

with open(dpkg_dir / "status", "w", encoding="utf-8") as f:
    f.writelines(status_entries)

(dpkg_dir / "available").touch()

print("  [✓] Debian rootfs and package database created successfully.")
PYEOF

echo "  [*] Configuring Debian container environment..."
DEB_ROOT="${STAGE_DIR}/debian"

# Setup apt sources.list with official keyring verification
mkdir -p "${DEB_ROOT}/etc/apt/apt.conf.d"
cat << 'EOF_APT' > "${DEB_ROOT}/etc/apt/sources.list"
deb [signed-by=/usr/share/keyrings/debian-archive-keyring.gpg] http://deb.debian.org/debian bookworm main contrib non-free non-free-firmware
deb [signed-by=/usr/share/keyrings/debian-archive-keyring.gpg] http://security.debian.org/debian-security bookworm-security main contrib non-free non-free-firmware
deb [signed-by=/usr/share/keyrings/debian-archive-keyring.gpg] http://deb.debian.org/debian bookworm-updates main contrib non-free non-free-firmware
EOF_APT

# Embedded APT optimizations
cat << 'EOF_APT_CONF' > "${DEB_ROOT}/etc/apt/apt.conf.d/99embedded"
Acquire::PDiffs "false";
Acquire::Languages "none";
APT::Install-Recommends "false";
APT::Install-Suggests "false";
Dir::Cache::pkgcache "";
Dir::Cache::srcpkgcache "";
EOF_APT_CONF

# Preconfigure _apt user in passwd/group
grep -q "^_apt:" "${DEB_ROOT}/etc/passwd" 2>/dev/null || echo "_apt:x:104:65534::/nonexistent:/usr/sbin/nologin" >> "${DEB_ROOT}/etc/passwd"
grep -q "^nogroup:" "${DEB_ROOT}/etc/group" 2>/dev/null || echo "nogroup:x:65534:" >> "${DEB_ROOT}/etc/group"

# APT cache directory permissions
mkdir -p "${DEB_ROOT}/var/cache/apt/archives/partial" "${DEB_ROOT}/var/lib/apt/lists/partial"
chmod 777 "${DEB_ROOT}/var/cache/apt/archives/partial" "${DEB_ROOT}/var/lib/apt/lists/partial" 2>/dev/null || true

# Hostname and hosts
echo "openngfw-debian" > "${DEB_ROOT}/etc/hostname"
cat << 'EOF_HOSTS' > "${DEB_ROOT}/etc/hosts"
127.0.0.1 localhost openngfw-debian
::1 localhost ip6-localhost ip6-loopback
EOF_HOSTS

# Shell prompt and environment
cat << 'EOF_ENV' > "${DEB_ROOT}/etc/profile.d/00-container.sh"
export PS1='\[\033[1;35m\](debian-armel)\[\033[0m\] \[\033[1;32m\]\u@\h\[\033[0m\]:\[\033[1;34m\]\w\[\033[0m\]\$ '
export PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
export TERM=${TERM:-xterm-256color}
export LANG=C.UTF-8
EOF_ENV
chmod 644 "${DEB_ROOT}/etc/profile.d/00-container.sh"

# Ensure mountpoint directories exist
mkdir -p "${DEB_ROOT}/proc" "${DEB_ROOT}/sys" "${DEB_ROOT}/dev/pts" "${DEB_ROOT}/root" "${DEB_ROOT}/tmp"
chmod 1777 "${DEB_ROOT}/tmp"

# Create launcher wrapper
echo "  [*] Creating launcher wrapper (/mnt/usb/opt/bin/debian)..."
cat << 'EOF_LAUNCHER' > "${STAGE_DIR}/bin/debian"
#!/bin/sh
set -e

OPT="/mnt/usb/opt"
DEB_ROOT="${OPT}/debian"

if [ ! -d "${DEB_ROOT}" ]; then
    echo "Error: Debian rootfs directory not found at ${DEB_ROOT}" >&2
    exit 1
fi

# Helper to mount virtual filesystems if not already active
mount_if_needed() {
    target="$1"
    type="$2"
    source="$3"
    if ! grep -q "[[:space:]]${target}[[:space:]]" /proc/mounts 2>/dev/null; then
        mkdir -p "${target}"
        if [ "$type" = "bind" ]; then
            mount --bind "${source}" "${target}"
        else
            mount -t "${type}" "${type}" "${target}"
        fi
    fi
}

mount_if_needed "${DEB_ROOT}/proc" "proc" "proc"
mount_if_needed "${DEB_ROOT}/sys" "sysfs" "sysfs"
mount_if_needed "${DEB_ROOT}/dev" "bind" "/dev"
mount_if_needed "${DEB_ROOT}/dev/pts" "bind" "/dev/pts"

# Synchronize DNS
if [ -f /etc/resolv.conf ]; then
    cp -L /etc/resolv.conf "${DEB_ROOT}/etc/resolv.conf" 2>/dev/null || true
fi

# Run ldconfig inside chroot if cache missing
if [ ! -f "${DEB_ROOT}/etc/ld.so.cache" ]; then
    chroot "${DEB_ROOT}" /sbin/ldconfig 2>/dev/null || true
fi

if [ $# -eq 0 ]; then
    exec chroot "${DEB_ROOT}" /bin/bash -l
else
    exec chroot "${DEB_ROOT}" "$@"
fi
EOF_LAUNCHER
chmod 755 "${STAGE_DIR}/bin/debian"

ln -sf debian "${STAGE_DIR}/bin/deb-shell"
ln -sf debian "${STAGE_DIR}/bin/deb-run"

# Post install hook
cat << 'EOF_HOOK' > "${STAGE_DIR}/share/ngpkg/debian/install.sh"
#!/bin/sh
DEB_ROOT="/mnt/usb/opt/debian"
if [ -d "${DEB_ROOT}" ]; then
    echo "  [*] Initializing Debian container dynamic linker cache..."
    chroot "${DEB_ROOT}" /sbin/ldconfig 2>/dev/null || true
    echo "  [✓] Debian container initialized. Run 'debian' to enter."
fi
EOF_HOOK
chmod 755 "${STAGE_DIR}/share/ngpkg/debian/install.sh"

echo "  [✓] Debian package staged successfully."
