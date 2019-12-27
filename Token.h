#pragma once

#define EoF 256
#define DIGIT 257

namespace MC {

struct Token {
    int tokenClass_;
    int pos_;
    char repr_;
};

} // ns MC
