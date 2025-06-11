// registry/builtin/history.cpp

#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include <logger.h>

using namespace logger::log;

void registerDefCommand() {
	registerCommand("def", [](const std::string& arg, HistoryManager& history) {
		// DEBUG("def") << arg << ";";
		
		EITS::Lexer lexer(arg);
		lexer.all();

		history.add("def", (arg.empty() ? "" : " " + arg));
	});
}
