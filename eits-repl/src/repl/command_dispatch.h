#pragma once

#include "history/history.h"
#include <string>
#include <vector>

// Returns true if the command is "exit"
bool dispatchCommand(const std::vector<std::string>& lines, HistoryManager& history);
bool dispatchCommand(const std::string& line, HistoryManager& history);
