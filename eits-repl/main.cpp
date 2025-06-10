#include <iostream>
#include "editor.h"

int main() {
    auto result = launchEditor();
    if (!result) {
        std::cerr << "Error: Terminal height too small. Please resize your window.\n";
        return -1;
    }

    std::cout << "\nYou've Input\n";
    for (const auto& line : *result) {
        std::cout << line << '\n';
    }

    return 0;
}

