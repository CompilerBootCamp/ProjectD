//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_LITERAL_H
#define PROJECTD_LITERAL_H

#include "Expression.h"
#include <string>

class IntLiteral;

class Literal: public Expression {
public:
    virtual ~Literal() = default;
    virtual std::string to_string();
    virtual Literal& evaluate();

    virtual Literal& operator+(Literal& rhs);
    virtual Literal& add_operator(IntLiteral*);
};


#endif //PROJECTD_LITERAL_H
