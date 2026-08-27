// ==============================================================================
// ngpkg: Next-Generation Package Manager for OpenNGFW
// Written in V for performance, safety, and zero-dependency standalone execution
// ==============================================================================

module main

import os
import strings

const version = '1.2.0'
const default_repo_url = 'http://192.168.1.1:8000/packages'
const default_install_prefix = '/mnt/usb/opt'
const default_db_dir = '/var/lib/ngpkg'

struct Config {
	repo_url string
	prefix   string
	db_dir   string
}

struct PackageMeta {
	name        string
	version     string
	size        string
	description string
	category    string
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

fn print_banner() {
	println('${c_cyan}╭──────────────────────────────────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_bold}🛡️  OpenNGFW Package Manager${c_reset} (${c_green}ngpkg v${version}${c_reset})                 ${c_cyan}│${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Prefix: /mnt/usb/opt  •  Binaries: ~/.ngpkg-bin${c_reset}             ${c_cyan}│${c_reset}')
	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯${c_reset}')
}

fn load_config() Config {
	mut repo_url := os.getenv('REPO_URL')
	mut prefix := os.getenv('INSTALL_PREFIX')
	mut db_dir := os.getenv('PKG_DB')

	// Load from /etc/ngpkg.conf or /etc/pkg.conf
	conf_paths := [
		os.getenv('PKG_CONF'),
		'/etc/ngpkg.conf',
		'/etc/pkg.conf',
		'/mnt/usb/opt/etc/ngpkg.conf',
	]

	for p in conf_paths {
		if p != '' && os.exists(p) {
			lines := os.read_lines(p) or { []string{} }
			for line in lines {
				trimmed := line.trim_space()
				if trimmed.starts_with('#') || trimmed == '' {
					continue
				}
				if trimmed.starts_with('REPO_URL=') && repo_url == '' {
					repo_url = trimmed.all_after('REPO_URL=').trim(' "\'')
				} else if trimmed.starts_with('INSTALL_PREFIX=') && prefix == '' {
					prefix = trimmed.all_after('INSTALL_PREFIX=').trim(' "\'')
				} else if trimmed.starts_with('PKG_DB=') && db_dir == '' {
					db_dir = trimmed.all_after('PKG_DB=').trim(' "\'')
				}
			}
			break
		}
	}

	if repo_url == '' {
		repo_url = default_repo_url
	}
	if prefix == '' {
		prefix = default_install_prefix
	}
	if db_dir == '' {
		db_dir = default_db_dir
	}

	return Config{
		repo_url: repo_url.trim_right('/')
		prefix: prefix.trim_right('/')
		db_dir: db_dir.trim_right('/')
	}
}

fn get_installed_packages(cfg Config) []string {
	inst_dir := '${cfg.db_dir}/installed'
	if !os.is_dir(inst_dir) {
		alt_dir := '${cfg.prefix}/var/lib/pkg/installed'
		if !os.is_dir(alt_dir) {
			return []
		}
		files := os.ls(alt_dir) or { []string{} }
		mut pkgs := []string{}
		for f in files {
			if f.ends_with('.list') {
				pkgs << f.trim_string_right('.list')
			}
		}
		return pkgs
	}
	files := os.ls(inst_dir) or { []string{} }
	mut pkgs := []string{}
	for f in files {
		if f.ends_with('.list') {
			pkgs << f.trim_string_right('.list')
		}
	}
	return pkgs
}

fn is_installed(cfg Config, pkg_name string) bool {
	return os.exists('${cfg.db_dir}/installed/${pkg_name}.list') ||
		os.exists('${cfg.prefix}/var/lib/pkg/installed/${pkg_name}.list')
}

fn fetch_index(cfg Config) []PackageMeta {
	index_file := '${cfg.db_dir}/cache/index.txt'
	if !os.exists(index_file) {
		return []
	}
	content := os.read_file(index_file) or { return [] }
	mut pkgs := []PackageMeta{}
	for line in content.split_into_lines() {
		trimmed := line.trim_space()
		if trimmed == '' || trimmed.starts_with('#') {
			continue
		}
		parts := trimmed.split('|')
		if parts.len >= 4 {
			pkgs << PackageMeta{
				name: parts[0].trim_space()
				version: parts[1].trim_space()
				size: parts[2].trim_space()
				description: parts[3].trim_space()
				category: if parts.len >= 5 { parts[4].trim_space() } else { 'utilities' }
			}
		}
	}
	return pkgs
}

// ==============================================================================
// Commands
// ==============================================================================

fn cmd_update(cfg Config) int {
	println('${c_cyan}◈${c_reset} Updating repository package index...')
	println('  ${c_gray}Source:${c_reset} ${c_blue}${cfg.repo_url}${c_reset}')

	os.mkdir_all('${cfg.db_dir}/cache') or {}
	target_file := '${cfg.db_dir}/cache/index.txt'

	base_url := cfg.repo_url.trim_string_right('/packages').trim_right('/')
	urls_to_try := [
		'${cfg.repo_url}/index.txt',
		'${base_url}/packages/index.txt',
		'${base_url}/index.txt',
	]

	mut success := false
	for url in urls_to_try {
		cmd := 'wget -q -O "${target_file}" "${url}"'
		res := os.execute(cmd)
		if res.exit_code == 0 && os.exists(target_file) && os.file_size(target_file) > 0 {
			success = true
			break
		}
	}

	if !success {
		eprintln('${c_red}✗ Failed to download package index from repository.${c_reset}')
		eprintln('  ${c_yellow}Tip:${c_reset} Ensure package server is running or configure REPO_URL in /etc/ngpkg.conf')
		return 1
	}

	pkgs := fetch_index(cfg)
	println('${c_green}✓ Repository updated successfully!${c_reset} (${c_bold}${pkgs.len}${c_reset} packages available)\n')
	return 0
}

fn cmd_list(cfg Config) int {
	pkgs := fetch_index(cfg)
	if pkgs.len == 0 {
		println('${c_yellow}[! Hot Tip]${c_reset} No local index found. Running ${c_bold}pkg update${c_reset} first...\n')
		if cmd_update(cfg) != 0 {
			return 1
		}
	}

	fresh_pkgs := fetch_index(cfg)
	installed := get_installed_packages(cfg)

	println('${c_bold}OpenNGFW Package Repository:${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')
	header_name := pad_right('NAME', 16)
	header_ver := pad_right('VERSION', 10)
	header_size := pad_right('SIZE', 9)
	header_status := pad_right('STATUS', 14)
	println('  ${c_bold}${header_name} ${header_ver} ${header_size} ${header_status} DESCRIPTION${c_reset}')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')

	mut inst_count := 0
	for p in fresh_pkgs {
		is_inst := installed.contains(p.name)
		if is_inst {
			inst_count++
		}
		status_badge := if is_inst {
			'${c_green}● installed${c_reset}'
		} else {
			'${c_cyan}○ available${c_reset}'
		}
		name_fmt := if is_inst { '${c_green}${c_bold}${pad_right(p.name, 16)}${c_reset}' } else { '${c_bold}${pad_right(p.name, 16)}${c_reset}' }
		ver_fmt := '${c_yellow}${pad_right(p.version, 10)}${c_reset}'
		size_fmt := '${c_gray}${pad_right(p.size, 9)}${c_reset}'
		status_fmt := pad_right(status_badge, 23)
		
		println('  ${name_fmt} ${ver_fmt} ${size_fmt} ${status_fmt} ${p.description}')
	}
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')
	println('  ${c_gray}Total:${c_reset} ${fresh_pkgs.len} packages  (${c_green}${inst_count} installed${c_reset}, ${c_cyan}${fresh_pkgs.len - inst_count} available${c_reset})\n')
	return 0
}

fn cmd_search(cfg Config, query string) int {
	pkgs := fetch_index(cfg)
	if pkgs.len == 0 {
		cmd_update(cfg)
	}
	fresh_pkgs := fetch_index(cfg)
	installed := get_installed_packages(cfg)
	q := query.to_lower()

	println('${c_cyan}◈${c_reset} Search results for "${c_bold}${query}${c_reset}":')
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}')

