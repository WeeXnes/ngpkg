// ==============================================================================
// OpenNGFW Package Repository Server (Written in V)
// High-performance, streaming standalone package server for OpenNGFW routers
// ==============================================================================

module main

import io
import net
import os
import strings
import time

const default_port = 8000
const server_version = "1.3.0"

struct PkgInfo {
	name        string
	version     string
	size        string
	description string
	category    string
	filename    string
}

fn get_local_ips() []string {
	res := os.execute('ip -4 -o addr show 2>/dev/null')
	if res.exit_code != 0 {
		return ['127.0.0.1']
	}
	mut ips := []string{}
	for line in res.output.split_into_lines() {
		parts := line.fields()
		if parts.len >= 4 {
			ip_with_mask := parts[3]
			ip := ip_with_mask.split('/')[0]
			if ip != '127.0.0.1' && !ips.contains(ip) {
				ips << ip
			}
		}
	}
	if ips.len == 0 {
		ips << '127.0.0.1'
	}
	return ips
}

fn load_packages(repo_dir string) []PkgInfo {
	index_file := os.join_path(repo_dir, 'index.txt')
	if !os.exists(index_file) {
		return []
	}
	content := os.read_file(index_file) or { return [] }
	mut pkgs := []PkgInfo{}
	for line in content.split_into_lines() {
		trimmed := line.trim_space()
		if trimmed == '' || trimmed.starts_with('#') {
			continue
		}
		parts := trimmed.split('|')
		if parts.len >= 4 {
			p_name := parts[0].trim_space()
			p_ver := parts[1].trim_space()
			p_sz := parts[2].trim_space()
			p_desc := parts[3].trim_space()
			p_cat := if parts.len >= 5 { parts[4].trim_space() } else { 'utilities' }
			pkgs << PkgInfo{
				name: p_name
				version: p_ver
				size: p_sz
				description: p_desc
				category: p_cat
				filename: '${p_name}-${p_ver}.ngpkg'
			}
		}
	}
	return pkgs
}

