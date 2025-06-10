#pragma once

#include <string>

namespace EITS::Error {

enum class Kind { Parse, Type, Runtime, Unknown };

std::string kind_to_string(Kind kind);

struct EngineError {
	Kind kind;
	std::string message;

	std::string to_string() const;
};

} // namespace EITS::Error