	mut matches := 0
	for p in fresh_pkgs {
		if p.name.to_lower().contains(q) || p.description.to_lower().contains(q) || p.category.to_lower().contains(q) {
			matches++
			is_inst := installed.contains(p.name)
			status_badge := if is_inst { '${c_green}[installed]${c_reset}' } else { '${c_cyan}[available]${c_reset}' }
			name_fmt := pad_right(p.name, 14)
			ver_fmt := pad_right(p.version, 8)
			size_fmt := pad_right(p.size, 8)
			status_fmt := pad_right(status_badge, 21)
			println('  ${c_bold}${name_fmt}${c_reset} ${c_yellow}${ver_fmt}${c_reset} ${c_gray}${size_fmt}${c_reset} ${status_fmt} ${p.description}')
		}
	}

	if matches == 0 {
		println('  ${c_gray}No matching packages found.${c_reset}')
	}
	println('${c_gray}────────────────────────────────────────────────────────────────────────────────${c_reset}\n')
	return 0
}

fn cmd_info(cfg Config, pkg_name string) int {
	pkgs := fetch_index(cfg)
	if pkgs.len == 0 {
		cmd_update(cfg)
	}
	fresh_pkgs := fetch_index(cfg)

	mut target := PackageMeta{}
	mut found := false
	for p in fresh_pkgs {
		if p.name == pkg_name {
			target = p
			found = true
			break
		}
	}

	if !found {
		eprintln('${c_red}✗ Package "${pkg_name}" not found in repository index.${c_reset}')
		return 1
	}

	is_inst := is_installed(cfg, pkg_name)
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'

	println('${c_cyan}╭─ Package Information: ${c_bold}${target.name}${c_reset} ${c_cyan}──────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Name:${c_reset}         ${c_bold}${target.name}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Version:${c_reset}      ${c_yellow}${target.version}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Category:${c_reset}     ${c_purple}${target.category}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Payload Size:${c_reset} ${target.size} (Compressed)')
	println('${c_cyan}│${c_reset}  ${c_gray}Status:${c_reset}       ' + if is_inst { '${c_green}● Installed${c_reset}' } else { '${c_cyan}○ Available for installation${c_reset}' })
	println('${c_cyan}│${c_reset}  ${c_gray}Prefix:${c_reset}       ${cfg.prefix}')
	println('${c_cyan}│${c_reset}  ${c_gray}Binary Path:${c_reset}  ${ngpkg_bin}/${target.name}')
	println('${c_cyan}│${c_reset}  ${c_gray}Description:${c_reset}  ${target.description}')

	if is_inst {
		list_file := '${cfg.db_dir}/installed/${pkg_name}.list'
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
		}
	}

	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯${c_reset}\n')
	return 0
}

