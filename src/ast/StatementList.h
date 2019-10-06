//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STATEMENTLIST_H
#define PROJECTD_STATEMENTLIST_H


#include "Node.h"

class StatementList: Node {

private:
    std::vector<Statement*> statements;
public:
    virtual void accept(Visitor visitor);
};


#endif //PROJECTD_STATEMENTLIST_H
