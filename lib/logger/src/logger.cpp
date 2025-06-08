#include "logger.h"
#include <chrono>
#include <iomanip>
#include <iostream>

namespace logger {

std::string current_time_string() {
	auto now = std::chrono::system_clock::now();
	std::time_t t = std::chrono::system_clock::to_time_t(now);
	std::tm tm = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
	return oss.str();
}

std::string color_code(LogColor color) {
	switch (color) {
		case BLACK:         return "\033[30m";
		case RED:           return "\033[31m";
		case GREEN:         return "\033[32m";
		case YELLOW:        return "\033[33m";
		case BLUE:          return "\033[34m";
		case MAGENTA:       return "\033[35m";
		case CYAN:          return "\033[36m";
		case WHITE:         return "\033[37m";
		case BRIGHT_BLACK:  return "\033[90m";
		case BRIGHT_RED:    return "\033[91m";
		case BRIGHT_GREEN:  return "\033[92m";
		case BRIGHT_YELLOW: return "\033[93m";
		case BRIGHT_BLUE:   return "\033[94m";
		case BRIGHT_MAGENTA:return "\033[95m";
		case BRIGHT_CYAN:   return "\033[96m";
		case BRIGHT_WHITE:  return "\033[97m";
		case DEFAULT:
		default:            return "\033[0m";
	}
}

Format::Format(LogColor color, bool bold, bool italic, bool underlined)
	: color(color), bold(bold), italic(italic), underlined(underlined) {}

std::string Format::polish(const std::string& str) const {
	std::string res = str;
	if (bold) res = "\033[1m" + res;
	if (italic) res = "\033[3m" + res;
	if (underlined) res = "\033[4m" + res;
	if (color != DEFAULT) res = color_code(color) + res + color_code(DEFAULT);
	return res;
}

LogStream::LogStream(std::string header, Format format, std::string title, std::shared_ptr<std::ofstream> out)
	: header(std::move(header)), format(std::move(format)), title(std::move(title)), file_out(std::move(out)) {}

LogStream::~LogStream() {
	if (header.empty() && title.empty() && buffer.str().empty())
		return;

	std::string timestamp = current_time_string();
	std::string log_output = "[" + timestamp + "][" + header + "] " + title + "\n" + buffer.str();

	std::cout << "[" << format.polish(header) << "] " << title << "\n";
	std::cout << buffer.str();
	if (has_payload) std::cout << std::endl;

	if (file_out && file_out->is_open()) {
		*file_out << log_output;
		file_out->flush();
	}
}

LogFactory::LogFactory(std::string h, Format f)
	: header(std::move(h)), format(std::move(f)) {}

void LogFactory::init(const std::filesystem::path& log_path_obj) {
	auto parent = log_path_obj.parent_path();
	if (!parent.empty()) std::filesystem::create_directories(parent);
	log_file->open(log_path_obj, std::ios::out | std::ios::app);
}

LogStream LogFactory::operator()(const std::string& title) const {
	return LogStream(header, format, title, log_file);
}


void init(const std::string& log_path) {
	std::string path_str = log_path.empty()
		? ("log/" + current_time_string() + ".log")
		: log_path;

	std::filesystem::path abs_path = std::filesystem::absolute(path_str);
	std::cout << "Log file initialized at: " << abs_path << std::endl;
	std::filesystem::create_directories(abs_path.parent_path());

	log::LOG.init(abs_path);
	log::INFO.init(abs_path);
	log::WARNING.init(abs_path);
	log::DEBUG.init(abs_path);
	log::ERROR.init(abs_path);
	log::OK.init(abs_path);
	log::FAILED.init(abs_path);
}

} // namespace logger

namespace logger::log {

LogFactory LOG    ("LOG",    Format(BRIGHT_BLACK,   true, false, false));
LogFactory INFO   ("INFO",   Format(BRIGHT_BLUE,    true, false, false));
LogFactory WARNING("WARN",   Format(BRIGHT_YELLOW,  true, false, false));
LogFactory DEBUG  ("DEBUG",  Format(BRIGHT_GREEN,   true, false, false));
LogFactory ERROR  ("ERROR",  Format(BRIGHT_RED,     true, false, false));
LogFactory OK     ("OK",     Format(BRIGHT_GREEN,   true, false, false));
LogFactory FAILED ("FAILED", Format(BRIGHT_RED,     true, true,  false));

} // namespace logger::log
