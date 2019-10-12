#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED

#include "AbstractVisitor.h"

class Interpreter: public AbstractVisitor
{
public:
    void visit(const AST::Print &);
    void visit(const AST::Node &);
    void visit(const AST::Reference &);
    void visit(const AST::Statement &);
    void visit(const AST::StatementList &);
    void visit(const AST::EmptyNode &);
    void visit(const Print &);
    void visit(const Node &);
    void visit(const Reference &);
    void visit(const Statement &);

    void visit(const AST::IfStatement &statement) override;
};

#endif // INTERPRETER_H_INCLUDED
