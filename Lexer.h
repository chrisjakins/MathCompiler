#pragma once

#include "Token.h"
#include <string>

namespace MC {

class Lexer {
public:
    Lexer(std::string sourceCode);

    void getNextToken();
    Token &currToken();

private:
    bool isLayoutChar(int ch);
    int getchar();

    int index;
    std::string sourceCode_;
    Token currToken_;
};

} // ns MC
