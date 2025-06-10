#include "repl/command_dispatch.h"
#include "history/history.h"
#include <HoTT/HoTT.h>
#include <string>

#include "editor/editor.h"

#include <logger.h>
using namespace logger::log;

// Global runtime and history instances
EITS::Runtime runtime;
HistoryManager history;

void runREPL() {
	while (true) {
		auto result = launchSingleLineEditor(history.get_next_id());
		if (!result.has_value()) break;
		std::string& line = *result;
		if (dispatchCommand(line, history)) break;
	}
}

int main(int argc, char* argv[]) {
	runtime.init();
	runREPL();
	return 0;
}
