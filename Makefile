# ==============================================================================
# ngpkg: OpenNGFW Package Manager Workspace Makefile
# ==============================================================================

PORT ?= 8000

.PHONY: all client client-host client-arm server packages build-all serve test clean help new

all: client-host server packages

client: client-host client-arm

client-host:
	$(MAKE) -C client host

client-arm:
	$(MAKE) -C client arm

server:
	$(MAKE) -C server server

packages build-all:
	python3 framework/ngpkg_build.py build-all

new:
	@if [ -z "$(PKG)" ]; then \
		echo "Usage: make new PKG=<package-name>"; exit 1; \
	fi
	python3 framework/ngpkg_build.py new $(PKG)

list-recipes:
	python3 framework/ngpkg_build.py list

serve:
	./server/pkg_server --port $(PORT)

test:
	@echo "=== Running ngpkg Test Suite ==="
	python3 framework/ngpkg_build.py validate recipes/nano
	python3 framework/ngpkg_build.py validate recipes/htop
	python3 framework/ngpkg_build.py validate recipes/screen
	python3 framework/ngpkg_build.py validate recipes/bareiron
	./client/ngpkg_host --version
	@echo "[✓] All tests passed successfully!"

clean:
	$(MAKE) -C client clean
	$(MAKE) -C server clean
	rm -rf repo/packages/*.ngpkg repo/packages/*.apkg repo/packages/index.txt repo/packages/index.json

help:
	@echo "ngpkg Top-Level Build Targets:"
	@echo "  make                      Build host client, server, and all package recipes"
	@echo "  make client               Build client for host and ARM target"
	@echo "  make client-host          Build native host client binary (client/ngpkg_host)"
	@echo "  make client-arm           Build cross-compiled ARM client binary (client/ngpkg)"
	@echo "  make server               Build repository HTTP server (server/pkg_server)"
	@echo "  make packages             Build all recipes in recipes/ into repo/packages/"
	@echo "  make new PKG=<name>       Scaffold a new recipe under recipes/<name>/"
	@echo "  make list-recipes         List all available package recipes"
	@echo "  make serve [PORT=8000]    Launch repository server and web dashboard"
	@echo "  make test                 Run framework and client test suite"
	@echo "  make clean                Clean binaries and generated packages"
