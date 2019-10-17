//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_BINARYEXPR_H
#define PROJECTD_BINARYEXPR_H

#include "../type_system/Operation.h"
#include "Expression.h"

namespace AST
{

class BinaryExpr: public Expression
{
public:
    Expression* left;
    Expression* right;
    BinOp operation;
public:
    BinaryExpr(Expression*, Expression*, BinOp);

    void accept(AbstractVisitor&) const;
    Literal& evaluate();
};
}

#endif //PROJECTD_BINARYEXPR_H
