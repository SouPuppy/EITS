#pragma once

#include <string>

enum CommandType {
	Help,
	Print,
	Define,
	Exit,
};

struct History {
	int id;
	CommandType cmd_type;
	std::string expr;
};

struct HistoryManager {
	int next_id = 1;

	// add
	// void add(std::string )

};
