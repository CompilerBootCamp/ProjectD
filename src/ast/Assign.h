#ifndef ASSIGN_H_INCLUDED
#define ASSIGN_H_INCLUDED

#include "Statement.h"

namespace AST
{
class Reference;
class Expression;

class Assign: public Statement
{
public:
    Expression* ref_variable;
    Expression* expression;
public:
    Assign(Expression*, Expression*);
    void accept(AbstractVisitor&) const;
};
}

#endif // ASSIGN_H_INCLUDED
