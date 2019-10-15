//
// Created by sovereign on 10/15/19.
//

#include "ReadString.h"
#include "../visitor/AbstractVisitor.h"

void AST::ReadString::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}
