#include <HoTT/HoTT.h>

#include <logger.h>
#include "display.h"

using namespace std;
using namespace EITS;
using namespace logger::log;

Runtime runtime;

int main() {
	EITS::display::display_inference(
		{"Γ ⊢ A : Type", "Γ, x : A ⊢ B : Type"},
		"Γ ⊢ Π(x : A), B : Type"
	);

	EITS::display::display_inference(
		{"1"},
		"Γ ⊢ Π(x : A), B : Type"
	);
	return 0;
}