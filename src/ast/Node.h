//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_NODE_H
#define PROJECTD_NODE_H

class AbstractVisitor;

namespace AST
{

    class Node
    {
    public:
        virtual ~Node() = default;
        virtual void accept(AbstractVisitor &) const;
    };
}

#endif //PROJECTD_NODE_H
