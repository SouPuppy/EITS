# scripts/common/setup.sh

set -e

# === Common Setup for MkDocs-based projects ===

function setup_paths() {
	SCRIPT_DIR=$(dirname "$(realpath "$0")")
	echo "Script directory: $SCRIPT_DIR"

	PROJECT_DIR=$(git -C "$SCRIPT_DIR" rev-parse --show-toplevel 2>/dev/null)

	if [ -z "$PROJECT_DIR" ]; then
			echo "Project root directory not found via git, falling back to script directory."
			PROJECT_DIR=$SCRIPT_DIR
	fi

	echo "Project directory: $PROJECT_DIR"
	
	cd "$PROJECT_DIR/eits-docs"

	VENV_DIR=".venv"
	REQUIREMENTS_FILE="requirements.txt"
}

function setup_venv() {
	echo -e "\033[1;34m[INFO]\033[0m Using pip index: \033[1m${PIP_INDEX_URL:-https://pypi.tuna.tsinghua.edu.cn/simple}\033[0m"
	export PIP_INDEX_URL="${PIP_INDEX_URL:-https://pypi.tuna.tsinghua.edu.cn/simple}"

	if [ ! -d "$VENV_DIR" ]; then
		echo -e "\033[1;32m[INFO]\033[0m Creating virtual environment at $VENV_DIR"
		python3 -m venv "$VENV_DIR"
	else
		echo -e "\033[1;34m[INFO]\033[0m Using existing virtual environment at $VENV_DIR"
	fi

	source "$VENV_DIR/bin/activate"
}

function install_local_packages() {
	LOCAL_PKG_DIRS=(
		"koala/koala-lexer/pygments-koala"
	)

	for dir in "${LOCAL_PKG_DIRS[@]}"; do
		if [ -d "$dir" ]; then
			echo -e "\n\033[1;36m[INFO]\033[0m Installing local package: \033[1m$dir\033[0m"
			pip install -e "$dir"
		else
			echo -e "\033[1;31m[ERROR]\033[0m Local package not found: $dir"
			exit 1
		fi
	done
}

function install_requirements() {
	echo -e "\n\033[1;33m[INFO]\033[0m Upgrading pip..."
	python -m pip install --upgrade pip

	echo -e "\n\033[1;33m[INFO]\033[0m Installing dependencies from \033[1m$REQUIREMENTS_FILE\033[0m"

	if [ ! -f "$REQUIREMENTS_FILE" ]; then
		echo -e "\033[1;31m[ERROR]\033[0m Requirements file not found: $REQUIREMENTS_FILE"
		exit 1
	fi

	while IFS= read -r line || [[ -n "$line" ]]; do
		if [[ "$line" != "" && "$line" != \#* ]]; then
			echo -e "  [ + ] Installing \033[1m$line\033[0m"
			pip install "$line"
		fi
	done < "$REQUIREMENTS_FILE"
}
