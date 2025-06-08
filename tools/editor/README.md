# Editor Configuration

This directory contains optional IDE/editor settings for supported development environments.

## Supported Editors

- **VSCode**: `tools/editor/vscode/`

## Usage

These configurations are **optional** and not activated by default.

To use them, you can either:

1. **Manually create a symbolic link**:

	```bash
	# For VSCode
	ln -s tools/editor/vscode .vscode
	```

2. **Automatically setup using the provided script**

	Alternatively, you can run the setup_editor.sh script, which will automatically create the symbolic link for you.

	To run the script, use the following command:

	> **Important:** Run the script from the project root directory.
	
	```
	scripts/setup_vscode.sh
	```

	This will create the required symbolic link for your editor configuration in the project root.

## Notes:

	The configuration is specific to VSCode at the moment. If you're using a different editor, you may need to adjust the settings manually.