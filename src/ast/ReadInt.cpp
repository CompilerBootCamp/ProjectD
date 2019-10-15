//
// Created by sovereign on 10/15/19.
//

#include "ReadInt.h"
#include "../visitor/AbstractVisitor.h"

void AST::ReadInt::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}
