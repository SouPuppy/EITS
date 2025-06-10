#include "history.h"

void HistoryManager::add(std::string cmd, std::string expr) {
	histories.push_back(HistoryLine{.id = next_id, .command = cmd, .expr = expr});
	next_id++;
}
