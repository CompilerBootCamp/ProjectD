//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_PRINT_H
#define PROJECTD_PRINT_H


#include "Statement.h"
#include <vector>
#include <memory>

namespace AST{

    class Expression;

    class ExpressionList;

    class Print: public Statement {
    public:
        std::vector<Expression*> expressionsList;

    public:
        Print(ExpressionList *);
        void accept(AbstractVisitor&) const;
    };
}


#endif //PROJECTD_PRINT_H
