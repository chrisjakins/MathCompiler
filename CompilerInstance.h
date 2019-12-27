#pragma once

#include <memory>
#include <string>

#include "Expression.h"

namespace MC {

class CompilerInstance {
public:
    CompilerInstance(const char *infilename, const char *outfilename);

    void compile();

private:
    std::string infile_;
    std::string outfilename_;

    std::shared_ptr<Expression> parseProgram();
    void generateCode(std::shared_ptr<Expression> expr);
    void constantFolding(std::shared_ptr<Expression> expr);
    int calc(int left, int oper, int right);
};

} // ns MC
