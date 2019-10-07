#include "CodeGen.h";

namespace MC {

void CodeGen::generate(Expression *expr) {
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
