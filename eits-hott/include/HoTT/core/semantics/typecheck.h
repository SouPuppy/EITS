#pragma once

#include <memory>
#include "HoTT/core/syntax/expression/type.h"
#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/core/semantics/context.h"
#include <functional>
#include <unordered_map>
#include <typeindex>

namespace EITS {

using TypecheckFn = std::function<std::shared_ptr<Type>(std::shared_ptr<Expression>, const Context&)>;

struct TypecheckRegistry {
	
	static TypecheckRegistry& instance();

	void register_handler(std::type_index type, TypecheckFn fn);

	std::shared_ptr<Type> dispatch(std::shared_ptr<Expression> expr, const Context& ctx);

	std::unordered_map<std::type_index, TypecheckFn> handlers;
};

} // namespace EITS
