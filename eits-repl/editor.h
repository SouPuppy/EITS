#pragma once

#include <string>
#include <vector>
#include <optional>

// Launch the terminal-based multi-line editor.
// Returns user input as a list of strings, one for each line.
std::optional<std::vector<std::string>> launchEditor();
