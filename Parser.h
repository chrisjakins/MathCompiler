#pragma once

#include "Expression.h"

namespace MC {

class Parser {
private:
    using ASTNode = Expression;

public:
    Parser();

    int parse(ASTNode **head);

private:
    using Operator = int;

    ASTNode *head;

    int parseOperator(Operator *oper);
    int parseExpression(Expression **expr);
};

} // ns MC
