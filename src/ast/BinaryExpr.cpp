//
// Created by sovereign on 10/6/19.
//

#include "BinaryExpr.h"
#include "BooleanLiteral.h"

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
            case _LESS:{
                auto temp = new BooleanLiteral(left->evaluate() < right->evaluate());
                return *temp;
            }
            case _GREATER:{
                auto temp = new BooleanLiteral(left->evaluate() > right->evaluate());
                return *temp;
            }
                break;
            case _LESS_OR_EQUAL:{
                auto temp = new BooleanLiteral(left->evaluate() <= right->evaluate());
                return *temp;
            }
                break;
            case _EQUAL:{
                auto temp = new BooleanLiteral(left->evaluate() == right->evaluate());
                return *temp;
            }
                break;
            case _GREATER_OR_EQUAL:{
                auto temp = new BooleanLiteral(left->evaluate() >= right->evaluate());
                return *temp;
            }
                break;
            case _DIVIDE_EQUAL:{
                auto temp = new BooleanLiteral(left->evaluate() != right->evaluate());
                return *temp;
            }
                break;
            }
    }
}
