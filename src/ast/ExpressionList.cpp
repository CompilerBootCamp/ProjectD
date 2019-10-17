#include "ExpressionList.h"
#include "../visitor/AbstractVisitor.h"

namespace AST
{
    ExpressionList::ExpressionList(Expression *expression)
    {
        expressions.push_back(expression);
    }

    void ExpressionList::accept(AbstractVisitor &visitor)
    {
        visitor.visit(*this);
    }

    void ExpressionList::add_expression(Expression *expression)
    {
        expressions.push_back(expression);
    }

    ExpressionList::ExpressionList()
    {
    }
}
