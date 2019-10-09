//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_EXPRESSION_H
#define PROJECTD_EXPRESSION_H

#include "Node.h"

class Literal;

class Expression: public Node {
public:
    virtual Literal& evaluate() = 0;
};


#endif //PROJECTD_EXPRESSION_H
