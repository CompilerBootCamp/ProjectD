//
// Created by sovereign on 10/6/19.
//

#include "../visitor/AbstractVisitor.h"
#include "Node.h"


void Node::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}
