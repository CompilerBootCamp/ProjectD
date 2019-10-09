//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_PRINT_H
#define PROJECTD_PRINT_H


#include "Statement.h"
#include <vector>
#include <memory>

class Expression;

class Print: public Statement {
public:
    std::vector<Expression* > expressions;

public:
    Print(Expression &);
    void accept(AbstractVisitor&);

    void addExpr(Expression &);
};


#endif //PROJECTD_PRINT_H
