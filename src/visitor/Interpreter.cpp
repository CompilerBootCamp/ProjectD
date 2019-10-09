//
// Created by sovereign on 10/6/19.
//

#include "../ast/Print.h"
#include "../ast/Expression.h"
#include "../ast/Literal.h"
#include "Interpreter.h"
#include <iostream>


void Interpreter::visit(const Print &print) {
    for(auto expression : print.expressions)
        std::cout << expression->evaluate().to_string()<< std::endl;
}

void Interpreter::visit(const Node &node) {}
void Interpreter::visit(const Reference &reference) {}
void Interpreter::visit(const Statement &stament) {}
