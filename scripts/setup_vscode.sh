#!/bin/bash

SCRIPT_DIR=$(dirname "$(realpath "$0")")
echo "Script directory: $SCRIPT_DIR"

PROJECT_DIR=$(git -C "$SCRIPT_DIR" rev-parse --show-toplevel 2>/dev/null)

if [ -z "$PROJECT_DIR" ]; then
    echo "Project root directory not found via git, falling back to script directory."
    PROJECT_DIR=$SCRIPT_DIR
fi

echo "Project directory: $PROJECT_DIR"

if [ -d "$PROJECT_DIR/.vscode" ]; then
    echo ".vscode directory already exists. Removing old link..."
    rm -rf "$PROJECT_DIR/.vscode"
fi

echo "Creating symbolic link for VSCode configuration..."
ln -s "$PROJECT_DIR/tools/editor/vscode" "$PROJECT_DIR/.vscode"

echo "Symbolic link created successfully!"
