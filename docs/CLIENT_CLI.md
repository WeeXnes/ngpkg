# ngpkg Client CLI Reference

## Synopsis
```bash
pkg <command> [arguments]
ngpkg <command> [arguments]
```

## Commands

- **`update`**: Synchronizes local package metadata cache with the remote repository.
- **`list`**: Formats and displays all available packages with version, size, category, and installed status dots.
- **`search <query>`**: Searches package names, categories, and descriptions matching `<query>`.
- **`info <package>`**: Displays comprehensive package metadata, payload size, installation status, and installed file list.
- **`install <package>`**: Downloads, decompresses, and installs `<package>` to `/mnt/usb/opt` and creates symlinks in `$HOME/.ngpkg-bin/`.
- **`remove <package>`**: Uninstalls `<package>`, removes files, and deletes binary symlinks.
- **`status`**: Displays storage breakdown for `/mnt/usb/opt`, number of installed packages, and active repository endpoint.
- **`self-update`**: Downloads the latest `ngpkg` binary from the repository and updates `/usr/bin/ngpkg`.

## Configuration & Environment Variables

- **`REPO_URL`**: HTTP endpoint for package repository (default: `http://192.168.1.1:8000/packages`).
- **`INSTALL_PREFIX`**: Root installation directory (default: `/mnt/usb/opt`).
- **`PKG_DB`**: Database and cache directory (default: `/var/lib/ngpkg`).
- **`PKG_CONF`**: Path to configuration file (default checks `/etc/ngpkg.conf`, `/etc/pkg.conf`).
