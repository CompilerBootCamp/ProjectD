//
// Created by sovereign on 10/6/19.
//

#include "Expression.h"
#include "Literal.h"

namespace AST {

void Expression::add_reference(ReferenceTail*){}

TYPES::Type Expression::getType()
{
    return (&this->evaluate())->getType();
}
}
