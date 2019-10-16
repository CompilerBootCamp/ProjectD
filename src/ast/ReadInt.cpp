//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadInt.h"
#include "../ast/IntLiteral.h"
namespace AST
{
Literal &ReadInt::evaluate()
{
    int value;
    std::cin >> value;
    IntLiteral* intLiteral = new IntLiteral(value);
    return *intLiteral;
}

ReadInt::ReadInt() {}
}
