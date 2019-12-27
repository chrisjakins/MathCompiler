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
        generateCode(expr);
    }
}

std::shared_ptr<Expression> CompilerInstance::parseProgram() {
    std::shared_ptr<Expression> expr = std::make_shared<Expression>();
    Lexer lexer(infile_);
    Parser parser(lexer);
    if (parser.parseProgram(expr) > 0) {
        return nullptr;
    }
    return expr;
}

//TODO: write to file
void CompilerInstance::generateCode(std::shared_ptr<Expression> expr) {
    CodeGen::generate(expr);
}

} // ns MC
