//
// Created by sovereign on 10/6/19.
//

#include "Reference.h"
#include "../visitor/AbstractVisitor.h"

void Reference::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}
