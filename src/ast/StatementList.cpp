//
// Created by sovereign on 10/6/19.
//

#include "StatementList.h"
#include "../visitor/AbstractVisitor.h"
#include "../ast/Scope.h"
#include "../ast/Statement.h"

namespace AST
{

    StatementList::StatementList(Statement *statement): statements()
    {
        scope = new Scope();
        statement->scope = new Scope();
        statement->scope->topScope = scope;
        statements.push_back(statement);
    }

    void StatementList::accept(AbstractVisitor &visitor)
    {
        visitor.visit(*this);
    }

    void StatementList::add_statement(Statement *statement)
    {
        statement->scope = new Scope();
        statement->scope->topScope = scope;
        statements.push_back(statement);
    }
}
