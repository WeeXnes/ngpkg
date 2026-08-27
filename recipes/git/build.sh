#!/usr/bin/env bash
set -euo pipefail
mkdir -p "${STAGE_DIR}/bin" "${STAGE_DIR}/libexec/git-core" "${STAGE_DIR}/share/git-core/templates" "${STAGE_DIR}/lib"

for git_dir in "${BUILDROOT_DIR}/build/git-2.43.5" "${BUILDROOT_DIR}/target/usr/bin"; do
    if [ -f "${git_dir}/git" ]; then
        cp -f "${git_dir}/git" "${STAGE_DIR}/bin/git"
        break
    fi
done

GIT_BUILD="${BUILDROOT_DIR}/build/git-2.43.5"
if [ -d "${GIT_BUILD}" ]; then
    for bin in git-remote-https git-remote-http git-http-fetch git-http-push git-receive-pack git-upload-pack; do
        if [ -f "${GIT_BUILD}/${bin}" ]; then
            cp -f "${GIT_BUILD}/${bin}" "${STAGE_DIR}/libexec/git-core/${bin}"
        fi
    done
    if [ -d "${GIT_BUILD}/templates/blt" ]; then
        cp -r "${GIT_BUILD}/templates/blt"/* "${STAGE_DIR}/share/git-core/templates/" 2>/dev/null || true
    fi
fi

# Copy required dynamic libraries
for sdir in "${BUILDROOT_DIR}/staging/usr/lib" "${BUILDROOT_DIR}/target/usr/lib" "${BUILDROOT_DIR}/target/lib"; do
    if [ -d "$sdir" ]; then
        for lib in libz.so libcrypto.so libssl.so libcurl.so libexpat.so; do
            cp -P "${sdir}/${lib}"* "${STAGE_DIR}/lib/" 2>/dev/null || true
        done
    fi
done
