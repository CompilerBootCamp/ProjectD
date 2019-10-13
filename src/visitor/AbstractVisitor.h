//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H

#include <ast/WhileStatement.h>

namespace AST
{
    class Node;
    class EmptyNode;
    class Print;
    class Reference;
    class Statement;
    class StatementList;
    class Expression;
    class IfStatement;
}

class AbstractVisitor
{
public:
    virtual ~AbstractVisitor() = default;

    virtual void visit(const AST::Node &) = 0;
    virtual void visit(const AST::EmptyNode &) = 0;
    virtual void visit(const AST::Reference &) = 0;
    virtual void visit(const AST::Print &) = 0;
    virtual void visit(const AST::StatementList &) = 0;
    virtual void visit(const AST::IfStatement&) = 0;
    virtual void visit(const AST::Statement &) = 0;
    virtual void visit(const AST::WhileStatement &) = 0;
};


#endif //PROJECTD_VISITOR_H
