//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_REFERENCE_H
#define PROJECTD_REFERENCE_H


#include "Node.h"

class Reference: Node {
    virtual void accept(Visitor visitor);
};


#endif //PROJECTD_REFERENCE_H
