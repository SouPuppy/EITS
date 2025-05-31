#include <iostream>
#include <Machinish/info/version.hpp>

int main() {
	std::cout << "Machinish Version: " << Machinish::Info::version() << "\n";
	return 0;
}
