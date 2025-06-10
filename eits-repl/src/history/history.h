#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

// enum CommandType {
// 	// HoTT command
// 	Define,
// 	Eval,

// 	// REPL commands
// 	History,
// 	Help,
// 	Exit,
// 	Unkown,
// };

// inline std::string CommandType_to_string(const CommandType& cmd) {
// 	switch (cmd) {
// 		case CommandType::Define:		return "def";
// 		case CommandType::History:	return "history";
// 		case CommandType::Help:			return "help";
// 		case CommandType::Exit:			return "exit";
// 		default:					        	return "unknown";
// 	}
// }

struct HistoryLine {
	int id;
	// CommandType cmd_type;
	std::string command;
	std::string expr;
	// HistoryLine();
};

struct HistoryManager {
	int next_id = 1;
	std::vector<HistoryLine> histories;

	// add
	void add(std::string cmd, std::string expr = "");
	void dump(int n) {
		int dump_total = std::min<int>(n, static_cast<int>(histories.size()));
		std::cout << "\n\033[1mHistories (" << n << " recent):\033[0m\n";
		int i = 1;
		auto it = histories.rbegin();

		while (dump_total > 0 && it != histories.rend()) {
			std::cout << " ~" << i << ": " << it->command << it->expr << "\n";
			++it;
			++i;
			--dump_total;
		}
		std::cout << "\n";
	}
	int get_next_id() { return next_id; }

	// go back history
	HistoryLine previous_history(int id = 0);
};