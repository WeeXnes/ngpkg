// ==============================================================================
// PKHeX.Everywhere Native HTTP Static Web Server (Blazor WebAssembly)
// ==============================================================================
module main

import os
import net
import flag

fn get_mime_type(file_path string) string {
	ext := os.file_ext(file_path).to_lower()
	match ext {
		'.html', '.htm' { return 'text/html; charset=utf-8' }
		'.js', '.mjs' { return 'text/javascript; charset=utf-8' }
		'.css' { return 'text/css; charset=utf-8' }
		'.json' { return 'application/json' }
		'.wasm' { return 'application/wasm' }
		'.dll', '.bin', '.dat' { return 'application/octet-stream' }
		'.png' { return 'image/png' }
		'.jpg', '.jpeg' { return 'image/jpeg' }
		'.gif' { return 'image/gif' }
		'.svg' { return 'image/svg+xml' }
		'.ico' { return 'image/x-icon' }
		'.woff2' { return 'font/woff2' }
		'.woff' { return 'font/woff' }
		'.ttf' { return 'font/ttf' }
		'.mp3' { return 'audio/mpeg' }
		'.wav' { return 'audio/wav' }
		'.mp4' { return 'video/mp4' }
		'.txt' { return 'text/plain; charset=utf-8' }
		else { return 'application/octet-stream' }
	}
}

fn send_file(mut conn net.TcpConn, file_path string) {
	if !os.exists(file_path) || os.is_dir(file_path) {
		conn.write_string('HTTP/1.1 404 Not Found\r\nContent-Length: 9\r\nConnection: close\r\n\r\nNot Found') or {}
		return
	}

	size := os.file_size(file_path)
	mime := get_mime_type(file_path)

	header := 'HTTP/1.1 200 OK\r\n' +
		'Content-Type: ${mime}\r\n' +
		'Content-Length: ${size}\r\n' +
		'Cache-Control: public, max-age=86400\r\n' +
		'Access-Control-Allow-Origin: *\r\n' +
		'Connection: close\r\n\r\n'

	conn.write_string(header) or { return }

	mut f := os.open_file(file_path, 'r') or { return }
	defer { f.close() }

	mut buf := []u8{len: 64 * 1024}
	for {
		n := f.read(mut buf) or { break }
		if n <= 0 {
			break
		}
		conn.write(buf[..n]) or { break }
	}
}

fn handle_connection(mut conn net.TcpConn, public_dir string) {
	defer { conn.close() or {} }

	mut buf := []u8{len: 4096}
	n := conn.read(mut buf) or { return }
	if n <= 0 {
		return
	}

	req_str := buf[..n].bytestr()
	lines := req_str.split_into_lines()
	if lines.len == 0 {
		return
	}

	parts := lines[0].split(' ')
	if parts.len < 2 {
		return
	}

	raw_path := parts[1].all_before('?').all_before('#')
	clean_path := raw_path.trim_left('/')

	target_file := if clean_path == '' {
		os.join_path(public_dir, 'index.html')
	} else {
		os.join_path(public_dir, clean_path)
	}

	if os.exists(target_file) && !os.is_dir(target_file) {
		send_file(mut conn, target_file)
		return
	}

	// SPA Fallback for Blazor WebAssembly client-side routes
	spa_index := os.join_path(public_dir, 'index.html')
	if os.exists(spa_index) {
		send_file(mut conn, spa_index)
		return
	}

	conn.write_string('HTTP/1.1 404 Not Found\r\nContent-Length: 9\r\nConnection: close\r\n\r\nNot Found') or {}
}

fn worker(conn_chan chan &net.TcpConn, public_dir string) {
	for {
		mut conn := <-conn_chan or { break }
		handle_connection(mut conn, public_dir)
	}
}

fn main() {
	mut fp := flag.new_flag_parser(os.args)
	fp.application('pkhex-server')
	fp.version('1.0.0')
	fp.description('Lightweight static server for PKHeX.Everywhere Blazor WASM')

	port := fp.int('port', `p`, 5062, 'HTTP server port')
	public_dir := fp.string('dir', `d`, '/mnt/usb/opt/share/pkhex/public', 'Public root directory')
	fp.finalize() or {
		eprintln(err)
		return
	}

	println('=======================================================================')
	println('  🎮 PKHeX.Everywhere Web Server (Blazor WebAssembly)')
	println('=======================================================================')
	println('  Port       : ${port}')
	println('  Public Dir : ${public_dir}')
	println('=======================================================================')

	mut listener := net.listen_tcp(.ip, '0.0.0.0:${port}') or {
		eprintln('Failed to bind on 0.0.0.0:${port}: ${err}')
		return
	}
	defer { listener.close() or {} }

	println('PKHeX web editor is listening on http://0.0.0.0:${port}/\n')

	conn_chan := chan &net.TcpConn{cap: 128}
	for _ in 0 .. 8 {
		spawn worker(conn_chan, public_dir)
	}

	for {
		mut conn := listener.accept() or { continue }
		conn_chan <- conn
	}
}
