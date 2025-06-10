// registry/builtin/history.cpp
#include "registry/registry.h"

#include <logger.h>

using namespace logger::log;

void registerDefineCommand() {
	registerCommand("def", [](const std::string& arg, HistoryManager& history) {
		DEBUG("def") << arg << ";";
		history.add("def", (arg.empty() ? "" : " " + arg));
	});
}
