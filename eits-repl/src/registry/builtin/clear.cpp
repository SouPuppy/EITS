#include "registry/registry.h"

void registerClearCommand() {
  registerCommand("clear", [](const std::string&, HistoryManager&) {
    std::cout << "\033[2J\033[H";
    std::cout.flush();
  });
}
