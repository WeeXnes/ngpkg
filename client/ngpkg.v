// ==============================================================================
// ngpkg: Next-Generation Serverless Package Manager for OpenNGFW
// Serverless Git-Repository Architecture: index.json, src/, bin/
// Written in V for performance, safety, and zero-dependency standalone execution
// ==============================================================================

module main

import os
import strings

const version = '2.0.0'
const default_repo_name = 'core'
const default_repo_url = 'https://code.weexnes.dev/NGPKG-PKG-REPO.git'
const default_install_prefix = '/mnt/usb/opt'
const default_db_dir = '/var/lib/ngpkg'

struct Repo {
mut:
	name          string
	url           string
	raw_url       string
	package_count int
}

struct Config {
mut:
	repos   []Repo
	prefix  string
	db_dir  string
}

struct Package {
mut:
	name        string
	version     string
	arch        string
	size        string
	size_bytes  u64
	description string
	category    string
	bin         string
	src         string
	pkg_type    string
	repo_name   string
}

// ==============================================================================
// ANSI Styling & Terminal Helpers
// ==============================================================================

const c_reset  = '\x1b[0m'
const c_bold   = '\x1b[1m'
const c_dim    = '\x1b[2m'
const c_cyan   = '\x1b[1;36m'
const c_blue   = '\x1b[1;34m'
const c_green  = '\x1b[1;32m'
const c_yellow = '\x1b[1;33m'
const c_red    = '\x1b[1;31m'
const c_purple = '\x1b[1;35m'
const c_gray   = '\x1b[38;5;244m'

fn pad_right(s string, width int) string {
	if s.len >= width {
		return s
	}
	return s + strings.repeat(` `, width - s.len)
}

fn format_bytes(bytes u64) string {
	if bytes >= 1024 * 1024 {
		mb := f64(bytes) / (1024.0 * 1024.0)
		return '${mb:.1f}MB'
	} else if bytes >= 1024 {
		kb := f64(bytes) / 1024.0
		return '${kb:.0f}KB'
	}
	return '${bytes}B'
}

fn json_escape(s string) string {
	mut res := strings.new_builder(s.len + 8)
	for i := 0; i < s.len; i++ {
		ch := s[i]
		match ch {
			`"`  { res.write_string('\\"') }
			`\\` { res.write_string('\\\\') }
			`\n` { res.write_string('\\n') }
			`\r` { res.write_string('\\r') }
			`\t` { res.write_string('\\t') }
			else { res.write_u8(ch) }
		}
	}
	return res.str()
}

fn parse_json_value(json_str string, key string) string {
	search_key := '"${key}"'
	if !json_str.contains(search_key) {
		return ''
	}
	after_key := json_str.all_after(search_key).trim_space()
	if !after_key.starts_with(':') {
		return ''
	}
	val_part := after_key.all_after(':').trim_space()
	if val_part.starts_with('"') {
		return val_part.all_after('"').all_before('"')
	}
	mut val := val_part.all_before(',').all_before('}').all_before('\n').all_before(']').trim_space()
	return val
}

fn print_banner() {
	println('${c_cyan}╭──────────────────────────────────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_bold}OpenNGFW Serverless Package Manager${c_reset} (${c_green}ngpkg v${version}${c_reset})      ${c_cyan}│${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Serverless Git Architecture • Prefix: /mnt/usb/opt${c_reset}          ${c_cyan}│${c_reset}')
	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯${c_reset}')
}

// ==============================================================================
// Serverless Git URL Normalization
// ==============================================================================

fn normalize_repo_url(url string) string {
	mut u := url.trim_space().trim_right('/')
	if u.ends_with('.git') {
		u = u.all_before_last('.git')
	}

	// GitHub repository URL -> raw content base URL
	if u.starts_with('https://github.com/') || u.starts_with('http://github.com/') {
		after_gh := if u.starts_with('https://github.com/') {
			u.all_after('https://github.com/')
		} else {
			u.all_after('http://github.com/')
		}
		parts := after_gh.split('/')
		if parts.len >= 2 {
			user := parts[0]
			repo := parts[1]
			mut branch := 'main'
			if parts.len >= 4 && parts[2] == 'tree' {
				branch = parts[3]
			}
			return 'https://raw.githubusercontent.com/${user}/${repo}/${branch}'
		}
	} else if u.starts_with('https://gitlab.com/') || u.starts_with('http://gitlab.com/') {
		after_gl := if u.starts_with('https://gitlab.com/') {
			u.all_after('https://gitlab.com/')
		} else {
			u.all_after('http://gitlab.com/')
		}
		parts := after_gl.split('/')
		if parts.len >= 2 {
			user := parts[0]
			repo := parts[1]
			return 'https://gitlab.com/${user}/${repo}/-/raw/main'
		}
	} else if u.starts_with('https://codeberg.org/') || u.starts_with('http://codeberg.org/') {
		after_cb := if u.starts_with('https://codeberg.org/') {
			u.all_after('https://codeberg.org/')
		} else {
			u.all_after('http://codeberg.org/')
		}
		parts := after_cb.split('/')
		if parts.len >= 2 {
			user := parts[0]
			repo := parts[1]
			return 'https://codeberg.org/${user}/${repo}/raw/branch/main'
		}
	}

	return u
}

fn get_repo_file_urls(repo Repo, rel_path string) []string {
	mut urls := []string{}
	clean_rel := rel_path.trim_left('/')

	// OneDev: https://code.weexnes.dev/<project>.git
	if repo.url.contains('code.weexnes.dev') {
		mut base := repo.url.trim_right('/')
		if base.ends_with('.git') {
			base = base.all_before_last('.git')
		}
		urls << '${base}/~raw?revision=main&file=${clean_rel}'
		urls << '${base}/~raw?revision=master&file=${clean_rel}'
		return urls
	}

	// GitHub: https://github.com/<owner>/<repo>
	if repo.url.starts_with('https://github.com/') || repo.url.starts_with('http://github.com/') {
		after := if repo.url.starts_with('https://github.com/') {
			repo.url.all_after('https://github.com/')
		} else {
			repo.url.all_after('http://github.com/')
		}
		mut clean := after.trim_right('/')
		if clean.ends_with('.git') { clean = clean.all_before_last('.git') }
		parts := clean.split('/')
		if parts.len >= 2 {
			user := parts[0]
			rname := parts[1]
			urls << 'https://raw.githubusercontent.com/${user}/${rname}/main/${clean_rel}'
			urls << 'https://raw.githubusercontent.com/${user}/${rname}/master/${clean_rel}'
			return urls
		}
	}

	// GitLab: https://gitlab.com/<owner>/<repo>
	if repo.url.starts_with('https://gitlab.com/') || repo.url.starts_with('http://gitlab.com/') {
		mut clean := repo.url.trim_right('/')
		if clean.ends_with('.git') { clean = clean.all_before_last('.git') }
		urls << '${clean}/-/raw/main/${clean_rel}'
		urls << '${clean}/-/raw/master/${clean_rel}'
		return urls
	}

	// Codeberg / Gitea:
	if repo.url.starts_with('https://codeberg.org/') || repo.url.starts_with('http://codeberg.org/') {
		mut clean := repo.url.trim_right('/')
		if clean.ends_with('.git') { clean = clean.all_before_last('.git') }
		urls << '${clean}/raw/branch/main/${clean_rel}'
		urls << '${clean}/raw/branch/master/${clean_rel}'
		return urls
	}

	// Direct Raw or generic static HTTP(S) URL
	base_raw := repo.raw_url.trim_right('/')
	urls << '${base_raw}/${clean_rel}'
	if base_raw.contains('/main') {
		urls << base_raw.replace('/main', '/master') + '/${clean_rel}'
	}
	return urls
}

