//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_UNARYEXPR_H
#define PROJECTD_UNARYEXPR_H


#include "Expression.h"
#include "../type_system/Operation.h"

namespace AST{

    class UnaryExpr: public Expression {
        Expression* expression;
        UnaryOp operation;
    public:
        UnaryExpr(Expression*, UnaryOp);
        Literal& evaluate();
    };
}


#endif //PROJECTD_UNARYEXPR_H
