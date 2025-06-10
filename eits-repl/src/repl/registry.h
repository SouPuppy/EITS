// command/registry.h
#pragma once

#include <string>
#include <functional>
#include <unordered_map>

#include "history/history.h"

// Type alias for a REPL command handler function
using CommandFunc = std::function<void(const std::string& args, HistoryManager&)>;

// Register a single command by name
void registerCommand(const std::string& name, CommandFunc func);

// Register all built-in commands (excluding "edit", which is special-cased)
void registerBuiltinCommands();

// Access the global command dispatch table
std::unordered_map<std::string, CommandFunc>& getCommandTable();