// ==============================================================================
// Configuration & Repository Management
// ==============================================================================

fn get_repos_conf_paths(prefix string) []string {
	return [
		'${prefix}/etc/ngpkg/repos.conf',
		'/etc/ngpkg/repos.conf',
		'/etc/ngpkg.repos',
		'${prefix}/etc/ngpkg.conf',
		'/etc/ngpkg.conf',
		'/etc/pkg.conf',
	]
}

fn load_config() Config {
	mut prefix := os.getenv('INSTALL_PREFIX')
	mut db_dir := os.getenv('PKG_DB')

	if prefix == '' {
		prefix = default_install_prefix
	}
	if db_dir == '' {
		db_dir = default_db_dir
	}

	mut repos := []Repo{}
	conf_paths := get_repos_conf_paths(prefix)

	for p in conf_paths {
		if p != '' && os.exists(p) {
			lines := os.read_lines(p) or { []string{} }
			for line in lines {
				trimmed := line.trim_space()
				if trimmed.starts_with('#') || trimmed == '' {
					continue
				}
				if trimmed.starts_with('REPO_URL=') {
					u := trimmed.all_after('REPO_URL=').trim(" \"\x27")
					if u != '' {
						raw := normalize_repo_url(u)
						repos << Repo{ name: 'default', url: u, raw_url: raw, package_count: 0 }
					}
				} else if trimmed.contains(' ') || trimmed.contains('\t') {
					parts := trimmed.fields()
					if parts.len >= 2 {
						r_name := parts[0].trim_space()
						r_url := parts[1].trim_space()
						raw := normalize_repo_url(r_url)
						// avoid duplicate repo names
						mut exists := false
						for r in repos {
							if r.name == r_name {
								exists = true
								break
							}
						}
						if !exists {
							repos << Repo{ name: r_name, url: r_url, raw_url: raw, package_count: 0 }
						}
					}
				}
			}
			if repos.len > 0 {
				break
			}
		}
	}

	// Environment variable override
	env_repo := os.getenv('REPO_URL')
	if env_repo != '' {
		raw := normalize_repo_url(env_repo)
		repos = [Repo{ name: 'env', url: env_repo, raw_url: raw, package_count: 0 }]
	}

	// Fallback to official default repository
	if repos.len == 0 {
		repos << Repo{
			name: default_repo_name
			url: default_repo_url
			raw_url: default_repo_url
			package_count: 0
		}
	}

	return Config{
		repos: repos
		prefix: prefix.trim_right('/')
		db_dir: db_dir.trim_right('/')
	}
}

fn save_repos_config(cfg Config) bool {
	mut content := strings.new_builder(256)
	content.write_string('# OpenNGFW Serverless Package Repositories\n')
	content.write_string('# Format: <name> <git-url-or-raw-url>\n\n')
	for r in cfg.repos {
		content.write_string('${r.name} ${r.url}\n')
	}

	target_paths := [
		'${cfg.prefix}/etc/ngpkg/repos.conf',
		'/etc/ngpkg/repos.conf',
	]

	mut ok := false
	for p in target_paths {
		dir := os.dir(p)
		os.mkdir_all(dir) or {}
		os.write_file(p, content.str()) or { continue }
		ok = true
	}
	return ok
}

// ==============================================================================
// Database & Installation State
// ==============================================================================

fn get_installed_db_dirs(cfg Config) []string {
	return [
		'${cfg.prefix}/var/lib/ngpkg/installed',
		'${cfg.db_dir}/installed',
		'/var/lib/ngpkg/installed',
	]
}

fn is_installed(cfg Config, pkg_name string) bool {
	for d in get_installed_db_dirs(cfg) {
		if os.exists('${d}/${pkg_name}.json') ||
		   os.exists('${d}/${pkg_name}.list') ||
		   os.exists('${d}/${pkg_name}.meta') {
			return true
		}
	}
	// Fallback check in prefix bin
	if os.exists('${cfg.prefix}/bin/${pkg_name}') || os.exists('${cfg.prefix}/sbin/${pkg_name}') {
		return true
	}
	return false
}

fn get_installed_packages(cfg Config) []string {
	mut pkgs := []string{}
	dirs := get_installed_db_dirs(cfg)

	for d in dirs {
		if os.is_dir(d) {
			files := os.ls(d) or { []string{} }
			for f in files {
				if f.ends_with('.json') {
					name := f.trim_string_right('.json')
					if !pkgs.contains(name) { pkgs << name }
				} else if f.ends_with('.list') {
					name := f.trim_string_right('.list')
					if !pkgs.contains(name) { pkgs << name }
				}
			}
		}
	}
	return pkgs
}

fn get_installed_meta(cfg Config, pkg_name string) ?Package {
	for d in get_installed_db_dirs(cfg) {
		json_file := '${d}/${pkg_name}.json'
		if os.exists(json_file) {
			content := os.read_file(json_file) or { '' }
			if content != '' {
				name := parse_json_value(content, 'name')
				ver := parse_json_value(content, 'version')
				desc := parse_json_value(content, 'description')
				cat := parse_json_value(content, 'category')
				repo := parse_json_value(content, 'repo')
				return Package{
					name: if name != '' { name } else { pkg_name }
					version: if ver != '' { ver } else { 'installed' }
					arch: 'armv7l'
					size: 'installed'
					description: if desc != '' { desc } else { 'Installed application' }
					category: if cat != '' { cat } else { 'utilities' }
					repo_name: if repo != '' { repo } else { 'local' }
					pkg_type: 'installed'
				}
			}
		}
	}

	// Legacy .meta file fallback
	for d in get_installed_db_dirs(cfg) {
		meta_file := '${d}/${pkg_name}.meta'
		if os.exists(meta_file) {
			lines := os.read_lines(meta_file) or { []string{} }
			mut name := pkg_name
			mut ver := 'unknown'
			mut desc := 'Installed package'
			mut cat := 'custom'
			for line in lines {
				trimmed := line.trim_space()
				if trimmed.starts_with('NAME=') {
					name = trimmed.all_after('NAME=').trim_space()
				} else if trimmed.starts_with('VERSION=') {
					ver = trimmed.all_after('VERSION=').trim_space()
				} else if trimmed.starts_with('DESCRIPTION=') {
					desc = trimmed.all_after('DESCRIPTION=').trim_space()
				} else if trimmed.starts_with('CATEGORY=') {
					cat = trimmed.all_after('CATEGORY=').trim_space()
				}
			}
			return Package{
				name: name
				version: ver
				arch: 'armv7l'
				size: 'installed'
				description: desc
				category: cat
				repo_name: 'local'
				pkg_type: 'installed'
			}
		}
	}

	return none
}

