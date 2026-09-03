#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/sbin" "${STAGE_DIR}/etc/systemd/system" "${STAGE_DIR}/share/netboot/tftp" "${STAGE_DIR}/share/netboot/www"

CACHE_DIR="/tmp/ngpkg_sources/netboot"
mkdir -p "${CACHE_DIR}"

CROSS_CC="${CROSS_CC:-/home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-gcc}"
STRIP_TOOL="${STRIP_TOOL:-/home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-strip}"

echo "  [*] Building netboot-httpd..."
"${CROSS_CC}" -O2 -mfloat-abi=soft "${SCRIPT_DIR}/netboot-httpd.c" -o "${STAGE_DIR}/bin/netboot-httpd"
if [ -x "${STRIP_TOOL}" ]; then
    "${STRIP_TOOL}" "${STAGE_DIR}/bin/netboot-httpd"
fi

echo "  [*] Building dnsmasq (ProxyDHCP + TFTP)..."
DNSMASQ_TAR="${CACHE_DIR}/dnsmasq-2.90.tar.xz"
DNSMASQ_SRC="${CACHE_DIR}/dnsmasq-2.90"
if [ ! -f "${DNSMASQ_TAR}" ]; then
    curl -fsSL "https://thekelleys.org.uk/dnsmasq/dnsmasq-2.90.tar.xz" -o "${DNSMASQ_TAR}"
fi
if [ ! -d "${DNSMASQ_SRC}" ]; then
    tar -xJf "${DNSMASQ_TAR}" -C "${CACHE_DIR}"
fi

(
    cd "${DNSMASQ_SRC}"
    make CC="${CROSS_CC}" COPTS="-DNO_DHCP6 -DNO_DNSSEC -DNO_AUTH -DNO_IPSET -DNO_LOOP" CFLAGS="-O2 -mfloat-abi=soft" -j4
    cp -f src/dnsmasq "${STAGE_DIR}/sbin/dnsmasq"
    if [ -x "${STRIP_TOOL}" ]; then
        "${STRIP_TOOL}" "${STAGE_DIR}/sbin/dnsmasq"
    fi
)

echo "  [*] Staging iPXE bootloaders..."
curl -fsSL "https://boot.ipxe.org/undionly.kpxe" -o "${STAGE_DIR}/share/netboot/tftp/undionly.kpxe"
curl -fsSL "https://boot.ipxe.org/x86_64-efi/ipxe.efi" -o "${STAGE_DIR}/share/netboot/tftp/ipxe.efi"
curl -fsSL "https://boot.ipxe.org/arm64-efi/ipxe.efi" -o "${STAGE_DIR}/share/netboot/tftp/ipxe-arm64.efi"

echo "  [*] Fetching syslinux memdisk..."
SYSLINUX_TAR="${CACHE_DIR}/syslinux-6.03.tar.gz"
if [ ! -f "${SYSLINUX_TAR}" ]; then
    curl -fsSL "https://mirrors.edge.kernel.org/pub/linux/utils/boot/syslinux/syslinux-6.03.tar.gz" -o "${SYSLINUX_TAR}"
fi
tar -xzf "${SYSLINUX_TAR}" -C "${CACHE_DIR}" syslinux-6.03/bios/memdisk/memdisk 2>/dev/null || true
if [ -f "${CACHE_DIR}/syslinux-6.03/bios/memdisk/memdisk" ]; then
    cp -f "${CACHE_DIR}/syslinux-6.03/bios/memdisk/memdisk" "${STAGE_DIR}/share/netboot/tftp/memdisk"
fi

echo "  [*] Staging CLI and systemd service..."
cp -f "${SCRIPT_DIR}/netboot" "${STAGE_DIR}/bin/netboot"
chmod 755 "${STAGE_DIR}/bin/netboot"

cp -f "${SCRIPT_DIR}/netboot.service" "${STAGE_DIR}/etc/systemd/system/netboot.service"

echo "  [✓] Netboot package staged successfully."
