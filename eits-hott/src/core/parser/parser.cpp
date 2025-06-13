#include "HoTT/core/parser/parser.h"
#include "HoTT/core/parser/lexer/token.h"
#include "HoTT/core/syntax/expression/expression.h"
#include "HoTT/core/syntax/expression/type.h"
#include "HoTT/core/syntax/expression/term/constant.h"
#include "HoTT/core/syntax/expression/term/variable.h"
#include <logger.h>
#include <memory>
#include <string>
#include "utf8_decoder.h"

using namespace logger::log;

namespace EITS {

Parser::Parser(Lexer& lexer) {
	tokens = lexer.all();
}

std::shared_ptr<Expression> Parser::parse_expr(const Context& ctx) {
	if (match(TokenType::TYPE)) {
		return std::make_shared<Expression>(parse_type(ctx));
	} else if (match(TokenType::IDENTIFIER)) {
		auto name = to_utf8(expect(TokenType::IDENTIFIER).lexme);
		return std::make_shared<Expression>(
			std::make_shared<Variable>(name)
		);
	} else {
		throw std::runtime_error("Invalid expression syntax");
	}
}

std::shared_ptr<Type> Parser::parse_type(const Context& ctx) {
	expect(TokenType::TYPE);
	int level = 0;
	if (match(TokenType::NUMBER)) {
		level = std::stoi(to_utf8(consume().lexme));
	}
	return std::make_shared<Type>(level);
}

std::shared_ptr<Type> typecheck(const Expression& expr, const Context& ctx) {
	DEBUG << "[typecheck] expr: " << expr.to_string();

	return std::visit([&](auto&& ptr) -> std::shared_ptr<Type> {
		using T = std::decay_t<decltype(*ptr)>;

		// ====== Type: Type u : Type (u + 1) ======
		if constexpr (std::is_same_v<T, Type>) {
			return std::make_shared<Type>(Level::succ(ptr->level));
		}

		// ====== Term 子类 ======
		else if constexpr (std::is_base_of_v<Term, T>) {
			// Free variable
			if (auto var = std::dynamic_pointer_cast<Variable>(ptr)) {
				if (var->is_free()) {
					auto binding = ctx.lookup(var->name);
if (!binding) throw std::runtime_error("Unbound variable: " + var->name);

return std::visit([&](auto&& inner_ptr) -> std::shared_ptr<Type> {
	using InnerT = std::decay_t<decltype(*inner_ptr)>;
	if constexpr (std::is_same_v<InnerT, Type>) {
		return std::dynamic_pointer_cast<Type>(inner_ptr);
	} else {
		throw std::runtime_error("[typecheck] Variable bound to non-Type: " + std::string(typeid(InnerT).name()));
	}
}, static_cast<const ExpressionVariant&>(**binding));
				} else {
					auto& bound = std::get<BoundVariable>(var->value);
					return typecheck(bound.type, ctx);
				}
			}

			// Constant
			else if (auto cst = std::dynamic_pointer_cast<Constant>(ptr)) {
				return typecheck(Expression(cst->type), ctx);
			}

			else {
				throw std::runtime_error("[typecheck] Unknown Term subtype: " + ptr->to_string());
			}
		}

		else {
			throw std::runtime_error("Unsupported expression kind in typecheck: " + std::string(typeid(T).name()));
		}
	}, static_cast<const ExpressionVariant&>(expr));
}

std::shared_ptr<Constant> Parser::parse_annotated(const Context& ctx) {
	std::string name = to_utf8(expect(TokenType::IDENTIFIER).lexme);
	expect(TokenType::COLON);
	std::shared_ptr<Expression> type_expr = parse_expr(ctx);
	std::shared_ptr<Type> inferred_type = typecheck(*type_expr, ctx);
	return std::make_shared<Constant>(name, inferred_type);
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
