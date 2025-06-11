// include/HoTT/core/parser/parser.h

#pragma once

#include "HoTT/core/parser/lexer/token.h"
#include "HoTT/core/parser/lexer/lexer.h"

#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/HoTT.h"
#include <vector>

namespace EITS {

struct Parser {
	explicit Parser(Lexer& lexer);
	size_t index = 0;
	std::vector<Token> tokens;

	std::shared_ptr<Expression> parse_expr();
	std::shared_ptr<Type> parse_type();
	std::shared_ptr<Constant> parse_annotated();
	
	Token peek(int offset = 0) const;
	Token consume();
	bool match(TokenType type) const;
	Token expect(TokenType type);
};

} // namespace EITS
