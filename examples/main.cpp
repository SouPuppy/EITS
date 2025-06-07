// #include <iostream>

#include "Machinish/kernel/syntax/expression/expression.h"
#include "Machinish/kernel/syntax/expression/universe.h"
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
	Expression expr3 = Universe();

	expr2.dump();

	runtime.ctx.add_binding("x", expr2);
	runtime.ctx.add_binding("x", expr2);
	runtime.ctx.add_binding("u", expr3);

	runtime.execute(Instruction::Dump);

	auto f = runtime.ctx.lookup("x");
	if (f) { f->dump(); }

	return 0;
}
