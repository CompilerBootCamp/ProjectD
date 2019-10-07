//
// Created by sovereign on 10/6/19.
//

#include "Print.h"
#include "../visitor/AbstractVisitor.h"

Print::Print(Expression &expression):expressions()
{
    expressions.push_back(&expression);
}

void Print::addExpr(Expression  &expression) {
    this->expressions.push_back(&expression);
}

void Print::accept(AbstractVisitor &visitor)
{
    visitor.visit(*this);
}
