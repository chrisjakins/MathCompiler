#include "CompilerInstance.h"

int main(int argc, char ** argv) {
    CompilerInstance compiler(argv[1], argv[2]);
    compiler.compile();
    return 0;
}
