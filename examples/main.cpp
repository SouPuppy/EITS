// #include <iostream>

#include <Machinish/Machinish.h>

#include <logger.h>
#include <memory>

using namespace std;
using namespace Machinish;
using namespace logger::log;

Runtime runtime;

int main() {
	logger::init("log/example.log");
	runtime.init();

	// Pi A;
	// Expression expr = make_shared<Type>(A);
	// DEBUG("A " + A.to_string());

	// Binder b = Binder("x", expr);
	// DEBUG("Binder: " + b.to_string());

	// DEBUG("Level 0: " + Level(4).to_string());
	
	// LOG(Type(2).to_string());

	Pi p(make_shared<Type>(), make_shared<Type>(), make_shared<Type>());
	Sigma s(make_shared<Type>(), make_shared<Type>(), make_shared<Type>());

	DEBUG("Sigam " + s.to_string());
	DEBUG("Pi " + p.to_string());

	p.dump();

	runtime.add_def("ℕ", make_shared<Type>());
	runtime.execute(Instruction::Dump);
	//
	// LOG("Reset Runtime");
	// runtime.execute(Instruction::Reset);
	// runtime.execute(Instruction::Dump);

	// Type a;

	// LOG(a.to_string());

	// Expression expr2 = Variable();
	// Expression expr3 = Universe();

	// expr2.dump();

	// runtime.ctx.add_binding("x", expr2);
	// runtime.ctx.add_binding("x", expr2);
	// runtime.ctx.add_binding("u", expr3);

	// runtime.execute(Instruction::Dump);

	// auto f = runtime.ctx.lookup("x");
	// if (f) { f->dump(); }

	return 0;
}
