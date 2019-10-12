//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_PRINT_H
#define PROJECTD_PRINT_H


#include "Statement.h"
#include <vector>
#include <memory>

namespace AST{

    class ExpressionList;

    class Print: public Statement {
    public:
        ExpressionList* expressionsList;

    public:
        Print(ExpressionList *);
        void accept(AbstractVisitor&) const;
    };
}


#endif //PROJECTD_PRINT_H
