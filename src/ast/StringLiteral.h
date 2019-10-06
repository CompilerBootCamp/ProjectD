//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STRINGLITERAL_H
#define PROJECTD_STRINGLITERAL_H

#include <string>
#include <utility>
#include "Literal.h"

template <class T>
class StringLiteral: Literal<T> {
private:
    std::string str;
public:
    StringLiteral(std::string str) : str(std::move(str)) {}

private:


public:
    std::string evaluate();

    [[nodiscard]]
    const std::string &getStr() const ;

    void setStr(const std::string &str) ;
};


#endif //PROJECTD_STRINGLITERAL_H
