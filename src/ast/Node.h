//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_NODE_H
#define PROJECTD_NODE_H


#include "../visitor/Visitor.h"

template <class T>
class Node {
public:
//    virtual void accept(Visitor visitor) = 0;
    void accept(Visitor visitor);
};




#endif //PROJECTD_NODE_H