// ==============================================================================
// Serverless Index Parser & Package Resolution
// ==============================================================================

fn parse_index_json(content string, repo_name string) []Package {
	mut pkgs := []Package{}
	if !content.contains('"packages"') {
		return pkgs
	}
	after_pkgs := content.all_after('"packages"').trim_space()
	if !after_pkgs.starts_with(':') {
		return pkgs
	}
	array_part := after_pkgs.all_after(':').trim_space()
	if !array_part.starts_with('[') {
		return pkgs
	}
	raw_array := array_part.all_after('[').all_before_last(']')

	mut in_obj := false
	mut brace_depth := 0
	mut start_idx := 0

	for i := 0; i < raw_array.len; i++ {
		ch := raw_array[i]
		if ch == `{` {
			if brace_depth == 0 {
				start_idx = i
				in_obj = true
			}
			brace_depth++
		} else if ch == `}` {
			brace_depth--
			if brace_depth == 0 && in_obj {
				in_obj = false
				obj_str := raw_array[start_idx..i+1]
				name := parse_json_value(obj_str, 'name')
				if name != '' {
					ver := parse_json_value(obj_str, 'version')
					arch := parse_json_value(obj_str, 'arch')
					desc := parse_json_value(obj_str, 'description')
					cat := parse_json_value(obj_str, 'category')
					sz := parse_json_value(obj_str, 'size')
					bin := parse_json_value(obj_str, 'bin')
					src := parse_json_value(obj_str, 'src')
					ptype := parse_json_value(obj_str, 'type')

					mut final_type := ptype
					if final_type == '' {
						if bin.ends_with('.tar.gz') || bin.ends_with('.tgz') || bin.ends_with('.ngpkg') || bin.ends_with('.tar') || bin.ends_with('.tar.xz') {
							final_type = 'archive'
						} else {
							final_type = 'binary'
						}
					}

					pkgs << Package{
						name: name
						version: if ver != '' { ver } else { '1.0.0' }
						arch: if arch != '' { arch } else { 'armv7l' }
						size: if sz != '' { sz } else { 'unknown' }
						description: if desc != '' { desc } else { 'Package ${name}' }
						category: if cat != '' { cat } else { 'utilities' }
						bin: bin
						src: src
						pkg_type: final_type
						repo_name: repo_name
					}
				}
			}
		}
	}
	return pkgs
}

fn fetch_all_repo_packages(cfg Config) []Package {
	mut all_pkgs := []Package{}
	mut seen := map[string]bool{}

	// Read cached index from all repos
	for repo in cfg.repos {
		repo_cache_candidates := [
			'${cfg.prefix}/var/lib/ngpkg/repos/${repo.name}/index.json',
			'${cfg.db_dir}/repos/${repo.name}/index.json',
			'/var/lib/ngpkg/repos/${repo.name}/index.json',
		]
		for cand in repo_cache_candidates {
			if os.exists(cand) {
				content := os.read_file(cand) or { '' }
				if content != '' {
					pkgs := parse_index_json(content, repo.name)
					for p in pkgs {
						if !seen[p.name] {
							seen[p.name] = true
							all_pkgs << p
						}
					}
					break
				}
			}
		}
	}

	// Also check consolidated cache index.json
	consolidated_candidates := [
		'${cfg.prefix}/var/lib/ngpkg/cache/index.json',
		'${cfg.db_dir}/cache/index.json',
		'/var/lib/ngpkg/cache/index.json',
	]
	for cand in consolidated_candidates {
		if os.exists(cand) {
			content := os.read_file(cand) or { '' }
			if content != '' {
				pkgs := parse_index_json(content, 'core')
				for p in pkgs {
					if !seen[p.name] {
						seen[p.name] = true
						all_pkgs << p
					}
				}
				break
			}
		}
	}

	return all_pkgs
}

// ==============================================================================
// Commands: Update
// ==============================================================================

fn download_url(url string, dest string) bool {
	dir := os.dir(dest)
	os.mkdir_all(dir) or {}
	cmd := 'curl -fsSL --connect-timeout 10 -m 60 --cacert /etc/ssl/certs/ca-certificates.crt -o "${dest}" "${url}" 2>/dev/null || curl -fsSL -k --connect-timeout 10 -m 60 -o "${dest}" "${url}" 2>/dev/null || wget -q -T 15 -O "${dest}" "${url}" 2>/dev/null'
	res := os.execute(cmd)
	return res.exit_code == 0 && os.exists(dest) && os.file_size(dest) > 0
}

