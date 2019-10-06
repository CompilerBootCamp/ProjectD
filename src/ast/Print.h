//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_PRINT_H
#define PROJECTD_PRINT_H


#include "Statement.h"
#include "Expression.h"
#include <vector>


class Print: Statement<Print> {
private:
    std::vector<Expression> expressions;

public:
    template <class R>
    const std::vector<Expression<R>> &getExpressions() const ;

    template <class R>
    void addExpr(const Expression<R> &expression);
};


#endif //PROJECTD_PRINT_H
