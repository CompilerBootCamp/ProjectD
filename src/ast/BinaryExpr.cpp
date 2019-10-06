//
// Created by sovereign on 10/6/19.
//

#include "BinaryExpr.h"
template <class T>
const Expression<T> &BinaryExpr::getLeft() const {
    return this->left;
}

template <class T>
void BinaryExpr::setLeft(const Expression<T> &left) {
    BinaryExpr::left = left;
}

template <class T>
const Expression<T> &BinaryExpr::getRight() const {
    return right;
}

template <class T>
void BinaryExpr::setRight(const Expression<T> &right) {
    BinaryExpr::right = right;
}
