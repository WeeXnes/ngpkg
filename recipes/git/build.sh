#!/usr/bin/env bash
# ==============================================================================
# Standalone Build Script for Git
# ==============================================================================
set -euo pipefail

mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/libexec/git-core" "${STAGE_DIR}/share/git-core/templates" "${STAGE_DIR}/lib"

CACHE_DIR="/tmp/ngpkg_sources"
mkdir -p "${CACHE_DIR}"
GIT_TAR="${CACHE_DIR}/git-2.43.5.tar.xz"
GIT_SRC="${CACHE_DIR}/git-2.43.5"

if [ ! -f "${GIT_TAR}" ]; then
    echo "  [*] Downloading Git 2.43.5 source archive..."
    curl -fsSL "https://mirrors.edge.kernel.org/pub/software/scm/git/git-2.43.5.tar.xz" -o "${GIT_TAR}" 2>/dev/null || \
    wget -q -O "${GIT_TAR}" "https://mirrors.edge.kernel.org/pub/software/scm/git/git-2.43.5.tar.xz"
fi

if [ ! -d "${GIT_SRC}" ]; then
    echo "  [*] Extracting git-2.43.5..."
    tar -xJf "${GIT_TAR}" -C "${CACHE_DIR}"
fi

cd "${GIT_SRC}"

if [ ! -f "config.mak.autogen" ]; then
    echo "  [*] Configuring git 2.43.5..."
    ac_cv_iconv_omits_bom=no \
    ac_cv_fread_reads_directories=yes \
    ac_cv_snprintf_returns_bogus=no \
    ./configure \
        --host="${CROSS_HOST:-arm-buildroot-linux-musleabi}" \
        --prefix=/mnt/usb/opt \
        --without-tcltk \
        --without-python \
        CC="${CROSS_CC}" \
        CFLAGS="-O2 -pipe" \
        > /dev/null 2>&1
fi

echo "  [*] Compiling git..."
make -j"$(nproc)" NO_TCLTK=1 NO_GETTEXT=1 NO_PYTHON=1 CC="${CROSS_CC}" > /dev/null 2>&1

cp -f git "${STAGE_DIR}/bin/git"
chmod 755 "${STAGE_DIR}/bin/git"

for b in git-remote-https git-remote-http git-http-fetch git-http-push git-receive-pack git-upload-pack; do
    if [ -f "${b}" ]; then
        cp -f "${b}" "${STAGE_DIR}/libexec/git-core/${b}"
        chmod 755 "${STAGE_DIR}/libexec/git-core/${b}"
    fi
done

if [ -d "templates/blt" ]; then
    cp -r templates/blt/* "${STAGE_DIR}/share/git-core/templates/" 2>/dev/null || true
fi

SYSROOT="$(${CROSS_CC} --print-sysroot 2>/dev/null || true)"
if [ -d "${SYSROOT}/usr/lib" ]; then
    for lib in libz libcrypto libssl libcurl libexpat; do
        cp -P "${SYSROOT}/usr/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi
