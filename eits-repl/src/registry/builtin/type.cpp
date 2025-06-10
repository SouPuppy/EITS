// registry/builtin/history.cpp

#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include <logger.h>

using namespace logger::log;

void registerTypeCommand() {
	registerCommand("type", [](const std::string& arg, HistoryManager& history) {
		DEBUG("type") << arg << ";";
		history.add("type", (arg.empty() ? "" : " " + arg));
	});
}
