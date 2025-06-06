#pragma once

#include <iostream>
#include <string>
#include <fstream>

namespace logger::format {

enum LogLevel {
	INFO,
	WARNING,
	ERROR,
	DEBUG,
	OK,
	FAILED,
};

enum LogColor {
	DEFAULT,
	BLACK,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,

	BRIGHT_BLACK,
	BRIGHT_RED,
	BRIGHT_GREEN,
	BRIGHT_YELLOW,
	BRIGHT_BLUE,
	BRIGHT_MAGENTA,
	BRIGHT_CYAN,
	BRIGHT_WHITE,
};

inline std::string color_code(LogColor color) {
	using namespace std::string_literals;
	switch (color) {
		case BLACK:         return "\033[30m";
		case RED:           return "\033[31m";
		case GREEN:         return "\033[32m";
		case YELLOW:        return "\033[33m";
		case BLUE:          return "\033[34m";
		case MAGENTA:       return "\033[35m";
		case CYAN:          return "\033[36m";
		case WHITE:         return "\033[37m";

		case BRIGHT_BLACK:   return "\033[90m";
		case BRIGHT_RED:     return "\033[91m";
		case BRIGHT_GREEN:   return "\033[92m";
		case BRIGHT_YELLOW:  return "\033[93m";
		case BRIGHT_BLUE:    return "\033[94m";
		case BRIGHT_MAGENTA: return "\033[95m";
		case BRIGHT_CYAN:    return "\033[96m";
		case BRIGHT_WHITE:   return "\033[97m";

		case DEFAULT:
		default:            return "\033[0m";
	}
}

inline std::string level_name(LogLevel level) {
	switch (level) {
		case INFO: 	 return "INFO";
		case WARNING: 	 return "WARNING";
		case ERROR:  return "ERROR";
		case DEBUG:  return "DEBUG";
		case OK:     return "OK";
		case FAILED: return "FAILED";
		default: 		 return "LOG";
	}
}

struct LogFormat {
	LogLevel level;
	LogColor color;
	bool bold = false;
	bool italic = false;
	bool underline = false;
};

} // namespace logger::format

namespace logger {

	const format::LogFormat DEV_INFO = format::LogFormat{format::INFO, format::BRIGHT_BLACK, true, false, false};
	const format::LogFormat INFO     = format::LogFormat{format::INFO, format::BRIGHT_BLUE, true, false, false};
	const format::LogFormat WARNING	 = format::LogFormat{format::WARNING, format::BRIGHT_YELLOW, true, false, false};
	const format::LogFormat DEBUG    = format::LogFormat{format::DEBUG, format::BRIGHT_GREEN, true, false, false};
	const format::LogFormat ERROR    = format::LogFormat{format::ERROR, format::BRIGHT_RED, true, false, false};
	const format::LogFormat OK       = format::LogFormat{format::OK, format::BRIGHT_GREEN, true, false, false};
	const format::LogFormat FAILED   = format::LogFormat{format::FAILED, format::BRIGHT_RED, true, false, false};
	// default format for logging without any specific style
	const format::LogFormat DEFAULT  = INFO;

class Logger {
private:
	std::ofstream log_file;

public:
	Logger() {};
	void init(const std::string& log_path = "");
	void log(const std::string& message, logger::format::LogFormat format = DEFAULT);
	std::ostream& stream();  // optional: only refers to file stream
};

extern Logger logger_default;

void init(const std::string& log_path = "");

} // namespace logger

namespace logger::log {
	inline void LOG(const std::string& msg)  			{ logger::logger_default.log(msg, logger::DEV_INFO); }
	inline void INFO(const std::string& msg)      { logger::logger_default.log(msg, logger::INFO); }
	inline void WARNING(const std::string& msg)		{ logger::logger_default.log(msg, logger::WARNING); }
	inline void DEBUG(const std::string& msg)     { logger::logger_default.log(msg, logger::DEBUG); }
	inline void ERROR(const std::string& msg)     { logger::logger_default.log(msg, logger::ERROR); }
	inline void OK(const std::string& msg)      	{ logger::logger_default.log(msg, logger::OK); }
	inline void FAILED(const std::string& msg)		{ logger::logger_default.log(msg, logger::FAILED); }
} // namespace logger::log
