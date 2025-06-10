// registry/builtin/history.cpp

#include "HoTT/core/runtime/runtime.h"
#include "common.h"
#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include <logger.h>

using namespace logger::log;

void registerContextCommand() {
	registerCommand("context", [](const std::string& arg, HistoryManager& history) {
		std::cout << "\n";
		runtime.execute(EITS::Instruction::Dump);
		std::cout << "\n";
		history.add("context", (arg.empty() ? "" : " " + arg));
	});
}
