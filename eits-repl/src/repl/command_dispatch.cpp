#include "command_dispatch.h"
#include "editor/editor.h"
#include "history/history.h"
#include "../registry/registry.h"

#include <HoTT/HoTT.h>
#include <logger.h>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace logger::log;

// Reference to the global engine instance
extern EITS::Engine engine;

// Flag to prevent recursive editor invocation
static bool isEditing = false;

// Dispatch a single-line REPL command
bool dispatchCommand(const std::string& line, HistoryManager& history) {
	if (line.empty()) return false;

	// Split command and argument
	std::istringstream iss(line);
	std::string command;
	iss >> command;

	std::string args;
	std::getline(iss, args);

	// Trim leading whitespace from argument
	size_t first = args.find_first_not_of(" \t");
	if (first != std::string::npos)
		args = args.substr(first);
	else
		args.clear();

	// Lazy initialization: register all external commands once
	static bool initialized = false;
	if (!initialized) {
		registerBuiltinCommands();
		initialized = true;
	}

	// Special handling for the "edit" command (uses local state)
	if (command == "edit") {
		if (isEditing) {
			std::cout << "[Error] Nested editor invocation is not allowed.\n";
			return false;
		}
		isEditing = true;
		std::cout << "[Launching editor...]\n";
		auto result = launchEditor();
		isEditing = false;

		if (!result.has_value()) {
			std::cout << "[Editor cancelled.]\n";
			return false;
		}

		std::cout << "[Editor done.]\n";
		dispatchCommand(result.value(), history);
		return false;
	}

	// Lookup and execute registered command
	auto& table = getCommandTable();
	auto it = table.find(command);
	if (it != table.end()) {
		it->second(args, history);
	} else {
		std::cout << "[Unknown command] Try 'help'\n";
	}
	return false;
}

// Dispatch multiple REPL commands (e.g., from editor)
bool dispatchCommand(const std::vector<std::string>& lines, HistoryManager& history) {
	bool shouldExit = false;
	for (const auto& line : lines) {
		if (dispatchCommand(line, history)) {
			shouldExit = true;
		}
	}
	return shouldExit;
}
