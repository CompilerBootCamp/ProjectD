//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadString.h"
#include "../ast/StringLiteral.h"

AST::Literal &AST::ReadString::evaluate() {
    std::string value;
    std::cin >> value;
    StringLiteral stringLiteral = value;
    return stringLiteral;
}
