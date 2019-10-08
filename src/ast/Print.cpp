//
// Created by sovereign on 10/6/19.
//

#include "Print.h"
#include "ExpressionList.h"
#include "../visitor/AbstractVisitor.h"

namespace AST{

    Print::Print(ExpressionList *expressionslist)
    {
        expressionsList = expressionslist;
    }

    void Print::accept(AbstractVisitor &visitor)
    {
        visitor.visit(*this);
    }
}
