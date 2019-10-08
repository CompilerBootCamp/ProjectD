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
}
