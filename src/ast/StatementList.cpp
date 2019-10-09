//
// Created by sovereign on 10/6/19.
//

#include "StatementList.h"
#include "../visitor/AbstractVisitor.h"

StatementList::StatementList(Statement &statement): statements()
{
    statements.push_back(&statement);
}

void StatementList::accept(AbstractVisitor &visitor) {
    for (auto & statement: statements) {
        visitor.visit(*statement);
    }
}
