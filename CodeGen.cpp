#include "CodeGen.h"

#include <iostream>

namespace MC {

void CodeGen::generate(std::shared_ptr<Expression> expr) {
    switch (expr->type_) {
        case 'D':
            std::cout << "PUSH " << expr->value_ << std::endl;
            break;
        case 'P':
            generate(expr->left_);
            generate(expr->right_);
            switch (expr->oper_) {
                case '+':
                    std::cout << "ADD" << std::endl;
                    break;
                case '*':
                    std::cout << "MULT" << std::endl;
                    break;
            }
            break;
    }
}

} // ns MC
