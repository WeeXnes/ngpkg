#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc/init.d" "${STAGE_DIR}/etc/bareiron"

SRC_DIR="/home/weexnes/AnbergearOS/packages/sources/bareiron"
if [ -d "${SRC_DIR}" ] && [ -f "${SRC_DIR}/src/main.c" ]; then
    echo "  [*] Compiling BareIron with ${CROSS_CC}..."
    ${CROSS_CC} -O3 -s -I"${SRC_DIR}/include" "${SRC_DIR}/src"/*.c -o "${STAGE_DIR}/bin/bareiron" -lm -lpthread 2>/dev/null || \
    gcc -O3 -s -I"${SRC_DIR}/include" "${SRC_DIR}/src"/*.c -o "${STAGE_DIR}/bin/bareiron" -lm -lpthread
else
    # Fallback to cached binary
    if [ -f "/tmp/pkg_build_bareiron/bin/bareiron" ]; then
        cp -f "/tmp/pkg_build_bareiron/bin/bareiron" "${STAGE_DIR}/bin/bareiron"
    fi
fi

cat << 'EOF_CONF' > "${STAGE_DIR}/etc/bareiron/server.properties"
server-port=25565
motd=OpenNGFW BareIron Minecraft Server
max-players=5
view-distance=6
online-mode=false
EOF_CONF

cat << 'EOF_INIT' > "${STAGE_DIR}/etc/init.d/S99bareiron"
#!/bin/sh
case "$1" in
  start)
    echo "Starting BareIron Minecraft server..."
    start-stop-daemon -S -b -m -p /var/run/bareiron.pid -x /mnt/usb/opt/bin/bareiron -- -c /mnt/usb/opt/etc/bareiron/server.properties
    ;;
  stop)
    echo "Stopping BareIron Minecraft server..."
    start-stop-daemon -K -p /var/run/bareiron.pid
    ;;
  restart)
    $0 stop
    sleep 1
    $0 start
    ;;
  *)
    echo "Usage: $0 {start|stop|restart}"
    exit 1
esac
EOF_INIT
chmod 755 "${STAGE_DIR}/etc/init.d/S99bareiron"
