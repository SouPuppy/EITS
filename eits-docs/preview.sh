#!/bin/bash

set -e

SCRIPT_DIR=$(dirname "$(realpath "$0")")
echo "Script directory: $SCRIPT_DIR"

PROJECT_DIR=$(git -C "$SCRIPT_DIR" rev-parse --show-toplevel 2>/dev/null)

if [ -z "$PROJECT_DIR" ]; then
    echo "Project root directory not found via git, falling back to script directory."
    PROJECT_DIR=$SCRIPT_DIR
fi

echo "Project directory: $PROJECT_DIR"

source "$PROJECT_DIR/eits-docs/setup.sh"

SOURCE_DIR="docs"
PORT=5050

setup_paths
setup_venv
install_requirements

# === Launch MkDocs preview ===
echo -e "\n\033[1;32m[SUCCESS]\033[0m Preview server running at: \033[1mhttp://127.0.0.1:$PORT\033[0m"
mkdocs serve -a 127.0.0.1:$PORT --config-file mkdocs.yml --watch "$SOURCE_DIR"
