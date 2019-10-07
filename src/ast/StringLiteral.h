//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STRINGLITERAL_H
#define PROJECTD_STRINGLITERAL_H

#include <string>
#include <utility>
#include "Literal.h"

class StringLiteral: public Literal {
private:
    std::string str;
public:
    StringLiteral(std::string str) : str(std::move(str)) {}

private:


public:

};


#endif //PROJECTD_STRINGLITERAL_H
