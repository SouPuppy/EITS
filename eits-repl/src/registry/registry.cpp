// command/registry.cpp
#include "registry.h"

static std::unordered_map<std::string, CommandFunc> commandTable;

void registerCommand(const std::string& name, CommandFunc func) {
	commandTable[name] = std::move(func);
}

std::unordered_map<std::string, CommandFunc>& getCommandTable() {
	return commandTable;
}

void registerHistoryCommand();
void registerClearCommand();
void registerHelpCommand();
void registerExitCommand();

void registerBuiltinCommands() {
	registerClearCommand();
	registerHistoryCommand();
	registerHelpCommand();
	registerExitCommand();
}
