#include "CompilerInstance.h"
#include "Lexer.h"
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
    Lexer lexer(infile_);

    Token currToken = lexer.getNextToken();
    while (currToken.tokenClass != EoF) {
        std::cout << currToken.repr << std::endl;
        currToken = lexer.getNextToken();
    }
}

} // ns MC
