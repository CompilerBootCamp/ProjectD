//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STATEMENTLIST_H
#define PROJECTD_STATEMENTLIST_H


#include "Node.h"
#include <vector>
class Statement;
class AbstractVisitor;

class StatementList: public Node {

public:
    std::vector<Statement*> statements;
public:
    StatementList(Statement &);
    ~StatementList() = default;

    virtual void accept(AbstractVisitor &);
};


#endif //PROJECTD_STATEMENTLIST_H
