#include "logger.h"
#include "config.h"

#include <fstream>
#include <filesystem>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

inline std::string polish(const std::string& str, const logger::format::LogFormat& format) {
	std::string style;

	if (format.bold)       style += "\033[1m";
	if (format.italic)     style += "\033[3m";
	if (format.underline)  style += "\033[4m";

	style += logger::format::color_code(format.color);

	return style + str + "\033[0m";
}

namespace logger {

Logger logger_default;

std::string current_time_string() {
	auto now = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(now);
	std::tm tm = *std::localtime(&t);
	
	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
	return oss.str();
}

void Logger::init(const std::string& log_path) {
	std::string path_str = log_path.empty()
		? ("./log/" + current_time_string() + ".log")
		: log_path;

	std::filesystem::path log_path_obj(path_str);
	auto parent = log_path_obj.parent_path();
	if (!parent.empty()) {
		std::filesystem::create_directories(parent);
	}

	log_file.open(path_str, std::ios::out | std::ios::app);

	std::filesystem::path abs_path = std::filesystem::absolute(log_path_obj);
#ifdef ENABLE_LOG_VERBOSE
	std::cout << "[" + polish("Initialize", DEFAULT) + "] " + abs_path.string() + "\n";
#endif
}

void Logger::log(const std::string& message, logger::format::LogFormat format) {
	std::string timestamp = current_time_string();
	std::string level_str = format::level_name(format.level);
	std::string plain_prefix = "[" + timestamp + "] [" + level_str + "] ";

#ifdef ENABLE_LOG_VERBOSE
	std::string styled_prefix = "[" + polish(level_str, format) + "]";
	std::cout << styled_prefix << " " << message << std::endl;
#endif

	log_file << plain_prefix << message << std::endl;
	log_file.flush();
}

std::ostream& Logger::stream() {
	return log_file;
}

void init(const std::string& log_path) {
	logger_default.init(log_path);
}

} // namespace logger