fn cmd_status(cfg Config) int {
	installed := get_installed_packages(cfg)
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }

	println('${c_cyan}╭─ System & Storage Status ────────────────────────────────────╮${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Package Manager:${c_reset} ${c_bold}ngpkg v${version}${c_reset}')
	println('${c_cyan}│${c_reset}  ${c_gray}Repository URL:${c_reset}  ${c_blue}${cfg.repo_url}${c_reset}')
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
	println('${c_cyan}╰──────────────────────────────────────────────────────────────╯${c_reset}\n')
	return 0
}

fn cmd_install(cfg Config, pkg_name string) int {
	pkgs := fetch_index(cfg)
	if pkgs.len == 0 {
		println('${c_yellow}[! No index]${c_reset} Updating repository index first...')
		if cmd_update(cfg) != 0 {
			return 1
		}
	}
	fresh_pkgs := fetch_index(cfg)

	mut target_pkg := PackageMeta{}
	mut found := false
	for p in fresh_pkgs {
		if p.name == pkg_name {
			target_pkg = p
			found = true
			break
		}
	}

	if !found {
		eprintln('${c_red}✗ Package "${pkg_name}" not found in repository index.${c_reset}')
		eprintln('  Run ${c_bold}pkg list${c_reset} to see all available applications.')
		return 1
	}

	if is_installed(cfg, pkg_name) {
		println('${c_yellow}[!] Package "${pkg_name}" is already installed.${c_reset} Reinstalling...')
	}

	println('${c_cyan}◈${c_reset} Installing ${c_bold}${target_pkg.name}${c_reset} (${c_yellow}v${target_pkg.version}${c_reset}, ${target_pkg.size})...')

	// Step 1: Download
	print('  ${c_blue}[1/3]${c_reset} ⬇ Downloading payload...')
	os.mkdir_all('${cfg.db_dir}/cache') or {}
	archive_file := '${cfg.db_dir}/cache/${target_pkg.name}-${target_pkg.version}.ngpkg'

	base_url := cfg.repo_url.trim_string_right('/packages').trim_right('/')
	candidate_urls := [
		'${cfg.repo_url}/${target_pkg.name}-${target_pkg.version}.ngpkg',
		'${cfg.repo_url}/${target_pkg.name}-${target_pkg.version}.apkg',
		'${cfg.repo_url}/${target_pkg.name}.ngpkg',
		'${base_url}/${target_pkg.name}-${target_pkg.version}.ngpkg',
		'${base_url}/${target_pkg.name}.ngpkg',
	]

	mut downloaded := false
	for url in candidate_urls {
		dl_cmd := 'wget -q -O "${archive_file}" "${url}"'
		dl_res := os.execute(dl_cmd)
		if dl_res.exit_code == 0 && os.exists(archive_file) && os.file_size(archive_file) > 0 {
			downloaded = true
			break
		}
	}

	if !downloaded {
		println(' ${c_red}FAILED${c_reset}')
		eprintln('${c_red}✗ Failed to download package ${target_pkg.name} from repository.${c_reset}')
		return 1
	}
	println(' ${c_green}DONE${c_reset}')

	// Step 2: Unpack
	print('  ${c_blue}[2/3]${c_reset} 📦 Unpacking to ${c_bold}${cfg.prefix}${c_reset}...')
	os.mkdir_all(cfg.prefix) or {}
	os.mkdir_all('${cfg.prefix}/bin') or {}
	os.mkdir_all('${cfg.prefix}/sbin') or {}
	os.mkdir_all('${cfg.prefix}/lib') or {}
	os.mkdir_all('${cfg.prefix}/libexec') or {}
	os.mkdir_all('${cfg.prefix}/etc') or {}
	os.mkdir_all('${cfg.prefix}/share') or {}
	os.mkdir_all('${cfg.db_dir}/installed') or {}

	// Multi-fallback extraction pipeline:
	mut unpack_cmd := 'gzip -dc "${archive_file}" 2>/dev/null | tar -xf - -C "${cfg.prefix}"'
	mut unpack_res := os.execute(unpack_cmd)
	if unpack_res.exit_code != 0 {
		unpack_cmd = 'gunzip -c "${archive_file}" 2>/dev/null | tar -xf - -C "${cfg.prefix}"'
		unpack_res = os.execute(unpack_cmd)
	}
	if unpack_res.exit_code != 0 {
		unpack_cmd = 'tar -xzf "${archive_file}" -C "${cfg.prefix}" 2>/dev/null'
		unpack_res = os.execute(unpack_cmd)
	}
	if unpack_res.exit_code != 0 {
		unpack_cmd = 'tar -xf "${archive_file}" -C "${cfg.prefix}" 2>/dev/null'
		unpack_res = os.execute(unpack_cmd)
	}

	if unpack_res.exit_code != 0 {
		println(' ${c_red}FAILED${c_reset}')
		eprintln('${c_red}✗ Failed to extract package payload.${c_reset}')
		return 1
	}
	println(' ${c_green}DONE${c_reset}')

	// Record installed file list
	list_file := '${cfg.db_dir}/installed/${target_pkg.name}.list'
	list_cmd := '(gzip -dc "${archive_file}" 2>/dev/null || gunzip -c "${archive_file}" 2>/dev/null || cat "${archive_file}") | tar -tf - > "${list_file}" 2>/dev/null || tar -tf "${archive_file}" > "${list_file}" 2>/dev/null || true'
	os.execute(list_cmd)

	meta_file := '${cfg.db_dir}/installed/${target_pkg.name}.meta'
	os.write_file(meta_file, 'NAME=${target_pkg.name}\nVERSION=${target_pkg.version}\nDESCRIPTION=${target_pkg.description}\nCATEGORY=${target_pkg.category}\n') or {}

	// Step 3: Symlink
	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'
	print('  ${c_blue}[3/3]${c_reset} 🔗 Linking binaries to ${c_bold}${ngpkg_bin}${c_reset}...')

	os.mkdir_all(ngpkg_bin) or {}
	if homedir != '/root' {
		os.mkdir_all('/root/.ngpkg-bin') or {}
	}

	if os.is_dir('${cfg.prefix}/bin') {
		bin_files := os.ls('${cfg.prefix}/bin') or { []string{} }
		for b in bin_files {
			target := '${cfg.prefix}/bin/${b}'
			os.chmod(target, 0o755) or {}
			symlink := '${ngpkg_bin}/${b}'
			if !os.exists(symlink) {
				os.symlink(target, symlink) or {}
			}
			if homedir != '/root' && !os.exists('/root/.ngpkg-bin/${b}') {
				os.symlink(target, '/root/.ngpkg-bin/${b}') or {}
			}
		}
	}

	if os.is_dir('${cfg.prefix}/sbin') {
		sbin_files := os.ls('${cfg.prefix}/sbin') or { []string{} }
		for b in sbin_files {
			target := '${cfg.prefix}/sbin/${b}'
			os.chmod(target, 0o755) or {}
			symlink := '${ngpkg_bin}/${b}'
			if !os.exists(symlink) {
				os.symlink(target, symlink) or {}
			}
			if homedir != '/root' && !os.exists('/root/.ngpkg-bin/${b}') {
				os.symlink(target, '/root/.ngpkg-bin/${b}') or {}
			}
		}
	}

	// Link init scripts
	if os.is_dir('${cfg.prefix}/etc/init.d') {
		os.mkdir_all('/etc/init.d') or {}
		init_scripts := os.ls('${cfg.prefix}/etc/init.d') or { []string{} }
		for s in init_scripts {
			src := '${cfg.prefix}/etc/init.d/${s}'
			dst := '/etc/init.d/${s}'
			os.chmod(src, 0o755) or {}
			if !os.exists(dst) {
				os.symlink(src, dst) or {}
			}
		}
	}

	println(' ${c_green}DONE${c_reset}')

	// Auto-start systemd service if present
	service_file := '/etc/systemd/system/${target_pkg.name}.service'
	if os.exists(service_file) {
		println('  ${c_purple}⚡ Registering system service:${c_reset} ${target_pkg.name}.service')
		os.execute('systemctl enable ${target_pkg.name} 2>/dev/null || true')
		os.execute('systemctl start ${target_pkg.name} 2>/dev/null || true')
	}

	println('\n${c_green}✓ Successfully installed ${c_bold}${target_pkg.name}${c_reset} (${target_pkg.version})!${c_reset}')
	println('  ${c_gray}Executables:${c_reset} ${c_cyan}${ngpkg_bin}/${target_pkg.name}${c_reset} (ready to run)\n')
	return 0
}

