//
// Created by sovereign on 10/6/19.
//

#include "Visitor.h"
#include "../ast/Print.h"

template <class R>
void Visitor::visit(Print* print) {
    for (const Expression<R> expr: print->getExpressions<R>()) {
        expr.accept(this);
    }
}
