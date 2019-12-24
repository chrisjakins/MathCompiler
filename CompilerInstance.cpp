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
    generateCode(expr);
}

std::shared_ptr<Expression> CompilerInstance::parseProgram() {
    std::shared_ptr<Expression> expr = std::make_shared<Expression>();
    Lexer lexer(infile_);
    Parser parser(lexer);
    parser.parseProgram(expr);
    return expr;
}

//TODO: write to file
void CompilerInstance::generateCode(std::shared_ptr<Expression> expr) {
    CodeGen::generate(expr);
}

} // ns MC
