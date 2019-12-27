#include "CompilerInstance.h"
#include "CodeGen.h"
#include "Expression.h"
#include "Lexer.h"
#include "Parser.h"

#include <iostream>
#include <fstream>

namespace MC {

CompilerInstance::CompilerInstance(const char *infilename, const char *outfilename)
    : outfilename_(outfilename)
{
    std::ifstream infile(infilename);
    infile >> infile_;
}

void CompilerInstance::compile() {
    auto expr = parseProgram();
    if (expr) {
        constantFolding(expr);
        generateCode(expr);
    }
}

std::shared_ptr<Expression> CompilerInstance::parseProgram() {
    std::shared_ptr<Expression> expr = std::make_shared<Expression>();
    Lexer lexer(infile_);
    Parser parser(lexer);
    if (parser.parseProgram(expr) == 0) {
        return nullptr;
    }
    return expr;
}

//TODO: write to file
void CompilerInstance::generateCode(std::shared_ptr<Expression> expr) {
    CodeGen::generate(expr);
}

// TODO: i believe this will only work on binary operations (as opposed to unary)
void CompilerInstance::constantFolding(std::shared_ptr<Expression> expr) {
    if (expr->left_->type_ != 'D') {
        constantFolding(expr->left_);
    }

    if (expr->right_->type_ != 'D') {
        constantFolding(expr->right_);
    }

    expr->type_ = 'D';
    expr->value_ = calc(expr->left_->value_, expr->oper_, expr->right_->value_);
    expr->oper_ = 0;
    expr->right_.reset();
    expr->left_.reset();
}

int CompilerInstance::calc(int left, int oper, int right) {
    switch (oper) {
        case '+': return left + right;
        case '*': return left * right;
        default: return left + right;
    }
}

} // ns MC
