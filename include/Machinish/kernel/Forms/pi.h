// include/Machinish/kernel/Forms/pi.h

#pragma once

#include <cassert>
#include <memory>
#include <string>

#include <Machinish/common.h>
#include <Machinish/kernel/term.h>
#include <Machinish/kernel/Forms/typed_variable.h>

namespace Machinish {

struct Type_Pi : Type_Base {
	Type binder;
	Type codomain;

	Type_Pi(Type binder, Type codomain)
		: binder(std::move(binder)), codomain(std::move(codomain)) {}
	
	std::string to_string() const override {
#ifdef MACHINISH_ENABLE_DEBUG
		return "(Pi) Π (" + binder->to_string() + ") → " + codomain->to_string();
#else
		return "Π (" + binder->to_string() + ") → " + codomain->to_string();
#endif
	}
};

using Pi = std::shared_ptr<Type_Pi>;
inline Type makePi(const Type& binder, const Type& codomain) {
// NOTE - Not ideal, but safe in practice as users are not expected to call makePi directly.
//        This method is intended to be used internally by higher-level constructors.

	assert(std::dynamic_pointer_cast<Type_TypedVariable>(binder) && "makePi: binder must be a TypedVariable");
	return std::make_shared<Type_Pi>(binder, codomain);
}

} // namespace Machinish
