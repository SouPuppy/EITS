// #include <iostream>

#include "Machinish/kernel/syntax/binder.h"
#include "Machinish/kernel/syntax/expression/universe.h"
#include <Machinish/Machinish.h>

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

	Binder b(std::make_shared<Universe>(u), std::make_shared<Type>(tp));
	b.dump();

	cout << b.to_string() << endl;
	runtime.execute(Instruction::Save);
	return 0;
}
