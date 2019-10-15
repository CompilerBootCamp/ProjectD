//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadInt.h"
#include "../ast/IntLiteral.h"

AST::Literal &AST::ReadInt::evaluate() {
    int value;
    std::cin >> value;
    IntLiteral intLiteral = value;
    return intLiteral;
}

AST::ReadInt::ReadInt() {}
