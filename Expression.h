#pragma once

namespace MC {

struct Expression {
private:
    using Operator = int;

public:
    Expression *left_, *right_;
    char type_;
    int value_;
    Operator *oper_;
};

} // ns MC
