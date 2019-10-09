#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED

#include "AbstractVisitor.h"

class Interpreter: public AbstractVisitor
{
public:
    void visit(const Print &);
    void visit(const Node &);
    void visit(const Reference &);
    void visit(const Statement &);
};

#endif // INTERPRETER_H_INCLUDED
