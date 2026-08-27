# ngpkg Architecture

## System Components

1. **Client (`client/ngpkg.c`)**:
   - Compiles as a statically linked or minimal dynamic musl ELF binary (~170 KB stripped).
   - Manages package state in `/var/lib/ngpkg/db/` and `/var/lib/ngpkg/cache/`.
   - Links binaries to `$HOME/.ngpkg-bin/` (and `/root/.ngpkg-bin/`).

2. **Package Archive Format (`.ngpkg`)**:
   - Tar-gzip archive containing:
     - `metadata.json`: Package metadata and file manifest
     - `bin/`: Executables
     - `lib/`: Required shared libraries
     - `etc/`: Configuration files
     - `share/`: Data files

3. **Build Framework (`framework/ngpkg_build.py`)**:
   - Validates `recipe.json` schemas.
   - Executes `recipes/<app>/build.sh` within an isolated staging environment.
   - Strips ELF binaries using cross-toolchain utilities (`arm-buildroot-linux-musleabi-strip`).
   - Generates checksummed `index.txt` and `index.json` manifests for repository distribution.

4. **Repository Daemon (`server/pkg_server.v`)**:
   - Lightweight HTTP server serving static `.ngpkg` archives and metadata.
