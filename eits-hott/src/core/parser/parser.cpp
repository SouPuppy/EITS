#include "HoTT/core/parser/parser.h"
#include <logger.h>
#include <string>

using namespace logger::log;

namespace EITS {

Parser::Parser(const std::string& source) {
	DEBUG << source;
}

} // namespace EITS
