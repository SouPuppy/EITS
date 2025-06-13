// registry/builtin/history.cpp

#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/core/syntax/expression/term/constant.h"
#include "registry/registry.h"

#include <HoTT/HoTT.h>

#include "common.h"

#include <logger.h>
#include <memory>

using namespace logger::log;

void registerDefCommand() {
	registerCommand("def", [](const std::string& arg, HistoryManager& history) {
		if (arg.empty()) {
			ERROR("def no arg");
			return ;
		}
		
		EITS::Lexer lexer(arg);
		EITS::Parser parser(lexer);
		auto expr = parser.parse_annotated(runtime.ctx);
		auto wrapped = std::make_shared<EITS::Expression>(
			std::make_shared<EITS::Constant>(expr->name, expr->type)
		);
		runtime.add_bind(expr->name, wrapped);

		history.add("def ", arg);
	});
}
