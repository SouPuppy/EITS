#include "HoTT/core/error/engine_error.h"

namespace EITS::Error {

std::string kind_to_string(Kind kind) {
	switch (kind) {
		case Kind::Parse:   return "[Parse Error]";
		case Kind::Type:    return "[Type Error]";
		case Kind::Runtime: return "[Runtime Error]";
		case Kind::Unknown: return "[Unknown Error]";
		default:            return "[Invalid Error]";
	}
}

std::string EngineError::to_string() const {
	return kind_to_string(kind) + " " + message;
}

} // namespace EITS::Error
