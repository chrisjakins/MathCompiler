#pragma once

#include "Token.h"
#include <string>

namespace MC {

class Lexer {
public:
    Lexer(std::string sourceCode);

    Token getNextToken();

private:
    bool isLayoutChar(int ch);
    int getchar();

    int index;
    std::string sourceCode_;
};

} // ns MC