fn cmd_update(cfg Config) int {
	println('${c_cyan}◈${c_reset} Synchronizing serverless package repositories...\n')

	mut total_available := 0
	mut success_count := 0

	for repo in cfg.repos {
		print('  ${c_blue}•${c_reset} Fetching ${c_bold}${repo.name}${c_reset} (${c_gray}${repo.url}${c_reset})... ')

		target_file := '${cfg.db_dir}/repos/${repo.name}/index.json'
		os.mkdir_all(os.dir(target_file)) or {}

		urls_to_try := get_repo_file_urls(repo, 'index.json')

		mut fetched := false
		for u in urls_to_try {
			if download_url(u, target_file) {
				fetched = true
				break
			}
		}

		if fetched {
			content := os.read_file(target_file) or { '' }
			pkgs := parse_index_json(content, repo.name)
			println('${c_green}✓ OK${c_reset} (${c_bold}${pkgs.len}${c_reset} packages)')
			total_available += pkgs.len
			success_count++

			// Persist copy to USB prefix
			if os.is_dir(cfg.prefix) {
				usb_dest := '${cfg.prefix}/var/lib/ngpkg/repos/${repo.name}/index.json'
				os.mkdir_all(os.dir(usb_dest)) or {}
				os.cp(target_file, usb_dest) or {}
			}
		} else {
			println('${c_red}✗ Failed${c_reset}')
			eprintln('    ${c_yellow}Could not fetch index.json from ${repo.raw_url}${c_reset}')
		}
	}

	// Consolidate into unified cache
	all_pkgs := fetch_all_repo_packages(cfg)
	os.mkdir_all('${cfg.db_dir}/cache') or {}
	mut consolidated_json := strings.new_builder(2048)
	consolidated_json.write_string('{\n  "version": "2.0",\n  "packages": [\n')
	for idx, p in all_pkgs {
		comma := if idx < all_pkgs.len - 1 { ',' } else { '' }
		consolidated_json.write_string('    {"name":"${p.name}","version":"${p.version}","size":"${p.size}","description":"${json_escape(p.description)}","category":"${p.category}","bin":"${p.bin}","src":"${p.src}","type":"${p.pkg_type}","repo":"${p.repo_name}"}${comma}\n')
	}
	consolidated_json.write_string('  ]\n}\n')
	os.write_file('${cfg.db_dir}/cache/index.json', consolidated_json.str()) or {}
	if os.is_dir(cfg.prefix) {
		os.mkdir_all('${cfg.prefix}/var/lib/ngpkg/cache') or {}
		os.write_file('${cfg.prefix}/var/lib/ngpkg/cache/index.json', consolidated_json.str()) or {}
	}

	println('\n${c_green}✓ Update complete:${c_reset} ${c_bold}${total_available}${c_reset} packages across ${c_bold}${success_count}/${cfg.repos.len}${c_reset} repositories.\n')
	return if success_count > 0 { 0 } else { 1 }
}

// ==============================================================================
// Commands: List & Search
// ==============================================================================

fn cmd_list(cfg Config, json_mode bool) int {
	pkgs := fetch_all_repo_packages(cfg)
	if pkgs.len == 0 && !json_mode {
		println('${c_yellow}[! No index found]${c_reset} Updating repository index first...\n')
		cmd_update(cfg)
	}

	fresh_pkgs := fetch_all_repo_packages(cfg)
	installed := get_installed_packages(cfg)

	if json_mode {
		mut items := []string{}
		for p in fresh_pkgs {
			is_inst := is_installed(cfg, p.name)
			items << '{"name":"${p.name}","version":"${p.version}","size":"${p.size}","description":"${json_escape(p.description)}","category":"${p.category}","repo":"${p.repo_name}","installed":${is_inst},"bin":"${p.bin}","src":"${p.src}"}'
		}
		// Also append local installed packages not found in repos
		for inst_name in installed {
			mut in_repo := false
			for p in fresh_pkgs {
				if p.name == inst_name { in_repo = true; break }
			}
			if !in_repo {
				m := get_installed_meta(cfg, inst_name) or {
					Package{ name: inst_name, version: 'custom', description: 'Local package', category: 'custom' }
				}
				items << '{"name":"${m.name}","version":"${m.version}","size":"${m.size}","description":"${json_escape(m.description)}","category":"${m.category}","repo":"local","installed":true,"bin":"","src":""}'
			}
		}
		println('[' + items.join(',') + ']')
		return 0
	}

	println('${c_bold}OpenNGFW Serverless Package Repositories:${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')
	h_name := pad_right('NAME', 14)
	h_ver := pad_right('VERSION', 9)
	h_repo := pad_right('REPO', 10)
	h_size := pad_right('SIZE', 8)
	h_status := pad_right('STATUS', 14)
	println('  ${c_bold}${h_name} ${h_ver} ${h_repo} ${h_size} ${h_status} DESCRIPTION${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')

	mut inst_count := 0
	mut listed_installed := []string{}

	for p in fresh_pkgs {
		is_inst := is_installed(cfg, p.name)
		if is_inst {
			inst_count++
			listed_installed << p.name
		}
		status_badge := if is_inst {
			'${c_green}● installed${c_reset}'
		} else {
			'${c_cyan}○ available${c_reset}'
		}
		name_fmt := if is_inst { '${c_green}${c_bold}${pad_right(p.name, 14)}${c_reset}' } else { '${c_bold}${pad_right(p.name, 14)}${c_reset}' }
		ver_fmt := '${c_yellow}${pad_right(p.version, 9)}${c_reset}'
		repo_fmt := '${c_purple}${pad_right(p.repo_name, 10)}${c_reset}'
		size_fmt := '${c_gray}${pad_right(p.size, 8)}${c_reset}'
		status_fmt := pad_right(status_badge, 23)

		println('  ${name_fmt} ${ver_fmt} ${repo_fmt} ${size_fmt} ${status_fmt} ${p.description}')
	}

	// Custom local packages
	for inst_name in installed {
		if !listed_installed.contains(inst_name) {
			inst_count++
			m := get_installed_meta(cfg, inst_name) or {
				Package{ name: inst_name, version: 'custom', description: 'Local package', category: 'custom' }
			}
			status_badge := '${c_green}● installed (local)${c_reset}'
			name_fmt := '${c_green}${c_bold}${pad_right(m.name, 14)}${c_reset}'
			ver_fmt := '${c_yellow}${pad_right(m.version, 9)}${c_reset}'
			repo_fmt := '${c_gray}${pad_right("local", 10)}${c_reset}'
			size_fmt := '${c_gray}${pad_right("installed", 8)}${c_reset}'
			status_fmt := pad_right(status_badge, 31)
			println('  ${name_fmt} ${ver_fmt} ${repo_fmt} ${size_fmt} ${status_fmt} ${m.description}')
		}
	}

	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')
	println('  ${c_gray}Total:${c_reset} ${fresh_pkgs.len} repository packages (${c_green}${inst_count} installed${c_reset}, ${c_cyan}${fresh_pkgs.len - listed_installed.len} available${c_reset})\n')
	return 0
}

fn cmd_search(cfg Config, query string) int {
	pkgs := fetch_all_repo_packages(cfg)
	if pkgs.len == 0 {
		cmd_update(cfg)
	}
	fresh_pkgs := fetch_all_repo_packages(cfg)
	q := query.to_lower()

	println('${c_cyan}◈${c_reset} Search results for "${c_bold}${query}${c_reset}":')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')

	mut matches := 0
	for p in fresh_pkgs {
		if p.name.to_lower().contains(q) || p.description.to_lower().contains(q) || p.category.to_lower().contains(q) || p.repo_name.to_lower().contains(q) {
			matches++
			is_inst := is_installed(cfg, p.name)
			status_badge := if is_inst { '${c_green}[installed]${c_reset}' } else { '${c_cyan}[available]${c_reset}' }
			name_fmt := pad_right(p.name, 14)
			ver_fmt := pad_right(p.version, 8)
			repo_fmt := pad_right(p.repo_name, 10)
			status_fmt := pad_right(status_badge, 21)
			println('  ${c_bold}${name_fmt}${c_reset} ${c_yellow}${ver_fmt}${c_reset} ${c_purple}${repo_fmt}${c_reset} ${status_fmt} ${p.description}')
		}
	}

	if matches == 0 {
		println('  ${c_gray}No matching packages found.${c_reset}')
	}
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}\n')
	return 0
}

