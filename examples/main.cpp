#include "Machinish/kernel/Forms/typed_variable.h"
#include <iostream>

#include <Machinish/Machinish.h>

using namespace std;
using namespace Machinish;

int main() {
	Type a = makeUniverse(3);
	Type b = makeUniverse(4);
	cout << a->to_string() << "\n";
	cout << b->to_string() << "\n";

	Type c = makeTypedVariable("x", b);
	cout << c->to_string() << "\n";

	Type d = makePi(c, a);

	// cout << d->to_string() << endl;

	// cout << a->to_string() << endl;
	// cout << (a == c);
	return 0;
}
