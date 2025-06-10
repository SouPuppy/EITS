#include "repl/command_dispatch.h"
#include "history/history.h"
#include <HoTT/HoTT.h>
#include <iostream>
#include <string>

#include <logger.h>
using namespace logger::log;

// Global runtime and history instances
EITS::Runtime runtime;
HistoryManager history;

// Main REPL loop
void runREPL() {
	std::string line;
	while (true) {
		std::cout << "In[" << history.get_next_id() << "]: ";
		if (!std::getline(std::cin, line)) {
			std::cout << std::endl;
			break;
		}
		if (dispatchCommand(line, history)) {
			break;
		}
	}
}

int main(int argc, char* argv[]) {
	runtime.init();
	runREPL();
	return 0;
}