fn cmd_info(cfg Config, pkg_name string) int {
	pkgs := fetch_all_repo_packages(cfg)
	if pkgs.len == 0 {
		cmd_update(cfg)
	}
	fresh_pkgs := fetch_all_repo_packages(cfg)

	mut target := Package{}
	mut found := false
	for p in fresh_pkgs {
		if p.name == pkg_name {
			target = p
			found = true
			break
		}
	}

	if !found && is_installed(cfg, pkg_name) {
		meta_opt := get_installed_meta(cfg, pkg_name)
		if m := meta_opt {
			target = m
			found = true
		}
	}

	if !found {
		eprintln('${c_red}✗ Package "${pkg_name}" not found in repository index or installed database.${c_reset}')
		return 1
	}

	// Find repo url
	mut repo_url := ''
	for r in cfg.repos {
		if r.name == target.repo_name {
			repo_url = r.url
			break
		}
	}

	is_inst := is_installed(cfg, target.name)
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'

	println('${c_cyan}╭─ Package Information: ${c_bold}${target.name}${c_reset} ${c_cyan}──────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Name:${c_reset}         ${c_bold}${target.name}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Version:${c_reset}      ${c_yellow}${target.version}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Repository:${c_reset}   ${c_purple}${target.repo_name}${c_reset} (${repo_url})')
	println('${c_cyan}│${c_reset}  ${c_gray}Category:${c_reset}     ${c_purple}${target.category}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Payload Size:${c_reset} ${target.size}')
	println('${c_cyan}│${c_reset}  ${c_gray}Type:${c_reset}         ${target.pkg_type}')
	println('${c_cyan}│${c_reset}  ${c_gray}Binary Path:${c_reset}  ${target.bin}')
	println('${c_cyan}│${c_reset}  ${c_gray}Source Path:${c_reset}  ${target.src}')
	println('${c_cyan}│${c_reset}  ${c_gray}Status:${c_reset}       ' + if is_inst { '${c_green}● Installed${c_reset}' } else { '${c_cyan}○ Available for installation${c_reset}' })
	println('${c_cyan}│${c_reset}  ${c_gray}Exec Link:${c_reset}    ${ngpkg_bin}/${target.name}')
	println('${c_cyan}│${c_reset}  ${c_gray}Description:${c_reset}  ${target.description}')

	if is_inst {
		for d in get_installed_db_dirs(cfg) {
			list_file := '${d}/${target.name}.list'
			if os.exists(list_file) {
				lines := os.read_lines(list_file) or { []string{} }
				println('${c_cyan}│${c_reset}')
				println('${c_cyan}│${c_reset}  ${c_bold}Installed Files:${c_reset} (${lines.len} files)')
				mut count := 0
				for l in lines {
					if l.trim_space() != '' && count < 8 {
						println('${c_cyan}│${c_reset}    ${c_gray}•${c_reset} ${cfg.prefix}/${l.trim_space()}')
						count++
					}
				}
				if lines.len > 8 {
					println('${c_cyan}│${c_reset}    ${c_dim}... and ${lines.len - 8} more files${c_reset}')
				}
				break
			}
		}
	}

	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯\n')
	return 0
}

// ==============================================================================
// Commands: Install & Remove
// ==============================================================================

fn cmd_install(cfg Config, pkg_name string) int {
	pkgs := fetch_all_repo_packages(cfg)
	if pkgs.len == 0 {
		cmd_update(cfg)
	}
	fresh_pkgs := fetch_all_repo_packages(cfg)

	mut target_pkg := Package{}
	mut found := false
	for p in fresh_pkgs {
		if p.name == pkg_name {
			target_pkg = p
			found = true
			break
		}
	}

	if !found {
		// Check for local file
		if pkg_name.ends_with('.ngpkg') || pkg_name.ends_with('.tar.gz') || os.exists(pkg_name) {
			return cmd_install_local_file(cfg, pkg_name)
		}
		eprintln('${c_red}✗ Package "${pkg_name}" not found in any repository index.${c_reset}')
		eprintln('  Run ${c_bold}pkg list${c_reset} to view all available applications.')
		return 1
	}

	// Locate target repository object
	mut target_repo := Repo{ name: default_repo_name, url: default_repo_url, raw_url: default_repo_url, package_count: 0 }
	for r in cfg.repos {
		if r.name == target_pkg.repo_name {
			target_repo = r
			break
		}
	}

	mut bin_path := target_pkg.bin.trim_left('/')
	if bin_path == '' {
		bin_path = 'bin/${target_pkg.name}'
	}

	candidate_urls := get_repo_file_urls(target_repo, bin_path)

	println('${c_cyan}◈${c_reset} Installing ${c_bold}${target_pkg.name}${c_reset} (${c_yellow}v${target_pkg.version}${c_reset}, ${target_pkg.size}) from repo [${c_purple}${target_pkg.repo_name}${c_reset}]...')

	cache_dir := '${cfg.prefix}/cache'
	os.mkdir_all(cache_dir) or {}
	archive_filename := os.file_name(bin_path)
	dest_file := '${cache_dir}/${archive_filename}'

	print('  ${c_blue}[1/2]${c_reset} ⬇ Downloading from ${c_gray}${target_repo.name}${c_reset}...')
	mut downloaded := false
	for u in candidate_urls {
		if download_url(u, dest_file) {
			downloaded = true
			break
		}
	}

	if !downloaded {
		println(' ${c_red}FAILED${c_reset}')
		eprintln('${c_red}✗ Failed to download ${target_pkg.name} from repository ${target_repo.name}.${c_reset}')
		return 1
	}
	println(' ${c_green}DONE${c_reset}')

	res := deploy_package_payload(cfg, dest_file, target_pkg)
	// Clean cache file
	os.rm(dest_file) or {}
	return res
}

fn cmd_install_local_file(cfg Config, file_path string) int {
	if !os.exists(file_path) {
		eprintln('${c_red}✗ File not found: ${file_path}${c_reset}')
		return 1
	}
	base := os.file_name(file_path).trim_string_right('.ngpkg').trim_string_right('.tar.gz')
	pkg := Package{
		name: base
		version: 'local'
		arch: 'armv7l'
		size: format_bytes(u64(os.file_size(file_path)))
		description: 'Custom local package'
		category: 'custom'
		pkg_type: 'archive'
		repo_name: 'local'
	}
	println('${c_cyan}◈${c_reset} Installing local package file: ${c_bold}${file_path}${c_reset}...')
	return deploy_package_payload(cfg, file_path, pkg)
}

