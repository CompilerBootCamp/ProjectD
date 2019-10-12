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
}

class AbstractVisitor
{
public:
    virtual ~AbstractVisitor() = default;

    virtual void visit(const AST::Node &) = 0;
    virtual void visit(const AST::EmptyNode &) = 0;
    virtual void visit(const AST::Reference &) = 0;
    virtual void visit(const AST::Print &) = 0;
    virtual void visit(const AST::Statement &) = 0;
    virtual void visit(const AST::StatementList &) = 0;
};


#endif //PROJECTD_VISITOR_H
