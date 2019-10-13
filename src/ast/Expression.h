//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_EXPRESSION_H
#define PROJECTD_EXPRESSION_H

#include "Node.h"

namespace AST
{
    class Literal;
    class ReferenceTail;

    class Expression: public Node
    {
    public:
        virtual Literal& evaluate() = 0;

        virtual void add_reference(ReferenceTail*);
    };
}

#endif //PROJECTD_EXPRESSION_H
