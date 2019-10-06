//
// Created by sovereign on 10/6/19.
//

#include "StatementList.h"

void StatementList::accept(Visitor visitor) {
    for (auto statement: statements) {
        visitor.visit(statement);
    }
}
