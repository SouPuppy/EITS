// #include <iostream>

#include <Machinish/Machinish.h>

#include <logger.h>

using namespace std;
using namespace Machinish;
using namespace logger::log;

Runtime runtime;

int main() {
	logger::init("log/example.log");
	runtime.init();

	Type a;

	LOG(a.to_string());

	Expression expr2 = Variable();
	LOG("expr2: " + expr2.to_string());

	return 0;
}
