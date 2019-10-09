//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_REFERENCE_H
#define PROJECTD_REFERENCE_H

#include "Node.h"

class Reference: public Node {
    void accept(AbstractVisitor &) const;
};


#endif //PROJECTD_REFERENCE_H
