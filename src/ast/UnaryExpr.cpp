//
// Created by sovereign on 10/6/19.
//

#include "UnaryExpr.h"
#include "IntLiteral.h"
#include "BooleanLiteral.h"

namespace AST{

    UnaryExpr::UnaryExpr(Expression* expr, UnaryOp op)
    {
        expression = expr;
        operation = op;
    }

    Literal& UnaryExpr::evaluate()
    {
        switch(operation)
        {
        case _PLUS:
            return IntLiteral(0) + expression->evaluate();
        case _MINUS:
            return IntLiteral(0) - expression->evaluate();
        case _NOT:
            auto temp = new BooleanLiteral(!expression->evaluate());
            return *temp;
        }
    }
}
