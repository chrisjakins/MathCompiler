#pragma once

#include "Expression.h"

namespace MC {

class CodeGen {
public:
    CodeGen();

    static void generate(std::shared_ptr<Expression> expr);
};

} // ns MC
