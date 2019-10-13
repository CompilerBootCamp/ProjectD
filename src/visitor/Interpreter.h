#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED

#include "AbstractVisitor.h"

class Interpreter: public AbstractVisitor
{
public:
    void visit(const AST::Print &) override;
    void visit(const AST::Node &) override;
    void visit(const AST::Reference &) override;
    void visit(const AST::Statement &) override;
    void visit(const AST::StatementList &) override;
    void visit(const AST::EmptyNode &) override;
    void visit(const AST::IfStatement &) override;
    void visit(const AST::WhileStatement &) override;
    void visit(const AST::DefinitionList &) override;
};

#endif // INTERPRETER_H_INCLUDED
