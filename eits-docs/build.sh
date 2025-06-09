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

SOURCE_DIR="$PROJECT_DIR/eits-docs/docs"
SITE_DIR="$PROJECT_DIR/eits-docs/build/public"

setup_paths
setup_venv
install_requirements

# === Build MkDocs site ===
echo -e "\n\033[1;34m[INFO]\033[0m Cleaning and building MkDocs site..."
mkdocs build --clean --config-file mkdocs.yml --site-dir "$SITE_DIR"

echo -e "\n\033[1;32m[SUCCESS]\033[0m Site build complete. Output located at: \033[1m$SITE_DIR/\033[0m"
