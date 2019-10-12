//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H

#include <ast/IfStatement.h>

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
class Print;
class Node;
class Reference;
class Statement;
class Expression;
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
    virtual void visit(const AST::IfStatement&) = 0;
    virtual void visit(const Node &) = 0;
    virtual void visit(const Reference &) = 0;
    virtual void visit(const Print &) = 0;
    virtual void visit(const Statement &) = 0;
};


#endif //PROJECTD_VISITOR_H
