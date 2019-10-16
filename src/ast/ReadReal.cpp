//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadReal.h"
#include "../ast/RealLiteral.h"
namespace AST
{
Literal &ReadReal::evaluate()
{
    double value;
    std::cin >> value;
    RealLiteral* realLiteral = new RealLiteral(value);
    return *realLiteral;
}
}
