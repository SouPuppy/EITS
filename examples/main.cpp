#include <Machinish/Machinish.h>

#include <logger.h>
#include <memory>

using namespace std;
using namespace Machinish;
using namespace logger::log;

Runtime runtime;

int main() {
	runtime.init();

	Expression A = make_shared<Type>(Level(0));

	// Variable a("a", A);
	Variable a;
	a.dump();

	LOG("a is free?") << a.is_free();

	Context ctx;

	ctx.add("a1", make_shared<Type>(1));
	ctx.add("a2", make_shared<Type>(2));
	ctx.extend();
	ctx.add("a3", make_shared<Type>(3));

	// ctx = ctx.extend("a3", make_shared<Type>(0));
	ctx.dump();
	ctx.lookup("a1");
	ctx.lookup("a2");
	ctx.lookup("a3");
/*
	#def e1 : (λx. x) y

	---
	#type e1 :
	Π x : A, A

	#context
	Γ = {
		y : A,
		A : Type
	}
*/
/*
	#def e2 : fst ⟨x, y⟩

	---
	#type e2 :
	A

	#context
	Γ = {
		x : A,
		y : B x,
		A : Type,
		B : A → Type
	}
*/
/*
	#def e3 : snd ⟨x, y⟩

	---
	#type e3 :
	B x

	#context
	Γ = {
		x : A,
		y : B x,
		A : Type,
		B : A → Type
	}
*/
/*
	#def e4 : (λf. f z) (λx. x)

	---
	#type e4 :
	A

	#context
	Γ = {
		z : A,
		A : Type
	}
*/
/*
	#def e5 : λx. ⟨x, x⟩

	---
	#type e5 :
	Π x : A, Σ y : A, A

	#context
	Γ = {
		A : Type
	}
*/
/*
	#def e6 : ⟨x, x⟩

	---
	#type e6 :
	Σ y : A, A

	#context
	Γ = {
		x : A,
		A : Type
	}
*/

	return 0;
}
