#pragma once

#include <string>

class CompilerInstance {
public:
    CompilerInstance(const char *infile, const char *outfile);

    void compile();

private:
    std::string infile_;
    std::string outfile_;
};
