#include "CompilerInstance.h"

#include <iostream>

int main(int argc, char ** argv) {
    if (argc < 3) {
        std::cerr << "Usage: ./compiler input.math outfilename" << std::endl;
        return 1;
    }
    MC::CompilerInstance compiler(argv[1], argv[2]);
    compiler.compile();
    return 0;
}
