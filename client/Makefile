# ==============================================================================
# ngpkg Client Makefile
# ==============================================================================

CC ?= gcc
CFLAGS ?= -std=gnu11 -w -O2

CROSS_CC ?= /home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-gcc
CROSS_STRIP ?= /home/weexnes/AnbergearOS/build/r6300v2/host/bin/arm-buildroot-linux-musleabi-strip

.PHONY: all host arm c clean

all: host

host: ngpkg_host

ngpkg_host: ngpkg.c
	$(CC) $(CFLAGS) ngpkg.c -o ngpkg_host
	@echo "[✓] Built ngpkg_host for $(shell uname -m)"

arm: ngpkg

ngpkg: ngpkg.c
	@if [ -f "$(CROSS_CC)" ]; then \
		$(CROSS_CC) $(CFLAGS) -pie -fPIE ngpkg.c -o ngpkg; \
		$(CROSS_STRIP) --strip-all ngpkg 2>/dev/null || true; \
		echo "[✓] Built ngpkg for ARMv7-A (musl)"; \
	else \
		echo "[!] Cross-compiler not found at $(CROSS_CC)"; exit 1; \
	fi

c:
	@if command -v v >/dev/null 2>&1; then \
		v -os linux -gc none -o ngpkg.c ngpkg.v; \
		echo "[✓] Generated standalone C source: ngpkg.c"; \
	else \
		echo "[!] V compiler not found in PATH"; exit 1; \
	fi

clean:
	rm -f ngpkg ngpkg_host
