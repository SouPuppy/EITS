# Logger

**Logger** is a lightweight and extensible C++ logging library that supports terminal output formatting, ANSI color styling, log levels, and file-based logging. It is designed for clarity, minimalism, and easy integration in both development and production environments.

---

## Features

- Standard log levels:
  - `INFO`, `WARNING`, `ERROR`, `DEBUG`, `DEV_INFO`, `OK`, `FAILED`
- Rich terminal formatting with:
  - Text styles: **bold**, *italic*, and underline
  - 16-color ANSI support (including bright variants)
- Timestamped log entries for traceability
- Output to both terminal and file
- Verbose mode control via CMake option
- Minimal and modern C++ interface

---

## Installation

### CMake Integration

Add the library to your CMake project:

```cmake
add_subdirectory(lib/Log)

# Optional: enable or disable verbose terminal logging
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)
```

---

## Usage

### Initialization

```cpp
#include <logger.h>

int main() {
    logger::init(); // Or use a custom path: logger::init("logs/output.log");
}
```

---

### Basic Logging

```cpp
#include <logger.h>
using namespace logger::log;

int main(int argc, char *argv[]) {
	
	INFO("This is an informational message.");
	WARNING("This is a warning.");
	ERROR("An error has occurred.");
	DEBUG("Debugging details.");
	LOG("Developer-specific internal log.");
	OK("This is a OK message");
	FAILED("This is a FAILED message");

	return 0;
}	
```

---

## Log Format

Each log entry includes:

- Timestamp
- Log level
- Styled and colored output (terminal only)

### `LogFormat` Structure

You can fully customize the appearance of logs using the `LogFormat` struct:

```cpp
struct LogFormat {
    LogLevel level;
    LogColor color;
    bool bold;
    bool italic;
    bool underline;
};
```

---

### Predefined Formats

```cpp
const format::LogFormat INFO     = {INFO, BRIGHT_BLUE,   true, false, false};
const format::LogFormat WARN     = {WARN, BRIGHT_YELLOW, true, false, false};
const format::LogFormat DEBUG    = {DEBUG, BRIGHT_GREEN, true, false, false};
const format::LogFormat ERROR    = {ERROR, BRIGHT_RED,   true, false, false};
const format::LogFormat DEV_INFO = {INFO,  BRIGHT_BLACK, true, false, false};
```

---

## Output

- Log files are saved by default to:

```
./log/YYYY-MM-DD_HH-MM-SS.log
```

- To specify a custom path:

```cpp
logger::init("logs/custom_output.log");
```

---

## Verbose Mode

To control terminal output, configure the `ENABLE_LOG_VERBOSE` option in CMake:

```cmake
option(ENABLE_LOG_VERBOSE "Enable verbose logging" ON)  # Enable terminal + file logging
option(ENABLE_LOG_VERBOSE "Enable verbose logging" OFF) # File-only logging
```

---
