#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for ClyoCloud - OpenNGFW / ARMv7 musl
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" \
         "${STAGE_DIR}/share/clyocloud/app" \
         "${STAGE_DIR}/etc/systemd/system"

SRC_DIR="/tmp/ngpkg_sources/clyocloud"
mkdir -p "$(dirname "${SRC_DIR}")"

if [ ! -d "${SRC_DIR}/.git" ]; then
    echo "  [*] Cloning ClyoCloud repository..."
    git clone https://code.weexnes.dev/ClyoCloud.git "${SRC_DIR}"
else
    echo "  [*] Updating ClyoCloud repository..."
    (cd "${SRC_DIR}" && git fetch && git pull --rebase 2>/dev/null || true)
fi

echo "  [*] Installing dependencies and building Nuxt production bundle on host..."
(
    cd "${SRC_DIR}"
    npm install --no-audit --no-fund
    npm run build
)

echo "  [*] Installing ClyoCloud server artifacts into stage directory..."
cp -r "${SRC_DIR}/.output" "${STAGE_DIR}/share/clyocloud/app/.output"
cp -r "${SRC_DIR}/.usermanager" "${STAGE_DIR}/share/clyocloud/app/.usermanager"
cp -f "${SRC_DIR}/package.json" "${STAGE_DIR}/share/clyocloud/app/package.json"

# Copy essential runtime node_modules for user manager CLI (bcryptjs, commander)
mkdir -p "${STAGE_DIR}/share/clyocloud/app/node_modules"
for mod in commander bcryptjs; do
    if [ -d "${SRC_DIR}/node_modules/${mod}" ]; then
        cp -r "${SRC_DIR}/node_modules/${mod}" "${STAGE_DIR}/share/clyocloud/app/node_modules/"
    fi
done

# 1. Systemd Service Unit File
cat << 'EOF_SVC' > "${STAGE_DIR}/etc/systemd/system/clyocloud.service"
[Unit]
Description=ClyoCloud - Modern Self-Hosted Personal Cloud & Media Streaming Suite
After=network.target

[Service]
Type=simple
Environment="PATH=/mnt/usb/opt/bin:/opt/bin:/usr/bin:/bin"
Environment="STORAGE_PATH=/mnt/usb/clyocloud/data"
Environment="MOVIES_PATH=/mnt/usb/clyocloud/movies"
Environment="SHOWS_PATH=/mnt/usb/clyocloud/shows"
Environment="THUMBNAIL_PATH=/mnt/usb/clyocloud/thumbs"
Environment="PREVIEW_PATH=/mnt/usb/clyocloud/previews"
Environment="USERS_FILE_PATH=/mnt/usb/clyocloud/users.json"
Environment="TAGS_FILE_PATH=/mnt/usb/clyocloud/tags.json"
Environment="DEVICES_FILE_PATH=/mnt/usb/clyocloud/devices.json"
Environment="PORT=3000"
Environment="NITRO_PORT=3000"
Environment="NITRO_HOST=0.0.0.0"
ExecStart=/mnt/usb/opt/bin/node /mnt/usb/opt/share/clyocloud/app/.output/server/index.mjs
Restart=on-failure
RestartSec=5

[Install]
WantedBy=multi-user.target
EOF_SVC
chmod 644 "${STAGE_DIR}/etc/systemd/system/clyocloud.service"

# 2. ClyoCloud Service Controller Script
cat << 'EOF_CLI' > "${STAGE_DIR}/bin/clyocloud"
#!/usr/bin/env sh
# ==============================================================================
# ClyoCloud Service Controller for OpenNGFW
# ==============================================================================

# Locate installation prefix
if [ -d "/mnt/usb/opt/share/clyocloud/app/.output" ]; then
    APP_DIR="/mnt/usb/opt/share/clyocloud/app"
elif [ -d "/opt/share/clyocloud/app/.output" ]; then
    APP_DIR="/opt/share/clyocloud/app"
else
    SELF_DIR="$(cd "$(dirname "$0")/.." && pwd)"
    APP_DIR="${SELF_DIR}/share/clyocloud/app"
fi

ENTRY="${APP_DIR}/.output/server/index.mjs"

CLYO_BASE="/mnt/usb/clyocloud"
if [ ! -d "/mnt/usb" ]; then
    CLYO_BASE="/root/.clyo"
fi

export STORAGE_PATH="${STORAGE_PATH:-${CLYO_BASE}/data}"
export MOVIES_PATH="${MOVIES_PATH:-${CLYO_BASE}/movies}"
export SHOWS_PATH="${SHOWS_PATH:-${CLYO_BASE}/shows}"
export THUMBNAIL_PATH="${THUMBNAIL_PATH:-${CLYO_BASE}/thumbs}"
export PREVIEW_PATH="${PREVIEW_PATH:-${CLYO_BASE}/previews}"
export USERS_FILE_PATH="${USERS_FILE_PATH:-${CLYO_BASE}/users.json}"
export TAGS_FILE_PATH="${TAGS_FILE_PATH:-${CLYO_BASE}/tags.json}"
export DEVICES_FILE_PATH="${DEVICES_FILE_PATH:-${CLYO_BASE}/devices.json}"
export PORT="${PORT:-3000}"
export NITRO_PORT="${NITRO_PORT:-${PORT}}"
export NITRO_HOST="${NITRO_HOST:-0.0.0.0}"

