//
// Created by sovereign on 10/6/19.
//

#include "BinaryExpr.h"

namespace AST
{

    BinaryExpr::BinaryExpr(Expression* l, Expression* r, Op op)
    {
        left = l;
        right = r;
        operation = op;
    }

    Literal& BinaryExpr::evaluate()
    {
        switch (operation)
            {
            case _ADD:
                return left->evaluate() + right->evaluate();
            case _DIVIDE:
                return left->evaluate() / right->evaluate();
            case _MULTIPLY:
                return left->evaluate() * right->evaluate();
            case _SUB:
                return left->evaluate() - right->evaluate();
            case _AND:
                return left->evaluate() && right->evaluate();
            case _OR:
                return left->evaluate() || right->evaluate();
            case _XOR:
                return left->evaluate() ^ right->evaluate();
            case _LESS:
                break;
            case _GREATER:
                break;
            case _LESS_OR_EQUAL:
                break;
            case _EQUAL:
                break;
            case _GREATER_OR_EQUAL:
                break;
            case _DIVIDE_EQUAL:
                break;
            }
    }
}
