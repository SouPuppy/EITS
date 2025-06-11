#include "HoTT/core/parser/lexer/scanner.h"
#include <logger.h>
#include <string>
#include "utf8_decoder.h"

using namespace logger::log;

namespace EITS {

Scanner::Scanner(const std::string& input) {
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

char32_t Scanner::peek(size_t offset) const {
	if (pos + offset >= buffer.size()) return U'\0';
	return buffer[pos + offset];
}

char32_t Scanner::advance() {
	if (pos >= buffer.size()) return U'\0';
	
	char32_t c = buffer[pos++];
	if (c == U'\n') { ++line; column = 1; }
	else { ++column; }
	return c;
}

void Scanner::consume(size_t count) {
	for (size_t i = 0; i < count && !isAtEnd(); ++i) {
		if (buffer[pos] == U'\n') {
			++line;
			column = 1;
		} else {
			++column;
		}
		++pos;
	}
}

bool Scanner::isAtEnd() const {
	return pos >= buffer.size();
}

} // namespace EITS
