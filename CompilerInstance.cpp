#include "CompilerInstance.h"
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
    std::cout << infile_ << std::endl;
}

} // ns MC
