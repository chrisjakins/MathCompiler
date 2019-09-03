#include "CompilerInstance.h"
#include <iostream>

CompilerInstance::CompilerInstance(const char *infile, const char *outfile)
    : infile_(infile), outfile_(outfile)
{}

void CompilerInstance::compile() {
    std::cout << "Compiling" << std::endl;
}
