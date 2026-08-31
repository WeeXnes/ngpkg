#!/usr/bin/env bash
# ==============================================================================
# PKHeX.Everywhere Build & Packaging Script for OpenNGFW
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/share/pkhex/public" "${STAGE_DIR}/etc/systemd/system"

CACHE_DIR="/tmp/ngpkg_sources/pkhex"
mkdir -p "$(dirname "${CACHE_DIR}")"

if [ ! -d "${CACHE_DIR}/.git" ]; then
    echo "  [*] Cloning PKHeX.Everywhere source repository..."
    git clone --depth 1 https://code.weexnes.dev/PKHeX.Everywhere.git "${CACHE_DIR}"
else
    echo "  [*] Updating PKHeX.Everywhere repository..."
    (cd "${CACHE_DIR}" && git pull --ff-only 2>/dev/null || true)
fi

echo "  [*] Building JavaScript assets with Vite..."
cd "${CACHE_DIR}/src/PKHeX.Web/_js"
npm install --no-audit --no-fund --quiet
npm run build

echo "  [*] Publishing Blazor WebAssembly static assets..."
cd "${CACHE_DIR}/src/PKHeX.Web"
TMP_PUB="/tmp/pkhex_pub_$$"
mkdir -p "${TMP_PUB}"
dotnet publish -c Release -o "${TMP_PUB}"

echo "  [*] Staging static WebAssembly files..."
cp -r "${TMP_PUB}/wwwroot/"* "${STAGE_DIR}/share/pkhex/public/"
rm -rf "${TMP_PUB}"

echo "  [*] Cross-compiling native PKHeX static web server..."
SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -z "${SYSROOT}" ] && [ -d "/home/weexnes/AnbergearOS/build/r6300v2/host/arm-buildroot-linux-musleabi/sysroot" ]; then
    SYSROOT="/home/weexnes/AnbergearOS/build/r6300v2/host/arm-buildroot-linux-musleabi/sysroot"
fi

REAL_CC="${CROSS_CC}"
if [ -f "/home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-gcc.br_real" ]; then
    REAL_CC="/home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-gcc.br_real"
fi

v -os linux -d no_backtrace -gc none \
  -cc "${REAL_CC}" \
  -cflags "--sysroot=${SYSROOT} -O2 -w -pie -fPIE -lm -lpthread" \
  -o "${STAGE_DIR}/bin/pkhex-server" \
  "${RECIPE_DIR}/server.v"

if [ -n "${CROSS_STRIP:-}" ]; then
    ${CROSS_STRIP} --strip-all "${STAGE_DIR}/bin/pkhex-server" 2>/dev/null || true
fi
chmod 755 "${STAGE_DIR}/bin/pkhex-server"

# Create execution wrapper script
cat << 'EOF' > "${STAGE_DIR}/bin/pkhex"
#!/bin/sh
PUBLIC_DIR="/mnt/usb/opt/share/pkhex/public"
PORT="${PKHEX_PORT:-5062}"

exec /mnt/usb/opt/bin/pkhex-server --port "${PORT}" --dir "${PUBLIC_DIR}" "$@"
EOF
chmod 755 "${STAGE_DIR}/bin/pkhex"

# Create systemd service unit file for OpenNGFW systemctl
cat << 'EOF_UNIT' > "${STAGE_DIR}/etc/systemd/system/pkhex.service"
[Unit]
Description=PKHeX.Everywhere - Pokémon Save File Editor Web UI
After=network.target

[Service]
ExecStart=/mnt/usb/opt/bin/pkhex-server --port=5062 --dir=/mnt/usb/opt/share/pkhex/public
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
EOF_UNIT
chmod 644 "${STAGE_DIR}/etc/systemd/system/pkhex.service"

echo "  [✓] PKHeX.Everywhere package staged successfully."
