#include "history.h"

void HistoryManager::add(CommandType cmd, std::string expr) {
	histories.push_back(HistoryLine{.id = next_id, .cmd_type = cmd, .expr = expr});
	next_id++;
}
