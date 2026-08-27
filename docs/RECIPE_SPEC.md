# ngpkg Recipe Specification

Every recipe is defined by a `recipe.json` file in `recipes/<name>/`.

## JSON Fields

| Field | Type | Required | Description |
|---|---|---|---|
| `name` | string | **Yes** | Unique package identifier (lowercase, hyphens permitted) |
| `version` | string | **Yes** | Semantic version string (e.g. `1.0.0`) |
| `description` | string | **Yes** | Human-readable one-line description |
| `category` | string | **Yes** | One of: `utilities`, `monitoring`, `security`, `networking`, `development`, `editors`, `gaming` |
| `license` | string | No | SPDX license identifier (e.g. `MIT`, `GPL-3.0`) |
| `homepage` | string | No | Project website URL |
| `type` | string | **Yes** | Build type: `buildroot`, `binary`, `source`, `python`, `custom` |
| `buildroot_package` | string | No | Buildroot package name if different from `name` |
| `binaries` | array | No | Relative paths to binaries placed in stage directory (e.g. `["bin/nano"]`) |
| `libraries` | array | No | Shared libraries to bundle from Buildroot (e.g. `["libncurses.so"]`) |
| `config_files` | array | No | Configuration files to install into `etc/` |
| `service` | string | No | Service script path (e.g. `etc/init.d/S99service`) |
