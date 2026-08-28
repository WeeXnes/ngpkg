#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/etc/caddy"

CACHE_DIR="/tmp/ngpkg_sources/caddy"
mkdir -p "${CACHE_DIR}"
cd "${CACHE_DIR}"

if [ ! -f "main.go" ]; then
    cat << 'EOF_MAIN' > main.go
package main

import (
	caddycmd "github.com/caddyserver/caddy/v2/cmd"
	_ "github.com/caddyserver/caddy/v2/modules/standard"
	_ "github.com/mholt/caddy-l4"
)

func main() {
	caddycmd.Main()
}
EOF_MAIN
fi

if [ ! -f "go.mod" ]; then
    echo "  [*] Initializing Caddy module with caddy-l4..."
    go mod init caddy-custom
    go get github.com/caddyserver/caddy/v2@v2.8.4
    go get github.com/mholt/caddy-l4@master
    go mod tidy
fi

echo "  [*] Cross-compiling Caddy for ARM (capped at 2 CPU threads)..."
GOMAXPROCS=2 GOOS=linux GOARCH=arm GOARM=5 CGO_ENABLED=0 \
    go build -trimpath -ldflags="-s -w" -o "${STAGE_DIR}/bin/caddy" main.go

chmod 755 "${STAGE_DIR}/bin/caddy"

# Default minimal Caddyfile
cat << 'EOF_CONF' > "${STAGE_DIR}/etc/caddy/Caddyfile"
{
    admin off
}

:80 {
    respond "Hello from OpenNGFW Caddy!"
}
EOF_CONF

echo "  [✓] Caddy with L4 plugin staged successfully."
