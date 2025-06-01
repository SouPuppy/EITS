// include/Machinish/kernel/Forms/typed_variable.h
// typed variable

#pragma once

#include <string>

#include <Machinish/common.h>
#include <Machinish/kernel/term.h>

namespace Machinish {

struct Type_TypedVariable : Type_Base {
	std::string binder;
	Type annotation;

	Type_TypedVariable(std::string _binder, Type _annotation): binder(_binder), annotation(_annotation){};
	std::string to_string() const override {
#ifdef MACHINISH_ENABLE_DEBUG
		return "(Typed Variable) " + binder + ":" + annotation->to_string();
#else
		return binder + ":" + annotation->to_string();
#endif
	}
};

using TypedVariable = std::shared_ptr<Type_TypedVariable>;
inline Type makeTypedVariable(std::string binder, const Type& annotation) {
	return std::make_shared<Type_TypedVariable>(binder, annotation);
}

} // namespace Machinish
