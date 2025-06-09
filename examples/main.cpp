#include <HoTT/HoTT.h>

#include <logger.h>
#include <memory>

using namespace std;
using namespace EITS;
using namespace logger::log;

Runtime runtime;

int main() {
	runtime.init();
	Expression A = std::make_shared<Constant>("A", std::make_shared<Type>(0));
	// DEBUG("A: " + A.to_string());
	// Expression y = std::make_shared<Variable>("y", A);
	// DEBUG("y: " + y.to_string());
	//
	// {
	// 	auto x = std::make_shared<Variable>("x", A);
	// 	DEBUG("x: " + x.to_string());
	//
	// 	Expression exp =
	// 		Lambda(Binder("x", A), );
	// 	DEBUG("exp: " + exp.to_string());
	// }
/*
	#def e1 (:=) (λx : A. x) y : A

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
