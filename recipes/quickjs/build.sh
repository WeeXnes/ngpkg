#!/usr/bin/env bash
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin"

CACHE_DIR="/tmp/ngpkg_sources/quickjs"
mkdir -p "${CACHE_DIR}"

if [ ! -d "${CACHE_DIR}/.git" ]; then
    git clone --depth 1 https://github.com/bellard/quickjs.git "${CACHE_DIR}"
fi

cd "${CACHE_DIR}"

sed -i '1i #define _GNU_SOURCE\ntypedef void (*sighandler_t)(int);\nextern char **environ;' quickjs-libc.c 2>/dev/null || true

# Host compiler for bytecode
gcc -O2 -pipe -D_GNU_SOURCE -DCONFIG_VERSION=\"2026-06-04\" \
    qjsc.c quickjs.c libregexp.c libunicode.c cutils.c quickjs-libc.c dtoa.c \
    -o qjsc_host -lm -lpthread

./qjsc_host -c -o repl.c -m repl.js

# Cross-compile for ARMv7
${CROSS_CC} -O2 -pipe -D_GNU_SOURCE -DCONFIG_VERSION=\"2026-06-04\" \
    qjs.c quickjs.c libregexp.c libunicode.c cutils.c quickjs-libc.c dtoa.c repl.c \
    -o "${STAGE_DIR}/bin/qjs" -lm -lpthread

${CROSS_CC} -O2 -pipe -D_GNU_SOURCE -DCONFIG_VERSION=\"2026-06-04\" \
    -DCONFIG_CC=\"/mnt/usb/opt/bin/gcc\" -DCONFIG_PREFIX=\"/mnt/usb/opt\" \
    qjsc.c quickjs.c libregexp.c libunicode.c cutils.c quickjs-libc.c dtoa.c \
    -o "${STAGE_DIR}/bin/qjsc" -lm -lpthread

ln -sf qjs "${STAGE_DIR}/bin/js"
ln -sf qjs "${STAGE_DIR}/bin/node"

if [ -n "${CROSS_STRIP:-}" ] && [ -x "${CROSS_STRIP:-}" ]; then
    ${CROSS_STRIP} --strip-all "${STAGE_DIR}/bin/qjs" "${STAGE_DIR}/bin/qjsc" 2>/dev/null || true
fi
chmod 755 "${STAGE_DIR}/bin/qjs" "${STAGE_DIR}/bin/qjsc"
