//
// Created by sovereign on 10/6/19.
//

#include "Print.h"
#include "Expression.h"
#include <vector>
template <class R>
void Print::addExpr(const Expression<R> &expression) {
    this->expressions.push_back(expression)
}

template<class R>
const std::vector<Expression<R>> &Print::getExpressions() const {
    return this->expressions;
}
