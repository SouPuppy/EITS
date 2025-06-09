#pragma once

#include <fstream>
#include <sstream>
#include <memory>
#include <filesystem>

namespace logger {

// Return current time as a formatted string
std::string current_time_string();

enum LogColor {
	DEFAULT,
	BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE,
	BRIGHT_BLACK, BRIGHT_RED, BRIGHT_GREEN, BRIGHT_YELLOW,
	BRIGHT_BLUE, BRIGHT_MAGENTA, BRIGHT_CYAN, BRIGHT_WHITE,
};

// Return ANSI color escape code for the given color
std::string color_code(LogColor color);

// Text style for log output
struct Format {
	LogColor color;
	bool bold, italic, underlined;

	Format(LogColor color = DEFAULT, bool bold = false, bool italic = false, bool underlined = false);
	std::string polish(const std::string& str) const;
};

// Stream object for log output
struct LogStream {
	std::string header;
	Format format;
	std::string title;
	std::ostringstream buffer;
	bool has_payload = false;
	std::shared_ptr<std::ofstream> file_out;

	LogStream(std::string header, Format format, std::string title, std::shared_ptr<std::ofstream> out);

	LogStream(const LogStream&) = delete;
	LogStream& operator=(const LogStream&) = delete;
	LogStream(LogStream&&) = default;
	LogStream& operator=(LogStream&&) = default;

	// Stream operator for inserting content
	template <typename T>
	LogStream& operator<<(const T& value) {
		buffer << "  " << value << "\n";
		has_payload = true;
		return *this;
	}

	~LogStream();
};

// Log factory used to produce LogStream instances
struct LogFactory {
	std::shared_ptr<std::ofstream> log_file = std::make_shared<std::ofstream>();
	std::string header;
	Format format;

	LogFactory(std::string h, Format f);

	// Initialize file output
	void init(const std::filesystem::path& log_path_obj);

	// Create a new log stream with optional title
	LogStream operator()(const std::string& title = "") const;

	// Shortcut for one-liner stream
	template <typename T>
	LogStream operator<<(const T& value) const {
		LogStream stream(header, format, "", log_file);
		stream << value;
		return std::move(stream);
	}
};

// Global logger initializer
void init(const std::string& log_path = "");

} // namespace logger

// Default logging categories
namespace logger::log {

extern LogFactory LOG;
extern LogFactory INFO;
extern LogFactory WARNING;
extern LogFactory DEBUG;
extern LogFactory ERROR;
extern LogFactory OK;
extern LogFactory FAILED;

} // namespace logger::log
