#ifndef INTERPRETER_H_INCLUDED
#define INTERPRETER_H_INCLUDED

#include "AbstractVisitor.h"

class Interpreter : public AbstractVisitor {
public:
    void visit(const AST::Print &) override;

    void visit(const AST::Node &) override;

    void visit(const AST::Reference &) override;

    void visit(const AST::Statement &) override;

    void visit(AST::StatementList &) override; // need const

    void visit(const AST::EmptyNode &) override;

    void visit(const AST::IfStatement &) override;

    void visit(const AST::WhileStatement &) override;

    void visit(const AST::DefinitionList &) override;

    void visit(const AST::ForStatement &) override;

    void visit(const AST::ReadInt &) override;

    void visit(const AST::ReadString &) override;

    void visit(const AST::ReadReal &) override;

    void visit(const AST::BinaryExpr &) override;

    void visit(const AST::Expression &) override;

    void visit(const AST::TypeIndicator &) override;

    void visit(const AST::UnaryExpr &) override;

    void visit(const AST::Assign &) override;
};

#endif // INTERPRETER_H_INCLUDED
