//
// Created by sovereign on 10/6/19.
//

#include "Print.h"
#include "ExpressionList.h"
#include "../visitor/AbstractVisitor.h"

namespace AST{

    Print::Print(ExpressionList *expressionslist)
    {
        expressionsList = expressionslist->expressions;
    }

    void Print::accept(AbstractVisitor &visitor) const
    {
        visitor.visit(*this);
    }
}
