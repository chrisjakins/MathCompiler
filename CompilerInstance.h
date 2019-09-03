#pragma once

#include <string>

namespace MC {

class CompilerInstance {
public:
    CompilerInstance(const char *infilename, const char *outfilename);

    void compile();

private:
    std::string infile_;
    std::string outfilename_;
};

} // ns MC