fn deploy_package_payload(cfg Config, payload_file string, pkg Package) int {
	print('  ${c_blue}[2/2]${c_reset} 📦 Deploying to ${c_bold}${cfg.prefix}${c_reset} & establishing links...')

	os.mkdir_all(cfg.prefix) or {}
	os.mkdir_all('${cfg.prefix}/bin') or {}
	os.mkdir_all('${cfg.prefix}/sbin') or {}
	os.mkdir_all('${cfg.prefix}/lib') or {}
	os.mkdir_all('${cfg.prefix}/etc') or {}
	os.mkdir_all('${cfg.prefix}/share') or {}
	os.mkdir_all('${cfg.prefix}/var/lib/ngpkg/installed') or {}
	os.mkdir_all('${cfg.db_dir}/installed') or {}

	mut installed_files := []string{}
	is_archive := payload_file.ends_with('.tar.gz') || payload_file.ends_with('.tgz') || payload_file.ends_with('.ngpkg') || payload_file.ends_with('.tar') || payload_file.ends_with('.tar.xz')

	if is_archive {
		// Discover files inside archive before unpacking
		list_cmd := '(gzip -dc "${payload_file}" 2>/dev/null || gunzip -c "${payload_file}" 2>/dev/null || cat "${payload_file}") | tar -tf - 2>/dev/null || tar -tf "${payload_file}" 2>/dev/null'
		res_list := os.execute(list_cmd)
		if res_list.exit_code == 0 {
			for f in res_list.output.split_into_lines() {
				trimmed := f.trim_space().trim_left('./')
				if trimmed != '' && !trimmed.ends_with('/') {
					installed_files << trimmed
				}
			}
		}

		// Unpack
		unpack_cmd := '(gzip -dc "${payload_file}" 2>/dev/null || gunzip -c "${payload_file}" 2>/dev/null || cat "${payload_file}") | tar -xf - -C "${cfg.prefix}" 2>/dev/null || tar -xf "${payload_file}" -C "${cfg.prefix}" 2>/dev/null'
		unpack_res := os.execute(unpack_cmd)
		if unpack_res.exit_code != 0 {
			println(' ${c_red}FAILED${c_reset}')
			eprintln('${c_red}✗ Failed to unpack payload archive to ${cfg.prefix}.${c_reset}')
			return 1
		}
	} else {
		// Standalone single executable binary
		bin_dest := '${cfg.prefix}/bin/${pkg.name}'
		os.cp(payload_file, bin_dest) or {
			println(' ${c_red}FAILED${c_reset}')
			eprintln('${c_red}✗ Failed to copy binary to ${bin_dest}.${c_reset}')
			return 1
		}
		os.chmod(bin_dest, 0o755) or {}
		installed_files << 'bin/${pkg.name}'
	}

	// Symlink binaries to user .ngpkg-bin
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'
	os.mkdir_all(ngpkg_bin) or {}
	if homedir != '/root' {
		os.mkdir_all('/root/.ngpkg-bin') or {}
	}

	mut service_units := []string{}

	for f in installed_files {
		full := '${cfg.prefix}/${f}'
		if f.starts_with('bin/') {
			b_name := f.all_after('bin/')
			if !b_name.contains('/') {
				os.chmod(full, 0o755) or {}
				sym := '${ngpkg_bin}/${b_name}'
				if !os.exists(sym) && !os.is_link(sym) { os.symlink(full, sym) or {} }
				if homedir != '/root' && !os.exists('/root/.ngpkg-bin/${b_name}') && !os.is_link('/root/.ngpkg-bin/${b_name}') {
					os.symlink(full, '/root/.ngpkg-bin/${b_name}') or {}
				}
			}
		} else if f.starts_with('sbin/') {
			b_name := f.all_after('sbin/')
			if !b_name.contains('/') {
				os.chmod(full, 0o755) or {}
				sym := '${ngpkg_bin}/${b_name}'
				if !os.exists(sym) && !os.is_link(sym) { os.symlink(full, sym) or {} }
				if homedir != '/root' && !os.exists('/root/.ngpkg-bin/${b_name}') && !os.is_link('/root/.ngpkg-bin/${b_name}') {
					os.symlink(full, '/root/.ngpkg-bin/${b_name}') or {}
				}
			}
		} else if f.starts_with('etc/systemd/system/') && f.ends_with('.service') {
			svc_name := f.all_after('etc/systemd/system/').trim_string_right('.service')
			os.mkdir_all('/etc/systemd/system') or {}
			dst := '/etc/systemd/system/${svc_name}.service'
			if !os.exists(dst) && !os.is_link(dst) {
				os.symlink(full, dst) or {}
			}
			service_units << svc_name
		}
	}

	// Always ensure primary package binary is symlinked if it exists in bin/
	if os.exists('${cfg.prefix}/bin/${pkg.name}') {
		p_target := '${cfg.prefix}/bin/${pkg.name}'
		os.chmod(p_target, 0o755) or {}
		if !os.exists('${ngpkg_bin}/${pkg.name}') && !os.is_link('${ngpkg_bin}/${pkg.name}') {
			os.symlink(p_target, '${ngpkg_bin}/${pkg.name}') or {}
		}
		if homedir != '/root' && !os.exists('/root/.ngpkg-bin/${pkg.name}') && !os.is_link('/root/.ngpkg-bin/${pkg.name}') {
			os.symlink(p_target, '/root/.ngpkg-bin/${pkg.name}') or {}
		}
	}

	// Check if a service named <pkg.name>.service was bundled
	if os.exists('/etc/systemd/system/${pkg.name}.service') && !service_units.contains(pkg.name) {
		service_units << pkg.name
	}

	// Start & enable services
	if service_units.len > 0 {
		os.execute('systemctl daemon-reload 2>/dev/null || true')
		for svc in service_units {
			os.execute('systemctl enable ${svc} 2>/dev/null || true')
			os.execute('systemctl start ${svc} 2>/dev/null || true')
		}
	}

	// Write installed receipt
	mut receipt_content := strings.new_builder(512)
	receipt_content.write_string('{\n')
	receipt_content.write_string('  "name": "${pkg.name}",\n')
	receipt_content.write_string('  "version": "${pkg.version}",\n')
	receipt_content.write_string('  "repo": "${pkg.repo_name}",\n')
	receipt_content.write_string('  "description": "${json_escape(pkg.description)}",\n')
	receipt_content.write_string('  "category": "${pkg.category}",\n')
	receipt_content.write_string('  "files": [\n')
	for idx, f in installed_files {
		comma := if idx < installed_files.len - 1 { ',' } else { '' }
		receipt_content.write_string('    "${f}"${comma}\n')
	}
	receipt_content.write_string('  ]\n}\n')

	receipt_dests := [
		'${cfg.prefix}/var/lib/ngpkg/installed/${pkg.name}.json',
		'${cfg.db_dir}/installed/${pkg.name}.json',
	]
	for d in receipt_dests {
		os.mkdir_all(os.dir(d)) or {}
		os.write_file(d, receipt_content.str()) or {}
	}

	// Also write legacy .list and .meta for backward compatibility
	list_content := installed_files.join('\n') + '\n'
	os.write_file('${cfg.prefix}/var/lib/ngpkg/installed/${pkg.name}.list', list_content) or {}
	os.write_file('${cfg.db_dir}/installed/${pkg.name}.list', list_content) or {}

	println(' ${c_green}DONE${c_reset}')
	println('\n${c_green}✓ Successfully installed ${c_bold}${pkg.name}${c_reset} (${pkg.version})!${c_reset}')
	println('  ${c_gray}Executables:${c_reset} ${c_cyan}${ngpkg_bin}/${pkg.name}${c_reset} (ready to run)\n')
	return 0
}

