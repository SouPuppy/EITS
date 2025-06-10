#pragma once

#include "history/history.h"
#include <string>
#include <vector>

#include "../registry/registry.h"

// Define command handler type

static std::unordered_map<std::string, CommandFunc> commandTable;

// Returns true if the command is "exit"
bool dispatchCommand(const std::vector<std::string>& lines, HistoryManager& history);
bool dispatchCommand(const std::string& line, HistoryManager& history);
