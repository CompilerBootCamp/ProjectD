//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H


#include "../token/StatementList.h"
#include "../ast/Statement.h"
#include "../ast/Print.h"

class Visitor {
public:

    template <class R>
    void visit(Print *print);


};


#endif //PROJECTD_VISITOR_H
