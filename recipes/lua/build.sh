#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/include" "${STAGE_DIR}/lib"

SRC_DIR="/tmp/lua-5.4.7"
if [ ! -d "${SRC_DIR}" ]; then
    curl -sSL "https://www.lua.org/ftp/lua-5.4.7.tar.gz" | tar -xz -C /tmp/
fi

cd "${SRC_DIR}"
make clean 2>/dev/null || true

make linux \
    CC="${CROSS_CC}" \
    AR="${CROSS_CC%-gcc}-ar rcu" \
    RANLIB="${CROSS_CC%-gcc}-ranlib" \
    MYCFLAGS="-mfloat-abi=soft -march=armv7-a -O2 -fPIC" \
    MYLIBS="-lm"

cp -f src/lua "${STAGE_DIR}/bin/lua"
cp -f src/luac "${STAGE_DIR}/bin/luac"
chmod 755 "${STAGE_DIR}/bin/lua" "${STAGE_DIR}/bin/luac"

cp -f src/lua.h src/luaconf.h src/lualib.h src/lauxlib.h src/lua.hpp "${STAGE_DIR}/include/"
cp -f src/liblua.a "${STAGE_DIR}/lib/" 2>/dev/null || true

echo "  [✓] Lua staged successfully."
