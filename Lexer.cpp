#include "Lexer.h"

#include <iostream>

namespace MC {

// TODO: sourceCode reference?
Lexer::Lexer(std::string sourceCode)
    : sourceCode_(sourceCode), index(0)
{}

//TODO change to stringstream
void Lexer::getNextToken() {
    int ch;

    do {
        ch = getchar();
        if (ch < 0) {
            currToken_.tokenClass_ = EoF;
            currToken_.repr_ = '#';
            return;
        }
    } while (isLayoutChar(ch));

    if ('0' <= ch && ch <= '9') {
        currToken_.tokenClass_ = DIGIT;
    }
    else {
        currToken_.tokenClass_ = ch; 
    }
    currToken_.repr_ = ch;
}

Token &Lexer::currToken() {
    return currToken_;
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
