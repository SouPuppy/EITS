// registry/registry.cpp
#include "registry.h"

static std::unordered_map<std::string, CommandFunc> commandTable;

void registerCommand(const std::string& name, CommandFunc func) {
	commandTable[name] = std::move(func);
}

std::unordered_map<std::string, CommandFunc>& getCommandTable() {
	return commandTable;
}

void registerSaveCommand();
void registerLoadCommand();

void registerDefCommand();
void registerTypeCommand();
void registerEvalCommand();
void registerContextCommand();

void registerHistoryCommand();
void registerClearCommand();
void registerHelpCommand();
void registerExitCommand();

void registerBuiltinCommands() {
	registerSaveCommand();
	registerLoadCommand();

	registerDefCommand();
	registerTypeCommand();
	registerEvalCommand();
	registerContextCommand();

	registerClearCommand();
	registerHistoryCommand();
	registerHelpCommand();
	registerExitCommand();
}
