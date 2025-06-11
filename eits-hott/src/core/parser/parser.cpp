#include "HoTT/core/parser/parser.h"
#include "HoTT/core/parser/lexer/token.h"
#include "HoTT/core/syntax/expression/expression.h"

#include <logger.h>
#include <memory>
#include <string>
#include "utf8_decoder.h"

using namespace logger::log;

#include "HoTT/HoTT.h"
namespace EITS {

Parser::Parser(Lexer& lexer) {
	tokens = lexer.all();
}

// std::shared_ptr<Expression> Parser::parse_expr() {
// 	//FIXME - Dummy Output
// 	Expression A = std::make_shared<Constant>("A", std::make_shared<Type>(0));
// 	return std::make_shared<Expression>(
// 		std::make_shared<Variable>("y", A)
// 	);
// }

std::shared_ptr<Type> Parser::parse_type() {
	expect(TokenType::TYPE);
	int level = 0;
	if (match(TokenType::NUMBER)) {
		level = std::stoi(to_utf8(consume().lexme));
	}
	return std::make_shared<Type>(level);
}

std::shared_ptr<Constant> Parser::parse_annotated() {
	//FIXME - lexme -> lexeme
	std::string name = to_utf8(expect(TokenType::IDENTIFIER).lexme);
	expect(TokenType::COLON);
	auto type = parse_type();
	
	return std::make_shared<Constant>(name, type);
}
	
Token Parser::peek(int offset) const {
	if (index + offset < tokens.size()) return tokens[index + offset];
	return Token(TokenType::EOF_TOKEN, U"", 1, tokens.size());
}

Token Parser::consume() { return tokens[index++]; }

bool Parser::match(TokenType type) const { return peek().type == type; }

Token Parser::expect(TokenType expected) {
	Token t = peek();
	if (t.type != expected) {
		DEBUG(
			"\nExpected token " + to_string(expected) +
			", but got " + to_string(t.type) +
			" at line " + std::to_string(t.line) +
			", column " + std::to_string(t.column)
		);
	}
	return consume();
}

} // namespace EITS
