#include "Parser.h"

#include <iostream>

namespace MC {

Parser::Parser(Lexer &lexer) 
    : lexer_(lexer)
{ }

int Parser::parseProgram(std::shared_ptr<Expression> expr) {
    lexer_.getNextToken();
    if (parseExpression(expr)) {
        if (lexer_.currToken().tokenClass_ != EoF) {
            std::cout << "Error: junk after EoF" << std::endl;
        }
        return 1;
    }
    return 0;
}

int Parser::parseOperator(Operator &oper) {
    // TODO: these could be combined
    if (lexer_.currToken().tokenClass_ == '+') {
        oper = '+';
        lexer_.getNextToken();
        return 1;
    }
    if (lexer_.currToken().tokenClass_ == '*') {
        oper = '*';
        lexer_.getNextToken();
        return 1;
    }
    return 0;
}

int Parser::parseExpression(std::shared_ptr<Expression> expr) {
    Token &currToken = lexer_.currToken();

    if (currToken.tokenClass_ == DIGIT) {
        expr->type_ = 'D';
        expr->value_ = currToken.repr_ - '0';
        lexer_.getNextToken();
        return 1;
    }

    if (currToken.tokenClass_ == '(') {
        expr->type_ = 'P';
        lexer_.getNextToken();
        expr->left_ = std::make_shared<Expression>();
        expr->right_ = std::make_shared<Expression>();
        if (!parseExpression(expr->left_)) {
            std::cout << "Error: missing expression at position " << currToken.pos_ << std::endl;
        }
        if (!parseOperator(expr->oper_)) {
            std::cout << "Error: missing operator at position " << currToken.pos_ << std::endl;
        }
        if (!parseExpression(expr->right_)) {
            std::cout << "Error: missing expression at position " << currToken.pos_ << std::endl;
        }
        if (currToken.tokenClass_ != ')') {
            std::cout << "Error: missing ) at position " << currToken.pos_ << std::endl;
        }
        lexer_.getNextToken();
        return 1;
    }
    return 0;
}

} // ns MC
