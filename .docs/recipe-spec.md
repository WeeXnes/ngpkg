# Recipe Specification

Field reference for `recipe.json`:

| Field | Type | Required | Description |
|---|---|---|---|
| `name` | string | Yes | Unique package identifier (lowercase, hyphens allowed) |
| `version` | string | Yes | Semantic version string (e.g. `1.0.0`) |
| `description` | string | Yes | Summary of the package |
| `category` | string | Yes | One of: `utilities`, `monitoring`, `security`, `networking`, `development`, `editors`, `gaming` |
| `license` | string | No | SPDX license identifier (e.g. `MIT`, `GPL-2.0`) |
| `homepage` | string | No | Upstream project URL |
| `type` | string | Yes | Build recipe type (`source`, `binary`, `custom`) |
| `binaries` | array | No | Relative paths to binaries within package root |
| `config_files` | array | No | Configuration files to install into `etc/` |
| `service` | string | No | Service init script path |