fn cmd_remove(cfg Config, pkg_name string) int {
	if !is_installed(cfg, pkg_name) {
		eprintln('${c_red}✗ Package "${pkg_name}" is not installed.${c_reset}')
		return 1
	}

	println('${c_cyan}◈${c_reset} Removing package ${c_bold}${pkg_name}${c_reset}...')

	// Stop service if present
	service_file := '/etc/systemd/system/${pkg_name}.service'
	if os.exists(service_file) {
		os.execute('systemctl stop ${pkg_name} 2>/dev/null || true')
		os.execute('systemctl disable ${pkg_name} 2>/dev/null || true')
	}

	homedir := if os.getenv('HOME') != '' { os.getenv('HOME') } else { '/root' }
	ngpkg_bin := '${homedir}/.ngpkg-bin'

	mut list_file := '${cfg.db_dir}/installed/${pkg_name}.list'
	if !os.exists(list_file) {
		list_file = '${cfg.prefix}/var/lib/pkg/installed/${pkg_name}.list'
	}

	if os.exists(list_file) {
		lines := os.read_lines(list_file) or { []string{} }
		for i := lines.len - 1; i >= 0; i-- {
			rel_path := lines[i].trim_space()
			if rel_path.len == 0 {
				continue
			}
			full_path := '${cfg.prefix}/${rel_path}'
			if os.is_file(full_path) || os.is_link(full_path) {
				os.rm(full_path) or {}
			} else if os.is_dir(full_path) {
				os.rmdir(full_path) or {}
			}
			// Unlink .ngpkg-bin
			if rel_path.starts_with('bin/') {
				bin_name := rel_path.all_after('bin/')
				symlink := '${ngpkg_bin}/${bin_name}'
				if os.is_link(symlink) {
					os.rm(symlink) or {}
				}
				if os.is_link('/root/.ngpkg-bin/${bin_name}') {
					os.rm('/root/.ngpkg-bin/${bin_name}') or {}
				}
			} else if rel_path.starts_with('sbin/') {
				sbin_name := rel_path.all_after('sbin/')
				symlink := '${ngpkg_bin}/${sbin_name}'
				if os.is_link(symlink) {
					os.rm(symlink) or {}
				}
				if os.is_link('/root/.ngpkg-bin/${sbin_name}') {
					os.rm('/root/.ngpkg-bin/${sbin_name}') or {}
				}
			} else if rel_path.starts_with('etc/init.d/') {
				svc_name := rel_path.all_after('etc/init.d/')
				init_link := '/etc/init.d/${svc_name}'
				if os.is_link(init_link) {
					os.rm(init_link) or {}
				}
			}
		}
		os.rm(list_file) or {}
	}

	meta_file := '${cfg.db_dir}/installed/${pkg_name}.meta'
	if os.exists(meta_file) {
		os.rm(meta_file) or {}
	}

	println('${c_green}✓ Package "${pkg_name}" removed successfully.${c_reset}\n')
	return 0
}

