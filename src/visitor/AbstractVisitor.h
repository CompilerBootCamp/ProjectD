//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H

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
    class WhileStatement;
    class DefinitionList;
    class ForStatement;
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
    virtual void visit(const AST::DefinitionList &) = 0;
    virtual void visit(const AST::ForStatement &) = 0;
};


#endif //PROJECTD_VISITOR_H
