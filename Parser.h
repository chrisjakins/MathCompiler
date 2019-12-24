#pragma once

#include "Expression.h"
#include "Lexer.h"
#include "Token.h"

#include <memory>

namespace MC {

class Parser {
private:
    using ASTNode = Expression;

public:
    Parser(Lexer &lexer);

    int parseProgram(std::shared_ptr<Expression> expr);

private:
    using Operator = int;

    Lexer lexer_;

    int parseOperator(Operator &oper);
    int parseExpression(std::shared_ptr<Expression> expr);
};

} // ns MC
