# ==============================================================================
# ngpkg Server Makefile
# ==============================================================================

PORT ?= 8000

.PHONY: all server serve clean

all: server

server: pkg_server

pkg_server: pkg_server.v
	@if command -v v >/dev/null 2>&1; then \
		v -prod pkg_server.v -o pkg_server; \
		echo "[✓] Built pkg_server (Vlang)"; \
	else \
		echo "[!] V compiler not found in PATH"; exit 1; \
	fi

serve: server
	./pkg_server --port $(PORT)

clean:
	rm -f pkg_server