fn cmd_remove(cfg Config, pkg_name string) int {
	if !is_installed(cfg, pkg_name) {
		eprintln('${c_red}✗ Package "${pkg_name}" is not installed.${c_reset}')
		return 1
	}

	println('${c_cyan}◈${c_reset} Removing package ${c_bold}${pkg_name}${c_reset}...')

	// Stop systemd service if running
	os.execute('systemctl stop ${pkg_name} 2>/dev/null || true')
	os.execute('systemctl disable ${pkg_name} 2>/dev/null || true')

	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'

	// Collect file list to remove
	mut files_to_remove := []string{}
	for d in get_installed_db_dirs(cfg) {
		json_file := '${d}/${pkg_name}.json'
		if os.exists(json_file) {
			content := os.read_file(json_file) or { '' }
			if content.contains('"files"') {
				files_part := content.all_after('"files"').all_after('[').all_before(']')
				for line in files_part.split_into_lines() {
					trimmed := line.trim_space().trim('",')
					if trimmed != '' { files_to_remove << trimmed }
				}
			}
			break
		}
		list_file := '${d}/${pkg_name}.list'
		if os.exists(list_file) {
			lines := os.read_lines(list_file) or { []string{} }
			for l in lines {
				trimmed := l.trim_space()
				if trimmed != '' { files_to_remove << trimmed }
			}
			break
		}
	}

	// If no file list found, default to standard bin/
	if files_to_remove.len == 0 {
		files_to_remove << 'bin/${pkg_name}'
	}

	for f in files_to_remove {
		full := '${cfg.prefix}/${f}'
		if os.is_file(full) || os.is_link(full) {
			os.rm(full) or {}
		}

		if f.starts_with('bin/') {
			b_name := f.all_after('bin/')
			os.rm('${ngpkg_bin}/${b_name}') or {}
			if homedir != '/root' { os.rm('/root/.ngpkg-bin/${b_name}') or {} }
		} else if f.starts_with('sbin/') {
			b_name := f.all_after('sbin/')
			os.rm('${ngpkg_bin}/${b_name}') or {}
			if homedir != '/root' { os.rm('/root/.ngpkg-bin/${b_name}') or {} }
		} else if f.starts_with('etc/systemd/system/') {
			svc_file := f.all_after('etc/systemd/system/')
			os.rm('/etc/systemd/system/${svc_file}') or {}
		}
	}

	// Always cleanup direct symlinks for package name
	os.rm('${ngpkg_bin}/${pkg_name}') or {}
	if homedir != '/root' { os.rm('/root/.ngpkg-bin/${pkg_name}') or {} }

	// Remove receipt files
	for d in get_installed_db_dirs(cfg) {
		os.rm('${d}/${pkg_name}.json') or {}
		os.rm('${d}/${pkg_name}.list') or {}
		os.rm('${d}/${pkg_name}.meta') or {}
	}

	os.execute('systemctl daemon-reload 2>/dev/null || true')
	println('${c_green}✓ Package "${pkg_name}" removed successfully.${c_reset}\n')
	return 0
}

// ==============================================================================
// Commands: Repository Management
// ==============================================================================

fn cmd_repo_list(cfg Config, json_mode bool) int {
	if json_mode {
		mut items := []string{}
		for r in cfg.repos {
			cache_file := '${cfg.db_dir}/repos/${r.name}/index.json'
			mut count := 0
			if os.exists(cache_file) {
				c := os.read_file(cache_file) or { '' }
				pkgs := parse_index_json(c, r.name)
				count = pkgs.len
			}
			items << '{"name":"${r.name}","url":"${r.url}","raw_url":"${r.raw_url}","packages":${count}}'
		}
		println('[' + items.join(',') + ']')
		return 0
	}

	println('${c_bold}Configured OpenNGFW Repositories:${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')
	h_name := pad_right('NAME', 14)
	h_pkgs := pad_right('PACKAGES', 10)
	println('  ${c_bold}${h_name} ${h_pkgs} URL${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')

	for r in cfg.repos {
		cache_file := '${cfg.db_dir}/repos/${r.name}/index.json'
		mut count := 0
		if os.exists(cache_file) {
			c := os.read_file(cache_file) or { '' }
			pkgs := parse_index_json(c, r.name)
			count = pkgs.len
		}
		name_fmt := '${c_purple}${c_bold}${pad_right(r.name, 14)}${c_reset}'
		pkgs_fmt := '${c_cyan}${pad_right(count.str(), 10)}${c_reset}'
		println('  ${name_fmt} ${pkgs_fmt} ${r.url}')
	}
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}\n')
	return 0
}

fn cmd_repo_add(mut cfg Config, name string, url string) int {
	if name == '' || url == '' {
		eprintln('${c_red}Usage: pkg repo add <name> <git-or-raw-url>${c_reset}')
		return 1
	}

	// Check if already exists
	for mut r in cfg.repos {
		if r.name == name {
			println('${c_yellow}[*] Updating existing repository "${name}"...${c_reset}')
			r.url = url
			r.raw_url = normalize_repo_url(url)
			save_repos_config(cfg)
			return cmd_update(cfg)
		}
	}

	raw := normalize_repo_url(url)
	cfg.repos << Repo{ name: name, url: url, raw_url: raw, package_count: 0 }
	save_repos_config(cfg)
	println('${c_green}✓ Added repository "${name}": ${url}${c_reset}')
	println('  ${c_gray}Raw URL:${c_reset} ${raw}\n')
	return cmd_update(cfg)
}

