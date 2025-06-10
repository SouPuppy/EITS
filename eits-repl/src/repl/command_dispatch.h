#pragma once
#include <string>
class History;

// Returns true if the command is "exit"
bool dispatchCommand(const std::string& line, History& history);
