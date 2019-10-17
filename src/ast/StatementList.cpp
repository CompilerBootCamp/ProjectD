//
// Created by sovereign on 10/6/19.
//

#include "StatementList.h"
#include "../visitor/AbstractVisitor.h"

namespace AST
{

    StatementList::StatementList(Statement *statement): statements()
    {
        statements.push_back(statement);
    }

    void StatementList::accept(AbstractVisitor &visitor)
    {
        visitor.visit(*this);
    }

    void StatementList::add_statement(Statement *statement)
    {
        statements.push_back(statement);
    }
}
