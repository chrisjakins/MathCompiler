#pragma once

#include <memory>

namespace MC {

struct Expression {
private:
    using Operator = int;

public:
    std::shared_ptr<Expression> left_, right_;
    char type_;
    int value_;
    Operator oper_;
};

} // ns MC
