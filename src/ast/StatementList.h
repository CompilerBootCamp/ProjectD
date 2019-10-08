//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STATEMENTLIST_H
#define PROJECTD_STATEMENTLIST_H


#include "Node.h"
#include <vector>

class AbstractVisitor;

namespace AST{
    class Statement;

    class StatementList: public Node {

    public:
        std::vector<Statement*> statements;
    public:
        StatementList(Statement *);
        ~StatementList() = default;

        virtual void accept(AbstractVisitor &);
        void add_statement(Statement *);
    };
}


#endif //PROJECTD_STATEMENTLIST_H
