// #include <iostream>

#include "Machinish/kernel/runtime/runtime.h"
#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/universe.h"
#include <Machinish/Machinish.h>
#include <memory>

using namespace std;
using namespace Machinish;

Runtime runtime;

int main() {
	runtime.init();
	Term a;
	a.dump();
	Type tp;
	tp.dump();
	Universe u;
	u.dump();
	Variable v;
	v.dump();

	// Binder b(std::make_shared<Universe>(u), std::make_shared<Type>(tp));
	Binder b("o", std::make_shared<Type>(tp));
	b.dump();

	cout << b.to_string() << endl;
	runtime.execute(Instruction::Save);

	runtime.ctx.add("u", std::make_shared<Universe>(u));
//FIXME - add exclusive rule for Global Context Δ
	runtime.ctx.add("v", std::make_shared<Variable>(v));
	runtime.ctx.add("v", std::make_shared<Type>(tp));
	runtime.ctx.add("t", std::make_shared<Type>(tp));

	runtime.execute(Instruction::Dump);

	runtime.execute(Instruction::Reset);

	runtime.ctx.add("v", std::make_shared<Variable>(v));

	runtime.execute(Instruction::Dump);

	if (auto expr = runtime.ctx.lookup("a")) {
		cout << "Found a: ";
		(*expr)->print();
		cout << "\n";
	} else {
		cout << "v not found\n";
	}

	if (auto expr = runtime.ctx.lookup("v")) {
		cout << "Found v: ";
		(*expr)->print();
		cout << "\n";
	} else {
		cout << "v not found\n";
	}

	return 0;
}
