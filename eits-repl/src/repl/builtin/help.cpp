#include "repl/registry.h"
#include <iomanip>
#include <iostream>

void registerHelpCommand() {
	registerCommand("help", [](const std::string&, HistoryManager&) {
		std::cout << "\n\033[1mAvailable commands:\033[0m\n\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "eval"    << "\033[0m <expr>          Evaluate expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "type"    << "\033[0m <expr>          Show type of expression\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "define"  << "\033[0m <name> <expr>   Define a named term\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "context" << "\033[0m                 Show current context\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "reset"   << "\033[0m                 Clear all definitions\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "edit"    << "\033[0m                 Launch multi-line editor\n";
		std::cout << "  \033[36m" << std::left << std::setw(9) << "help"    << "\033[0m                 Show this help message\n";
		std::cout << "\n";
	});
}
