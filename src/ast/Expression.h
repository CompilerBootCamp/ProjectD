//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_EXPRESSION_H
#define PROJECTD_EXPRESSION_H

#include "Node.h"
#include "Literal.h"

template <class T>
class Expression: Node<T> {
public:
    template <class R>
    virtual R evaluate() = 0;
};


#endif //PROJECTD_EXPRESSION_H
