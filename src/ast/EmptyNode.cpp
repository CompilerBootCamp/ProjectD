#include "../visitor/AbstractVisitor.h"
#include "EmptyNode.h"

namespace AST {

    EmptyNode::EmptyNode()
    {

    }

    void EmptyNode::accept(AbstractVisitor &visitor) const {
        visitor.visit(*this);
    }
}
