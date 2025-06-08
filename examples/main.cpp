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

	// A : Type_0
	Expression A = make_shared<Type>(Level(0));
	LOG("A   - " + A.to_string());

	// B : Type_0
	Expression B = make_shared<Type>(Level(0));
	LOG("B   - " + B.to_string());

	// a:A
	Binder a = Binder("a", A);
	LOG("a:A - " + a.to_string());

	// _:A
	Binder _ = Binder("_", A);
	LOG("_:A - " + _.to_string());

	// Pi x:A. B
	Expression e1 = make_shared<Pi>(Binder("x", A), B);
	LOG("Pi x:A. B - " + e1.to_string());

	// Sigma x:A. B
	Expression e2 = make_shared<Sigma>(Binder("x", A), B);
	LOG("Sigma x:A. B - " + e2.to_string());

	// runtime.add_bind("A", A);
	// runtime.execute(Instruction::Dump);
	
	// Id A a b
	Expression e3 = make_shared<Id>(A, a.type, a.type);
	LOG("Id A a a - " + e3.to_string());

	return 0;
}