fn cmd_repo_remove(mut cfg Config, name string) int {
	if name == '' {
		eprintln('${c_red}Usage: pkg repo remove <name>${c_reset}')
		return 1
	}

	mut idx := -1
	for i, r in cfg.repos {
		if r.name == name {
			idx = i
			break
		}
	}

	if idx == -1 {
		eprintln('${c_red}✗ Repository "${name}" not found in configuration.${c_reset}')
		return 1
	}

	cfg.repos.delete(idx)
	save_repos_config(cfg)

	// Clean cache files
	os.rmdir_all('${cfg.db_dir}/repos/${name}') or {}
	os.rmdir_all('${cfg.prefix}/var/lib/ngpkg/repos/${name}') or {}

	println('${c_green}✓ Removed repository "${name}".${c_reset}\n')
	return 0
}

// ==============================================================================
// Commands: Status
// ==============================================================================

fn cmd_status(cfg Config) int {
	installed := get_installed_packages(cfg)
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }

	println('${c_cyan}╭─ System & Storage Status ────────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Package Manager:${c_reset} ${c_bold}ngpkg v${version}${c_reset} (Serverless Edition)')
	println('${c_cyan}│${c_reset}  ${c_gray}Repositories:${c_reset}    ${cfg.repos.len} configured')
	for r in cfg.repos {
		println('${c_cyan}│${c_reset}    ${c_purple}• ${r.name}:${c_reset} ${r.url}')
	}
	println('${c_cyan}│${c_reset}  ${c_gray}Install Root:${c_reset}    ${cfg.prefix}')
	println('${c_cyan}│${c_reset}  ${c_gray}User Binaries:${c_reset}   ${homedir}/.ngpkg-bin')
	println('${c_cyan}│${c_reset}  ${c_gray}Installed:${c_reset}       ${c_green}${installed.len} packages${c_reset}')

	// USB storage check
	df_res := os.execute('df -h "${cfg.prefix}" 2>/dev/null | tail -n 1')
	if df_res.exit_code == 0 && df_res.output.trim_space() != '' {
		fields := df_res.output.fields()
		if fields.len >= 5 {
			total := fields[1]
			used := fields[2]
			avail := fields[3]
			percent := fields[4]
			println('${c_cyan}│${c_reset}')
			println('${c_cyan}│${c_reset}  ${c_bold}USB Storage (${cfg.prefix}):${c_reset}')
			println('${c_cyan}│${c_reset}    Total: ${total}  •  Used: ${used} (${percent})  •  Free: ${avail}')
		}
	}
	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯\n')
	return 0
}

fn print_help() {
	print_banner()
	println('${c_bold}USAGE:${c_reset}')
	println('  pkg <command> [arguments]\n')
	println('${c_bold}COMMANDS:${c_reset}')
	println('  ${c_cyan}update${c_reset}                      Sync latest package indexes from all git repos')
	println('  ${c_cyan}list${c_reset} [--json]               List all available & installed packages')
	println('  ${c_cyan}search${c_reset} <query>              Search packages by name, description, or category')
	println('  ${c_cyan}info${c_reset} <package>              Inspect package details, source & binary paths')
	println('  ${c_cyan}install${c_reset} <pkg|file>          Install package from repo or local archive')
	println('  ${c_cyan}remove${c_reset} <package>            Uninstall an application and clean symlinks/services')
	println('  ${c_cyan}repo list${c_reset} [--json]          List configured serverless repositories')
	println('  ${c_cyan}repo add${c_reset} <name> <url>       Add a new Git repository (GitHub/GitLab/etc.)')
	println('  ${c_cyan}repo remove${c_reset} <name>          Remove a configured repository')
	println('  ${c_cyan}status${c_reset}                      Display repositories, installed count & storage')
	println('  ${c_cyan}help${c_reset}                        Show this reference manual\n')
	println('${c_bold}EXAMPLES:${c_reset}')
	println('  pkg update')
	println('  pkg repo add custom https://github.com/myuser/my-openngfw-packages')
	println('  pkg list')
	println('  pkg install nano')
	println('  pkg remove nano\n')
}

fn main() {
	args := os.args[1..]
	if args.len == 0 {
		print_help()
		return
	}

	cmd := args[0]
	mut cfg := load_config()

	match cmd {
		'update', 'sync', 'refresh' {
			exit(cmd_update(cfg))
		}
		'list', 'ls' {
			json_mode := args.contains('--json') || args.contains('-j')
			exit(cmd_list(cfg, json_mode))
		}
		'search', 'find' {
			if args.len < 2 {
				eprintln('${c_red}Usage: pkg search <query>${c_reset}')
				exit(1)
			}
			exit(cmd_search(cfg, args[1]))
		}
		'info', 'show' {
			if args.len < 2 {
				eprintln('${c_red}Usage: pkg info <package>${c_reset}')
				exit(1)
			}
			exit(cmd_info(cfg, args[1]))
		}
		'install', 'i', 'add', 'get' {
			if args.len < 2 {
				eprintln('${c_red}Usage: pkg install <package|path/to/package>${c_reset}')
				exit(1)
			}
			exit(cmd_install(cfg, args[1]))
		}
		'remove', 'uninstall', 'rm', 'delete' {
			if args.len < 2 {
				eprintln('${c_red}Usage: pkg remove <package>${c_reset}')
				exit(1)
			}
			exit(cmd_remove(cfg, args[1]))
		}
		'repo', 'repos' {
			if args.len < 2 || args[1] == 'list' || args[1] == 'ls' {
				json_mode := args.contains('--json') || args.contains('-j')
				exit(cmd_repo_list(cfg, json_mode))
			}
			sub := args[1]
			if sub == 'add' {
				if args.len < 4 {
					eprintln('${c_red}Usage: pkg repo add <name> <git-or-raw-url>${c_reset}')
					exit(1)
				}
				exit(cmd_repo_add(mut cfg, args[2], args[3]))
			} else if sub in ['remove', 'rm', 'del', 'delete'] {
				if args.len < 3 {
					eprintln('${c_red}Usage: pkg repo remove <name>${c_reset}')
					exit(1)
				}
				exit(cmd_repo_remove(mut cfg, args[2]))
			} else {
				eprintln('${c_red}Unknown repo command: ${sub}. Available: list, add, remove${c_reset}')
				exit(1)
			}
		}
		'status', 'stat', 'df' {
			exit(cmd_status(cfg))
		}
		'help', '--help', '-h' {
			print_help()
			exit(0)
		}
		'version', '--version', '-v' {
			println('ngpkg version ${version} (Serverless Edition)')
			exit(0)
		}
		else {
			eprintln('${c_red}Unknown command: "${cmd}"${c_reset}')
			eprintln('Run ${c_bold}pkg help${c_reset} for available commands.')
			exit(1)
		}
	}
}