PID_FILE="/var/run/clyocloud.pid"
LOG_DIR="${CLYO_BASE}/logs"
LOG_FILE="${LOG_DIR}/clyocloud.log"

mkdir -p "${STORAGE_PATH}" "${MOVIES_PATH}" "${SHOWS_PATH}" "${THUMBNAIL_PATH}" "${PREVIEW_PATH}" "${LOG_DIR}"

if ! command -v node >/dev/null 2>&1; then
    if [ -x "/mnt/usb/opt/bin/node" ]; then
        PATH="/mnt/usb/opt/bin:${PATH}"
    elif [ -x "/opt/bin/node" ]; then
        PATH="/opt/bin:${PATH}"
    else
        echo "[ERROR] Node.js is required to run ClyoCloud. Please install it with: pkg install nodejs" >&2
        exit 1
    fi
fi

is_running() {
    if [ -f "${PID_FILE}" ]; then
        PID="$(cat "${PID_FILE}" 2>/dev/null || true)"
        if [ -n "${PID}" ] && kill -0 "${PID}" 2>/dev/null; then
            return 0
        fi
    fi
    return 1
}

case "${1:-start}" in
    start)
        if is_running; then
            echo "[!] ClyoCloud is already running (PID: $(cat "${PID_FILE}") on port ${PORT})."
            exit 0
        fi
        echo "[*] Starting ClyoCloud on port ${PORT}..."
        echo "    Storage: ${STORAGE_PATH}"
        echo "    Logs:    ${LOG_FILE}"
        nohup node "${ENTRY}" >> "${LOG_FILE}" 2>&1 &
        echo $! > "${PID_FILE}"
        sleep 1
        if is_running; then
            echo "[✓] ClyoCloud started successfully! (PID: $(cat "${PID_FILE}"))"
            echo "    Access Web UI at: http://$(hostname -I 2>/dev/null | awk '{print $1}'):${PORT}"
        else
            echo "[ERROR] ClyoCloud failed to start. Check logs with: clyocloud logs"
            exit 1
        fi
        ;;
    stop)
        if is_running; then
            PID="$(cat "${PID_FILE}")"
            echo "[*] Stopping ClyoCloud (PID: ${PID})..."
            kill "${PID}" 2>/dev/null || true
            rm -f "${PID_FILE}"
            echo "[✓] ClyoCloud stopped."
        else
            echo "[!] ClyoCloud is not currently running."
            rm -f "${PID_FILE}"
        fi
        ;;
    restart)
        "$0" stop
        sleep 1
        "$0" start
        ;;
    status)
        if is_running; then
            PID="$(cat "${PID_FILE}")"
            echo "[✓] ClyoCloud is RUNNING (PID: ${PID})"
            echo "    Port:    ${PORT}"
            echo "    Storage: ${STORAGE_PATH}"
            echo "    Web UI:  http://$(hostname -I 2>/dev/null | awk '{print $1}'):${PORT}"
        else
            echo "[-] ClyoCloud is STOPPED"
        fi
        ;;
    logs)
        if [ -f "${LOG_FILE}" ]; then
            tail -n "${2:-50}" -f "${LOG_FILE}"
        else
            echo "No log file found at: ${LOG_FILE}"
        fi
        ;;
    user)
        shift
        NODE_PATH="${APP_DIR}/node_modules" node "${APP_DIR}/.usermanager/index.js" "$@" -p "${USERS_FILE_PATH}"
        ;;
    *)
        echo "Usage: clyocloud {start|stop|restart|status|logs|user ...}"
        echo ""
        echo "Commands:"
        echo "  start           Start ClyoCloud server in background"
        echo "  stop            Stop running ClyoCloud server"
        echo "  restart         Restart ClyoCloud server"
        echo "  status          Show service status and endpoint"
        echo "  logs            Follow server output logs"
        echo "  user add <u> <p> Add user account"
        exit 1
        ;;
esac
EOF_CLI
chmod 755 "${STAGE_DIR}/bin/clyocloud"

# 3. User Manager CLI wrapper
cat << 'EOF_UM' > "${STAGE_DIR}/bin/clyo-user-manager"
#!/usr/bin/env sh
exec clyocloud user "$@"
EOF_UM
chmod 755 "${STAGE_DIR}/bin/clyo-user-manager"

echo "[✓] ClyoCloud package stage prepared successfully!"