fn cmd_self_update(cfg Config) int {
	println('${c_cyan}◈${c_reset} Checking for ngpkg client updates...')
	update_url := '${cfg.repo_url}/ngpkg'
	tmp_binary := '/tmp/ngpkg_new'

	dl_res := os.execute('wget -q -O "${tmp_binary}" "${update_url}"')
	if dl_res.exit_code != 0 || !os.exists(tmp_binary) || os.file_size(tmp_binary) < 1000 {
		eprintln('${c_red}✗ Could not fetch update binary from ${update_url}${c_reset}')
		return 1
	}

	os.chmod(tmp_binary, 0o755) or {}
	dest_path := '/usr/bin/ngpkg'
	if os.exists(dest_path) {
		os.cp(tmp_binary, dest_path) or {
			eprintln('${c_red}✗ Failed to overwrite ${dest_path}: read-only or permission error${c_reset}')
			return 1
		}
		os.chmod(dest_path, 0o755) or {}
	}
	os.rm(tmp_binary) or {}

	println('${c_green}✓ ngpkg updated successfully!${c_reset}\n')
	return 0
}

fn print_help() {
	print_banner()
	println('${c_bold}USAGE:${c_reset}')
	println('  pkg <command> [arguments]\n')
	println('${c_bold}COMMANDS:${c_reset}')
	println('  ${c_cyan}update${c_reset}              Sync latest package index from repository')
	println('  ${c_cyan}list${c_reset}                List all available & installed packages')
	println('  ${c_cyan}search${c_reset} <query>      Search packages by name, description, or category')
	println('  ${c_cyan}info${c_reset} <package>      Inspect package details, size, and installed files')
	println('  ${c_cyan}install${c_reset} <package>   Install an application to USB storage (/mnt/usb/opt)')
	println('  ${c_cyan}remove${c_reset} <package>    Uninstall an application and clean symlinks')
	println('  ${c_cyan}status${c_reset}              Display USB storage, prefix, and repository info')
	println('  ${c_cyan}self-update${c_reset}         Update ngpkg package manager to the latest version')
	println('  ${c_cyan}help${c_reset}                Show this reference manual\n')
	println('${c_bold}EXAMPLES:${c_reset}')
	println('  pkg update')
	println('  pkg install btop')
	println('  pkg install screen')
	println('  pkg info git')
	println('  pkg search wireguard\n')
}

fn main() {
	args := os.args[1..]
	if args.len == 0 {
		print_help()
		return
	}

	cmd := args[0]
	cfg := load_config()

	match cmd {
		'update', 'sync', 'refresh' {
			exit(cmd_update(cfg))
		}
		'list', 'ls' {
			exit(cmd_list(cfg))
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
				eprintln('${c_red}Usage: pkg install <package>${c_reset}')
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
		'status', 'stat', 'df' {
			exit(cmd_status(cfg))
		}
		'self-update', 'selfupdate', 'upgrade-pkg' {
			exit(cmd_self_update(cfg))
		}
		'help', '--help', '-h' {
			print_help()
			exit(0)
		}
		'version', '--version', '-v' {
			println('ngpkg version ${version} (OpenNGFW Edition)')
			exit(0)
		}
		else {
			eprintln('${c_red}Unknown command: "${cmd}"${c_reset}')
			eprintln('Run ${c_bold}pkg help${c_reset} for available commands.')
			exit(1)
		}
	}
}
