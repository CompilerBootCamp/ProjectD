//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_BINARYEXPR_H
#define PROJECTD_BINARYEXPR_H

#include "../type_system/Operation.h"
#include "Expression.h"
#include "Literal.h"

class BinaryExpr: public Expression {
public:
    Expression* left;
    Expression* right;
    Op op;
public:
    Literal& evaluate(){
        switch (op){
            case ADD:
                return left->evaluate() + right->evaluate();
            case DIVIDE:
                break;
            case MULTIPLY:
                break;
            case SUB:
                break;
            case AND:
                break;
            case OR:
                break;
            case XOR:
                break;
            case LESS:
                break;
            case GREATER:
                break;
            case LESS_OR_EQUAL:
                break;
            case EQUAL:
                break;
            case GREATER_OR_EQUAL:
                break;
            case DIVIDE_EQUAL:
                break;
        }
    }
};


#endif //PROJECTD_BINARYEXPR_H
