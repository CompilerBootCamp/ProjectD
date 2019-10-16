//
// Created by sovereign on 10/15/19.
//

#include <iostream>
#include "ReadString.h"
#include "../ast/StringLiteral.h"

namespace AST{
Literal& ReadString::evaluate() {
    std::string value;
    std::cin >> value;
    StringLiteral* stringLiteral = new StringLiteral(value);
    return *stringLiteral;
}
}
