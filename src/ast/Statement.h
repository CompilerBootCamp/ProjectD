//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STATEMENT_H
#define PROJECTD_STATEMENT_H

#include "Node.h"

namespace AST{

    class Statement: public Node {
    public:
        virtual void accept(AbstractVisitor &) const = 0;
    };
}


#endif //PROJECTD_STATEMENT_H
