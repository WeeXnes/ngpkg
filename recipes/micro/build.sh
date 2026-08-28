#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin"

SRC_DIR="/tmp/micro_src"
if [ ! -d "${SRC_DIR}/.git" ]; then
    git clone --depth 1 --branch v2.0.14 https://github.com/zyedidia/micro.git "${SRC_DIR}"
fi

cd "${SRC_DIR}"
export GOOS=linux
export GOARCH=arm
export GOARM=5
export CGO_ENABLED=0

go build -ldflags="-s -w -X github.com/zyedidia/micro/v2/pkg/util.Version=2.0.14" -o "${STAGE_DIR}/bin/micro" ./cmd/micro
chmod 755 "${STAGE_DIR}/bin/micro"

echo "  [✓] Micro editor staged successfully."
