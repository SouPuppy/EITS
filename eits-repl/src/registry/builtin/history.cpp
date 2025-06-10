// command/builtin/history.cpp
#include "registry/registry.h"

void registerHistoryCommand() {
	registerCommand("history", [](const std::string& arg, HistoryManager& history) {
		int n = 10;
		if (!arg.empty()) {
			bool valid = std::all_of(arg.begin(), arg.end(), ::isdigit);
			if (valid) {
				n = std::stoi(arg);
				if (n <= 0) {
					std::cout << "[Error] Please enter a positive number.\n";
					return;
				}
			} else {
				std::cout << "[Error] Invalid argument. Use: history 5\n";
				return;
			}
		}
		history.dump(n);
		history.add(CommandType::History, "history" + (arg.empty() ? "" : " " + arg));
	});
}