fn generate_html_dashboard(pkgs []PkgInfo, ips []string, port int) string {
	primary_ip := if ips.len > 0 { ips[0] } else { '192.168.1.1' }
	
	mut rows := strings.new_builder(2048)
	for p in pkgs {
		rows.write_string('
        <tr>
            <td class="pkg-name"><strong>${p.name}</strong></td>
            <td><span class="badge badge-ver">${p.version}</span></td>
            <td><span class="badge badge-cat">${p.category}</span></td>
            <td><span class="badge badge-size">${p.size}</span></td>
            <td class="pkg-desc">${p.description}</td>
            <td class="pkg-actions">
                <a href="/packages/${p.filename}" class="btn btn-download">Download</a>
                <code class="cmd-snippet" title="Click to copy" onclick="copyCmd(\'pkg install ${p.name}\')">pkg install ${p.name}</code>
            </td>
        </tr>')
	}

	mut ip_badges := strings.new_builder(256)
	for ip in ips {
		ip_badges.write_string('<span class="badge badge-ip">${ip}:${port}</span> ')
	}

	return '<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>OpenNGFW Package Repository</title>
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Fira+Code:wght@400;600&family=Inter:wght@400;500;600;700;800&display=swap" rel="stylesheet">
    <style>
        :root {
            --bg: #0b0f19;
            --surface: #111827;
            --surface-border: #1f2937;
            --primary: #06b6d4;
            --primary-glow: rgba(6, 182, 212, 0.2);
            --accent: #3b82f6;
            --success: #10b981;
            --text-main: #f9fafb;
            --text-muted: #9ca3af;
            --code-bg: #1f2937;
        }

        * { box-sizing: border-box; margin: 0; padding: 0; }
        body {
            font-family: \'Inter\', sans-serif;
            background-color: var(--bg);
            color: var(--text-main);
            line-height: 1.6;
            padding: 2rem 1rem;
            min-height: 100vh;
        }

        .container {
            max-width: 1100px;
            margin: 0 auto;
        }

        .header {
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 2rem;
            padding-bottom: 1.5rem;
            border-bottom: 1px solid var(--surface-border);
            flex-wrap: wrap;
            gap: 1rem;
        }

        .logo-group {
            display: flex;
            align-items: center;
            gap: 1rem;
        }

        .logo-icon {
            font-size: 2.2rem;
            background: linear-gradient(135deg, var(--primary), var(--accent));
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
        }

        h1 {
            font-size: 1.6rem;
            font-weight: 800;
            letter-spacing: -0.025em;
        }

        .subtitle {
            color: var(--text-muted);
            font-size: 0.875rem;
        }

        .hero-box {
            background: linear-gradient(180deg, rgba(17, 24, 39, 0.8), rgba(11, 15, 25, 0.9));
            border: 1px solid var(--surface-border);
            border-radius: 12px;
            padding: 1.5rem;
            margin-bottom: 2rem;
            backdrop-filter: blur(10px);
            box-shadow: 0 4px 20px -2px rgba(0, 0, 0, 0.5);
        }

        .hero-title {
            font-size: 1.1rem;
            font-weight: 700;
            margin-bottom: 0.75rem;
            color: var(--primary);
            display: flex;
            align-items: center;
            gap: 0.5rem;
        }

        .config-instruction {
            font-size: 0.9rem;
            color: var(--text-muted);
            margin-bottom: 0.75rem;
        }

        .code-block {
            background: var(--code-bg);
            border: 1px solid rgba(255, 255, 255, 0.05);
            border-radius: 8px;
            padding: 0.75rem 1rem;
            font-family: \'Fira Code\', monospace;
            font-size: 0.875rem;
            color: #38bdf8;
            overflow-x: auto;
            display: flex;
            justify-content: space-between;
            align-items: center;
        }

        .endpoints {
            margin-top: 1rem;
            display: flex;
            align-items: center;
            gap: 0.5rem;
            flex-wrap: wrap;
        }

        .badge {
            font-size: 0.75rem;
            font-weight: 600;
            padding: 0.25rem 0.5rem;
            border-radius: 6px;
            display: inline-block;
        }

        .badge-ip {
            background: rgba(59, 130, 246, 0.15);
            color: #60a5fa;
            border: 1px solid rgba(59, 130, 246, 0.3);
            font-family: \'Fira Code\', monospace;
        }

        .badge-ver {
            background: rgba(16, 185, 129, 0.15);
            color: #34d399;
            font-family: \'Fira Code\', monospace;
        }

        .badge-cat {
            background: rgba(168, 85, 247, 0.15);
            color: #c084fc;
        }

        .badge-size {
            background: rgba(255, 255, 255, 0.08);
            color: #94a3b8;
            font-family: \'Fira Code\', monospace;
        }

        .search-bar {
            margin-bottom: 1.5rem;
            width: 100%;
        }

        .search-input {
            width: 100%;
            background: var(--surface);
            border: 1px solid var(--surface-border);
            border-radius: 8px;
            padding: 0.75rem 1rem;
            color: var(--text-main);
            font-size: 0.95rem;
            outline: none;
            transition: border-color 0.2s;
        }

        .search-input:focus {
            border-color: var(--primary);
            box-shadow: 0 0 0 2px var(--primary-glow);
        }

        .table-container {
            background: var(--surface);
            border: 1px solid var(--surface-border);
            border-radius: 12px;
            overflow: hidden;
            box-shadow: 0 4px 15px -3px rgba(0, 0, 0, 0.3);
        }

        table {
            width: 100%;
            border-collapse: collapse;
            text-align: left;
            font-size: 0.9rem;
        }

        th {
            background: rgba(255, 255, 255, 0.02);
            padding: 1rem;
            font-weight: 600;
            color: var(--text-muted);
            border-bottom: 1px solid var(--surface-border);
            font-size: 0.8rem;
            text-transform: uppercase;
            letter-spacing: 0.05em;
        }

        td {
            padding: 1rem;
            border-bottom: 1px solid rgba(255, 255, 255, 0.03);
            vertical-align: middle;
        }

        tr:hover {
            background: rgba(255, 255, 255, 0.02);
        }

        .pkg-name strong {
            color: #e0f2fe;
            font-size: 0.95rem;
        }

        .pkg-desc {
            color: var(--text-muted);
            max-width: 350px;
        }

        .pkg-actions {
            display: flex;
            align-items: center;
            gap: 0.5rem;
            flex-wrap: wrap;
        }

        .btn {
            text-decoration: none;
            font-size: 0.8rem;
            font-weight: 600;
            padding: 0.4rem 0.75rem;
            border-radius: 6px;
            transition: all 0.2s;
            display: inline-block;
        }

        .btn-download {
            background: rgba(6, 182, 212, 0.1);
            color: var(--primary);
            border: 1px solid rgba(6, 182, 212, 0.3);
        }

        .btn-download:hover {
            background: var(--primary);
            color: #000;
        }

        .cmd-snippet {
            background: var(--code-bg);
            border: 1px solid var(--surface-border);
            padding: 0.35rem 0.6rem;
            border-radius: 6px;
            font-family: \'Fira Code\', monospace;
            font-size: 0.75rem;
            color: #cbd5e1;
            cursor: pointer;
            user-select: all;
            transition: background 0.2s;
        }

        .cmd-snippet:hover {
            background: #374151;
            border-color: #4b5563;
        }

        .footer {
            margin-top: 3rem;
            text-align: center;
            font-size: 0.8rem;
            color: var(--text-muted);
            border-top: 1px solid var(--surface-border);
            padding-top: 1.5rem;
        }

        .toast {
            position: fixed;
            bottom: 20px;
            right: 20px;
            background: var(--success);
            color: #000;
            padding: 0.75rem 1.25rem;
            border-radius: 8px;
            font-weight: 600;
            font-size: 0.875rem;
            opacity: 0;
            transform: translateY(10px);
            transition: all 0.3s;
            pointer-events: none;
            box-shadow: 0 4px 12px rgba(16, 185, 129, 0.3);
        }

        .toast.show {
            opacity: 1;
            transform: translateY(0);
        }
    </style>
</head>
<body>
    <div class="container">
        <header class="header">
            <div class="logo-group">
                <div class="logo-icon">🛡️</div>
                <div>
                    <h1>OpenNGFW Package Repository</h1>
                    <div class="subtitle">Next-Generation Streaming Package Server • v' + server_version + '</div>
                </div>
            </div>
            <div class="endpoints">
                <span style="font-size: 0.85rem; color: var(--text-muted)">Listening on:</span>
                ' + ip_badges.str() + '
            </div>
        </header>

        <section class="hero-box">
            <div class="hero-title">🚀 Quick Router Setup</div>
            <div class="config-instruction">Point your router\'s package manager to this repository by running:</div>
            <div class="code-block">
                <span>export REPO_URL="http://' + primary_ip + ':' + port.str() + '/packages" &amp;&amp; pkg update</span>
                <button class="btn btn-download" onclick="copyCmd(\'export REPO_URL=&quot;http://' + primary_ip + ':' + port.str() + '/packages&quot; &amp;&amp; pkg update\')">Copy</button>
            </div>
        </section>

        <div class="search-bar">
            <input type="text" id="search" class="search-input" placeholder="🔍 Search packages by name or description..." onkeyup="filterTable()">
        </div>

        <div class="table-container">
            <table id="pkgTable">
                <thead>
                    <tr>
                        <th>Package</th>
                        <th>Version</th>
                        <th>Category</th>
                        <th>Size</th>
                        <th>Description</th>
                        <th>Actions</th>
                    </tr>
                </thead>
                <tbody>
                    ' + rows.str() + '
                </tbody>
            </table>
        </div>

        <footer class="footer">
            OpenNGFW Package Repository Server • Built with V with zero memory leaks and buffered streaming.
        </footer>
    </div>

    <div id="toast" class="toast">Copied command to clipboard!</div>

    <script>
        function filterTable() {
            const input = document.getElementById("search");
            const filter = input.value.toLowerCase();
            const table = document.getElementById("pkgTable");
            const tr = table.getElementsByTagName("tr");

            for (let i = 1; i < tr.length; i++) {
                const name = tr[i].getElementsByTagName("td")[0]?.textContent || "";
                const desc = tr[i].getElementsByTagName("td")[4]?.textContent || "";
                if (name.toLowerCase().indexOf(filter) > -1 || desc.toLowerCase().indexOf(filter) > -1) {
                    tr[i].style.display = "";
                } else {
                    tr[i].style.display = "none";
                }
            }
        }

        function copyCmd(text) {
            navigator.clipboard.writeText(text).then(() => {
                const toast = document.getElementById("toast");
                toast.classList.add("show");
                setTimeout(() => toast.classList.remove("show"), 2000);
            });
        }
    </script>
</body>
</html>'
}

fn handle_client(mut conn net.TcpConn, repo_dir string, port int, start_time time.Time) {
	defer {
		conn.close() or {}
	}

	conn.set_read_timeout(10 * time.second)
	conn.set_write_timeout(120 * time.second)

	mut reader := io.new_buffered_reader(reader: conn)
	req_line := reader.read_line() or { return }
	parts := req_line.split(' ')
	if parts.len < 2 {
		return
	}

	method := parts[0]
	if method != 'GET' && method != 'HEAD' {
		not_impl := 'HTTP/1.1 501 Not Implemented\r\nContent-Length: 0\r\nConnection: close\r\n\r\n'
		conn.write_string(not_impl) or {}
		return
	}

	raw_url := parts[1].split('?')[0]
	mut clean_path := raw_url.trim_left('/')

	now_str := time.now().format_ss()

	if clean_path.starts_with('packages/') {
		clean_path = clean_path.trim_string_left('packages/').trim_left('/')
	} else if clean_path == 'packages' {
		clean_path = ''
	}

	// 1. Dashboard Route
	if clean_path == '' || clean_path == 'index.html' || clean_path == 'dashboard' {
		pkgs := load_packages(repo_dir)
		ips := get_local_ips()
		html := generate_html_dashboard(pkgs, ips, port)
		header := 'HTTP/1.1 200 OK\r\nServer: OpenNGFW-PkgServer/${server_version}\r\nContent-Type: text/html; charset=utf-8\r\nContent-Length: ${html.len}\r\nAccess-Control-Allow-Origin: *\r\nConnection: close\r\n\r\n'
		conn.write_string(header) or { return }
		if method == 'GET' {
			conn.write_string(html) or { return }
		}
		println('[$now_str] 200 GET / (Dashboard)')
		return
	}

	// 2. Health check API
	if clean_path == 'api/health' || clean_path == 'health' {
		uptime := (time.now() - start_time).seconds()
		pkgs := load_packages(repo_dir)
		body := '{"status":"healthy","uptime_seconds":${uptime},"packages_count":${pkgs.len},"version":"${server_version}"}\n'
		header := 'HTTP/1.1 200 OK\r\nServer: OpenNGFW-PkgServer/${server_version}\r\nContent-Type: application/json; charset=utf-8\r\nContent-Length: ${body.len}\r\nAccess-Control-Allow-Origin: *\r\nConnection: close\r\n\r\n'
		conn.write_string(header) or { return }
		if method == 'GET' {
			conn.write_string(body) or { return }
		}
		println('[$now_str] 200 GET /api/health')
		return
	}

	// 3. JSON API
	if clean_path == 'api/packages' || clean_path == 'index.json' || clean_path == 'packages.json' {
		json_path := os.join_path(repo_dir, 'index.json')
		if os.exists(json_path) {
			content := os.read_file(json_path) or { '{}' }
			header := 'HTTP/1.1 200 OK\r\nServer: OpenNGFW-PkgServer/${server_version}\r\nContent-Type: application/json; charset=utf-8\r\nContent-Length: ${content.len}\r\nAccess-Control-Allow-Origin: *\r\nConnection: close\r\n\r\n'
			conn.write_string(header) or { return }
			if method == 'GET' {
				conn.write_string(content) or { return }
			}
			println('[$now_str] 200 GET /${clean_path}')
			return
		}
	}

	// 4. File Serving (Streaming mode in 64KB blocks)
	target_file := os.join_path(repo_dir, clean_path)

	if !os.exists(target_file) || os.is_dir(target_file) {
		println('[$now_str] 404 GET /${clean_path} (Not Found)')
		err_body := '404 Not Found: ${clean_path}\n'
		not_found := 'HTTP/1.1 404 Not Found\r\nServer: OpenNGFW-PkgServer/${server_version}\r\nContent-Type: text/plain\r\nContent-Length: ${err_body.len}\r\nAccess-Control-Allow-Origin: *\r\nConnection: close\r\n\r\n${err_body}'
		conn.write_string(not_found) or {}
		return
	}

	file_size := os.file_size(target_file)

	mut content_type := 'application/octet-stream'
	if clean_path.ends_with('.ngpkg') || clean_path.ends_with('.apkg') || clean_path.ends_with('.tar.gz') {
		content_type = 'application/gzip'
	} else if clean_path.ends_with('.txt') {
		content_type = 'text/plain; charset=utf-8'
	} else if clean_path.ends_with('.json') {
		content_type = 'application/json; charset=utf-8'
	}

	header := 'HTTP/1.1 200 OK\r\nServer: OpenNGFW-PkgServer/${server_version}\r\nContent-Type: ${content_type}\r\nContent-Length: ${file_size}\r\nAccept-Ranges: bytes\r\nAccess-Control-Allow-Origin: *\r\nConnection: close\r\n\r\n'
	conn.write_string(header) or { return }

	if method == 'GET' {
		mut f := os.open(target_file) or {
			println('[$now_str] 500 GET /${clean_path} (File Open Error)')
			return
		}
		defer {
			f.close()
		}

		mut buf := []u8{len: 65536}
		mut total_sent := u64(0)
		for {
			n := f.read(mut buf) or { break }
			if n <= 0 {
				break
			}
			conn.write(buf[..n]) or {
				println('[$now_str] ! Connection reset by client during transfer: ${clean_path} (${total_sent}/${file_size} bytes sent)')
				return
			}
			total_sent += u64(n)
		}
		println('[$now_str] 200 GET /${clean_path} (${total_sent} bytes streamed)')
	} else {
		println('[$now_str] 200 HEAD /${clean_path} (${file_size} bytes)')
	}
}

fn kill_port_conflict(port int) {
	os.execute('fuser -k ${port}/tcp 2>/dev/null')
	time.sleep(300 * time.millisecond)
}

fn main() {
	mut port := default_port
	mut repo_dir := ''

	for i := 0; i < os.args.len; i++ {
		if os.args[i] == '--port' && i + 1 < os.args.len {
			port = os.args[i + 1].int()
		} else if os.args[i] == '--repo' && i + 1 < os.args.len {
			repo_dir = os.args[i + 1]
		}
	}

	if repo_dir == '' {
		candidates := [
			'/home/weexnes/ngpkg/repo/packages',
			os.join_path(os.dir(os.real_path(os.args[0])), '../repo/packages'),
			os.join_path(os.dir(os.real_path(os.args[0])), 'repo/packages'),
		]
		for c in candidates {
			if os.exists(c) {
				repo_dir = c
				break
			}
		}
		if repo_dir == '' {
			repo_dir = '/home/weexnes/ngpkg/repo/packages'
		}
	}

	kill_port_conflict(port)

	ips := get_local_ips()
	primary_ip := if ips.len > 0 { ips[0] } else { '127.0.0.1' }
	pkgs := load_packages(repo_dir)

	println('=======================================================================')
	println('  🛡️  OpenNGFW Streaming Package Server (Vlang Edition v${server_version})')
	println('=======================================================================')
	println('  Serving Directory : ${repo_dir}')
	println('  Indexed Packages  : ${pkgs.len} available')
	println('  Listening Port    : ${port}')
	println('')
	println('  Reachable Endpoints:')
	for ip in ips {
		println('    -> http://${ip}:${port}/packages')
	}
	println('')
	println('  Web Dashboard     : http://127.0.0.1:${port}/')
	println('  Router Config     : REPO_URL="http://${primary_ip}:${port}/packages"')
	println('=======================================================================')
	println('Press Ctrl+C to stop the server.\n')

	start_time := time.now()
	mut listener := net.listen_tcp(.ip, '0.0.0.0:${port}') or {
		eprintln('Failed to bind on port ${port}: ${err}')
		return
	}
	defer {
		listener.close() or {}
	}

	for {
		mut conn := listener.accept() or {
			continue
		}
		spawn handle_client(mut conn, repo_dir, port, start_time)
	}
}
