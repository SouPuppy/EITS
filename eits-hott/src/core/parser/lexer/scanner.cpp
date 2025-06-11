#include "HoTT/core/parser/lexer/scanner.h"
#include <logger.h>
#include <string>
#include "utf8_decoder.h"

using namespace logger::log;

namespace EITS {

Scanner::Scanner(const std::string& input) {
	DEBUG("Scanner [string]") << input;
	buffer = decode_utf8(input);
}

void Scanner::skipWhitespace() {
	while (!isAtEnd()) {
		char32_t c = peek();
		if (c == U'\n' || c == U'\t' || c == U' ') {
			advance();
		}	
		else { break; }
	}
}

char32_t Scanner::peek() const {
	if (pos >= buffer.size()) return U'\0';
	return buffer[pos];
}

char32_t Scanner::advance() {
	if (pos >= buffer.size()) return U'\0';

	char32_t c = buffer[pos++];
	if (c == U'\n') ++line;
	return c;
}

bool Scanner::isAtEnd() const {
	return pos >= buffer.size();
}

} // namespace EITS
