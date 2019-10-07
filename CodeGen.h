#pragma once

#include "Expression.h"

namespace MC {

class CodeGen {
public:
    CodeGen();

    void generate(Expression *expr);

private:

};

} // ns MC
