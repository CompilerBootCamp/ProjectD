//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H

namespace AST {
    class Node;

    class EmptyNode;

    class Print;

    class Reference;

    class Statement;

    class StatementList;

    class Expression;

    class IfStatement;

    class WhileStatement;

    class DefinitionList;

    class ForStatement;

    class ReadInt;

    class ReadString;

    class ReadReal;

    class BinaryExpr;

    class Expression;

    class TypeIndicator;

    class UnaryExpr;

    class Assign;
}

class AbstractVisitor {
public:
    virtual ~AbstractVisitor() = default;

    virtual void visit(const AST::Node &) = 0;

    virtual void visit(const AST::EmptyNode &) = 0;

    virtual void visit(const AST::Reference &) = 0;

    virtual void visit(const AST::Print &) = 0;

    virtual void visit(AST::StatementList &) = 0;

    virtual void visit(const AST::IfStatement &) = 0;

    virtual void visit(const AST::Statement &) = 0;

    virtual void visit(const AST::WhileStatement &) = 0;

    virtual void visit(const AST::DefinitionList &) = 0;

    virtual void visit(const AST::ForStatement &) = 0;

    virtual void visit(const AST::ReadInt &) = 0;

    virtual void visit(const AST::ReadString &) = 0;

    virtual void visit(const AST::ReadReal &) = 0;

    virtual void visit(const AST::BinaryExpr &) = 0;

    virtual void visit(const AST::Expression &) = 0;

    virtual void visit(const AST::TypeIndicator &) = 0;

    virtual void visit(const AST::UnaryExpr &) = 0;

    virtual void visit(const AST::Assign &) = 0;
};


#endif //PROJECTD_VISITOR_H
