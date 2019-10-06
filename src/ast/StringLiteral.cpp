//
// Created by sovereign on 10/6/19.
//

#include "StringLiteral.h"

template<class T>
[[nodiscard]]
const std::string &StringLiteral<T>::getStr() const {
    return this->str;
}

template<class T>
void StringLiteral<T>::setStr(const std::string &str) {
    this->str=str;
}

template<class T>
std::string StringLiteral<T>::evaluate() {
    return std::string(this->str);
}

