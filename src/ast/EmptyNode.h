#ifndef EMPTYNODE_H_INCLUDED
#define EMPTYNODE_H_INCLUDED

#include "Statement.h"

class AbstractVisitor;

namespace AST
{

    class EmptyNode: public Statement
    {
    public:
        EmptyNode();
        virtual ~EmptyNode() = default;
        void accept(AbstractVisitor &) const;
    };
}

#endif // EMPTYNODE_H_INCLUDED
