// #include <iostream>

#include <Machinish/Machinish.h>

using namespace std;
using namespace Machinish;

Runtime runtime;

int main() {
	runtime.init();
	Term a;
	a.dump();
	Type b;
	b.dump();
	Universe u;
	u.dump();
	return 0;
}
