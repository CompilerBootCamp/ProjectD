//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadReal.h"
#include "../ast/RealLiteral.h"

AST::Literal &AST::ReadReal::evaluate() {
    double value;
    std::cin >> value;
    RealLiteral realLiteral = RealLiteral(value);
    return realLiteral;
}
