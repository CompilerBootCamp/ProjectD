//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_BINARYEXPR_H
#define PROJECTD_BINARYEXPR_H

#include "Operation.cpp"
#include "Expression.h"


class BinaryExpr: Expression<BinaryExpr> {
private:
    Expression left;
    Expression right;
    Op op;
public:
    template <class T>
    const Expression<T> &getLeft() const;

    template <class T>
    void setLeft(const Expression<T> &left);

    template <class T>
    const Expression<T> &getRight() const;

    template <class T>
    void setRight(const Expression<T> &right);

    void evaluate(){
        switch (op){
            case ADD:

                break;
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
