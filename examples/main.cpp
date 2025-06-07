// #include <iostream>

#include "Machinish/kernel/syntax/expression/expression.h"
#include "Machinish/kernel/syntax/expression/variable.h"
#include <logger.h>
#include <Machinish/Machinish.h>

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
