// registry/builtin/load.cpp

#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include "common.h"

#include <logger.h>

using namespace logger::log;

void registerLoadCommand() {
	registerCommand("load", [](const std::string& arg, HistoryManager& history) {
		DEBUG("Loading ...");
	});
}
