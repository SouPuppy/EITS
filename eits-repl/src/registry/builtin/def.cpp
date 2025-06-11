// registry/builtin/history.cpp

#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include "common.h"

#include <logger.h>

using namespace logger::log;

void registerDefCommand() {
	registerCommand("def", [](const std::string& arg, HistoryManager& history) {
		if (arg.empty()) {
			ERROR("def no arg");
			return ;
		}
		
		EITS::Lexer lexer(arg);
		EITS::Parser parser(lexer);
		auto expr = parser.parse_annotated();
		runtime.add_bind(expr->name, expr->type);
		history.add("def ", arg);
	});
}
