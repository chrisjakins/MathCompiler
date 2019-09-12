#include "Lexer.h"

#include <iostream>

namespace MC {

Lexer::Lexer(std::string sourceCode)
    : sourceCode_(sourceCode), index(0)
{}

Token Lexer::getNextToken() {
    Token currToken;
    int ch;

    do {
        ch = getchar();
        if (ch < 0) {
            currToken.tokenClass = EoF;
            currToken.repr = '#';
            return currToken;
        }
    } while (isLayoutChar(ch));

    if ('0' <= ch && ch <= '9') {
        currToken.tokenClass = DIGIT;
    }
    else {
        currToken.tokenClass = ch; 
    }
    currToken.repr = ch;
    return currToken;
}

bool Lexer::isLayoutChar(int ch) {
    switch (ch) {
        case ' ':
        case '\t':
        case '\n':
            return 1;
        default:
            return 0;
    }
}

int Lexer::getchar() {
    if (index == sourceCode_.size()) {
        return -1;
    }

    return sourceCode_[index++];
}

} // ns MC
