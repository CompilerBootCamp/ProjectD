#ifndef FUNCBODY_H_INCLUDED
#define FUNCBODY_H_INCLUDED

#include "Node.h"

namespace AST
{
class StatementList;
class Expression;

class FuncBody: public Node
{
public:
    bool is_expression;
    StatementList* f_statements;
    Expression* f_expression;
public:
    FuncBody(StatementList*);
    FuncBody(Expression*);

};
}

#endif // FUNCBODY_H_INCLUDED
