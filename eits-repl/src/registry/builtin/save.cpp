// registry/builtin/save.cpp

#include "HoTT/core/runtime/runtime.h"
#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include "common.h"

#include <logger.h>

using namespace logger::log;

void registerSaveCommand() {
	registerCommand("save", [](const std::string& arg, HistoryManager& history) {
		DEBUG("Saving ...");
		runtime.execute(EITS::Instruction::Save);
		history.add("save");
	});
}
