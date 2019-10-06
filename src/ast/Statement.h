//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STATEMENT_H
#define PROJECTD_STATEMENT_H


#include "../visitor/Visitor.h"
template <class T>
class Statement: Node<T> {
public:
    virtual void accept(Visitor visitor) = 0;
};


#endif //PROJECTD_STATEMENT_H
