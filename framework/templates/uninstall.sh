#!/bin/sh
# OpenNGFW Package Teardown Hook
# Executed by 'pkg remove <name>' on the router before file deletion.
set -e

# Stop running processes if active
killall example-app 2>/dev/null || true
