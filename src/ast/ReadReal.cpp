//
// Created by sovereign on 10/15/19.
//

#include "ReadReal.h"
#include "../visitor/AbstractVisitor.h"

void AST::ReadReal::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}
