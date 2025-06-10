#include "command_dispatch.h"
#include "editor/editor.h"
#include "history/history.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <functional>

#include <HoTT/HoTT.h>

#include <logger.h>
using namespace logger::log;

// Reference to the global engine instance
extern EITS::Engine engine;

// Define command handler type
using CommandFunc = std::function<void(const std::string& args, HistoryManager&)>;

// Static flag to prevent nested editor invocation
static bool isEditing = false;

// Command dispatch table mapping command names to handlers
static std::unordered_map<std::string, CommandFunc> commandTable = {
	{"history", [](const std::string& arg, HistoryManager& history) {
		int n = 10;

		// Check if the argument is a numeric string
		if (!arg.empty()) {
			bool valid = std::all_of(arg.begin(), arg.end(), ::isdigit);
			if (valid) {
				n = std::stoi(arg);
				if (n <= 0) {
					std::cout << "[Error] Please enter a positive number.\n";
					return;
				}
			} else {
				std::cout << "[Error] Invalid argument. Please enter a number, e.g., history 5\n";
				return;
			}
		}

		history.dump(n);
		history.add(CommandType::History, "history" + (arg.empty() ? "" : " " + arg));
	}},
	
	// Launch the multi-line editor, preventing recursive calls
	{"edit", [](const std::string&, HistoryManager& history) {
		if (isEditing) {
			std::cout << "[Error] Nested editor invocation is not allowed.\n";
			return;
		}
		isEditing = true;

		std::cout << "[Launching editor...]\n";
		auto result = launchEditor();

		isEditing = false;

		if (!result.has_value()) {
			std::cout << "[Editor cancelled.]\n";
			return;
		}

		// Dispatch each line in the editor result
		std::cout << "[Editor done.]\n";
		dispatchCommand(result.value(), history);
	}},

	// Print available commands with formatted output
	{"help", [](const std::string&, HistoryManager&) {
		std::cout << "\n\033[1mAvailable commands:\033[0m\n\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "eval"    << "\033[0m <expr>          Evaluate expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "type"    << "\033[0m <expr>          Show type of expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "define"  << "\033[0m <name> <expr>   Define a named term\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "context" << "\033[0m                 Show current context\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "reset"   << "\033[0m                 Clear all definitions\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "edit"    << "\033[0m                 Launch multi-line editor\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "help"    << "\033[0m                 Show this help message\n";
		std::cout << "\n";
	}},

	// Exit REPL
	{"exit", [](const std::string&, HistoryManager& history) {
		exit(0);
	}}
};

// Single-line command dispatcher
bool dispatchCommand(const std::string& line, HistoryManager& history) {
	if (line.empty()) return false;

	std::istringstream iss(line);
	std::string command;
	iss >> command;

	std::string args;
	std::getline(iss, args);

	// Trim leading whitespace from arguments
	size_t first = args.find_first_not_of(" \t");
	if (first != std::string::npos) {
		args = args.substr(first);
	} else {
		args.clear();
	}

	// Prevent nested 'edit' inside editor input
	if (isEditing && command == "edit") {
		std::cout << "[Warning] Nested 'edit' call ignored inside editor.\n";
		return false;
	}

	// Lookup and execute the command handler
	auto it = commandTable.find(command);
	if (it != commandTable.end()) {
		it->second(args, history);
		return false;
	} else {
		std::cout << "[Unknown command] Try 'help'\n";
		return false;
	}
}

// Multi-line command dispatcher (e.g., for editor input)
bool dispatchCommand(const std::vector<std::string>& lines, HistoryManager& history) {
	bool shouldExit = false;
	for (const auto& line : lines) {
		if (dispatchCommand(line, history)) {
			shouldExit = true;
		}
	}
	return shouldExit;
}
