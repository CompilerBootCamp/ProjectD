//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_BINARYEXPR_H
#define PROJECTD_BINARYEXPR_H

#include "../type_system/Operation.h"
#include "Expression.h"
#include "Literal.h"

namespace AST
{

    class BinaryExpr: public Expression
    {
    public:
        Expression* left;
        Expression* right;
        Op operation;
    public:
        BinaryExpr(Expression*, Expression*, Op);

        Literal& evaluate()
        {
            switch (operation)
            {
            case _ADD:
                return left->evaluate() + right->evaluate();
            case _DIVIDE:
                break;
            case _MULTIPLY:
                break;
            case _SUB:
                break;
            case _AND:
                break;
            case _OR:
                break;
            case _XOR:
                break;
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
    };
}

#endif //PROJECTD_BINARYEXPR_H
