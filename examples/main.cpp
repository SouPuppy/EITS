// #include <iostream>

#include <logger.h>
#include <Machinish/Machinish.h>
#include <memory>

using namespace std;
using namespace Machinish;

Runtime runtime;

int main() {
	logger::init("log/example.log");

	runtime.init();
	Term a;
	Type tp;
	Universe u;
	Variable v;
	Binder b("o", std::make_shared<Type>(tp));

	// a.dump();
	// tp.dump();
	// u.dump();
	// v.dump();
	// b.dump();

	// Binder b(std::make_shared<Universe>(u), std::make_shared<Type>(tp));

	runtime.execute(Instruction::Save);

	// runtime.ctx.add("u", std::make_shared<Universe>(u));
//FIXME - add exclusive rule for Global Context Δ
	// runtime.ctx.add("v", std::make_shared<Variable>(v));
	// runtime.ctx.add("v", std::make_shared<Type>(tp));
	// runtime.ctx.add("t", std::make_shared<Type>(tp));

	// runtime.execute(Instruction::Dump);
// 
	// runtime.execute(Instruction::Reset);

	// runtime.ctx.add("v", std::make_shared<Variable>(v));

	// runtime.execute(Instruction::Dump);

	// if (auto expr = runtime.ctx.lookup("a")) {
	// 	cout << "Found a: ";
	// 	(*expr)->print();
	// 	cout << "\n";
	// } else {
	// 	cout << "v not found\n";
	// }

	// if (auto expr = runtime.ctx.lookup("v")) {
	// 	cout << "Found v: ";
	// 	(*expr)->print();
	// 	cout << "\n";
	// } else {
	// 	cout << "v not found\n";
	// }

	// Pi pi(b, std::make_shared<Universe>(u));
	// pi.dump();
	// pi.print(); cout << "\n";
	
	// Lambda lam(b, std::make_shared<Universe>(u));
	// lam.dump();
	// lam.print(); cout << "\n";
	

	// f : Π x : Nat, Nat
	// f := λ x : Nat, x + 1


	return 0;
}
