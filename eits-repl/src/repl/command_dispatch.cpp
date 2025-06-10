#include "command_dispatch.h"
#include "editor/editor.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>

#include <HoTT/HoTT.h>

extern EITS::Engine engine;

using CommandFunc = std::function<void(const std::string& args, History&)>;

static std::unordered_map<std::string, CommandFunc> commandTable = {
	{"help", [](const std::string&, History&) {
		std::cout << "  \033[1mAvailable commands:\033[0m\n\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "eval"    << "\033[0m <expr>          Evaluate expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "type"    << "\033[0m <expr>          Show type of expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "define"  << "\033[0m <name> <expr>   Define a named term\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "context" << "\033[0m                 Show current context\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "reset"   << "\033[0m                 Clear all definitions\n";
		std::cout << "  \033[36m" << std::left << std::setw(10) << "help"    << "\033[0m                 Show this help message\n";
	}}
};

bool dispatchCommand(const std::string& line, History& history) {
	if (line.empty()) return false;

	std::istringstream iss(line);
	std::string command;
	iss >> command;

	std::string args;
	std::getline(iss, args);
	size_t first = args.find_first_not_of(" \t");
	if (first != std::string::npos) {
		args = args.substr(first);
	} else {
		args.clear();
	}

	auto it = commandTable.find(command);
	if (it != commandTable.end()) {
		it->second(args, history);
		return false;
	} else {
		std::cout << "[Unknown command] Try 'help'\n";
		return false;
	}
}
