#include "registry/registry.h"

void registerExitCommand() {
	registerCommand("exit", [](const std::string&, HistoryManager&) {
		exit(0);
	});
}
