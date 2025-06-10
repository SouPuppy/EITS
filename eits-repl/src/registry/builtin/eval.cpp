// registry/builtin/history.cpp

#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include <logger.h>

using namespace logger::log;

void registerEvalCommand() {
	registerCommand("eval", [](const std::string& arg, HistoryManager& history) {
		DEBUG("eval") << arg << ";";
		history.add("eval", (arg.empty() ? "" : " " + arg));
	});
}
