#ifndef EXPRESSIONLIST_H_INCLUDED
#define EXPRESSIONLIST_H_INCLUDED

#include "Node.h"
#include <vector>

class AbstractVisitor;

namespace AST
{
    class Expression;

    class ExpressionList: public Node
    {
    public:
        std::vector<Expression*> expressions;
    public:
        ExpressionList();
        ExpressionList(Expression *);
        ~ExpressionList() = default;

        virtual void accept(AbstractVisitor &);
        void add_expression(Expression *);
    };
}

#endif // EXPRESSIONLIST_H_INCLUDED
