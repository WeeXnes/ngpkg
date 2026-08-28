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

cp -f git "${STAGE_DIR}/bin/git.real"
chmod 755 "${STAGE_DIR}/bin/git.real"

cat << 'EOF_WRAPPER' > "${STAGE_DIR}/bin/git"
#!/bin/sh
export GIT_SSL_CAINFO="${GIT_SSL_CAINFO:-/etc/ssl/certs/ca-certificates.crt}"
export GIT_EXEC_PATH="${GIT_EXEC_PATH:-/mnt/usb/opt/libexec/git-core}"
export GIT_TEMPLATE_DIR="${GIT_TEMPLATE_DIR:-/mnt/usb/opt/share/git-core/templates}"
exec /mnt/usb/opt/bin/git.real "$@"
EOF_WRAPPER
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
if [ -d "${SYSROOT}/lib" ]; then
    for lib in libz libcrypto libssl libcurl libexpat; do
        cp -P "${SYSROOT}/lib/${lib}".so* "${STAGE_DIR}/lib/" 2>/dev/null || true
    done
fi

PATCHELF="/home/weexnes/AnbergearOS/build/r6300v2/host/bin/patchelf"
if [ -x "${PATCHELF}" ]; then
    echo "  [*] Patching RPATH with patchelf..."
    "${PATCHELF}" --set-rpath "/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib" "${STAGE_DIR}/bin/git" 2>/dev/null || true
    for exe in "${STAGE_DIR}/libexec/git-core"/*; do
        [ -f "$exe" ] && "${PATCHELF}" --set-rpath "/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib" "$exe" 2>/dev/null || true
    done
    for so in "${STAGE_DIR}/lib"/*.so*; do
        if [ -f "$so" ] && [ ! -L "$so" ]; then
            "${PATCHELF}" --set-rpath "/mnt/usb/opt/lib:/mnt/usb/opt/usr/lib" "$so" 2>/dev/null || true
        fi
    done
fi
