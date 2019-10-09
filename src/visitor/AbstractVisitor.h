//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_VISITOR_H
#define PROJECTD_VISITOR_H

class Print;
class Node;
class Reference;
class Statement;
class Expression;

class AbstractVisitor {
public:
    virtual ~AbstractVisitor() = default;

    virtual void visit(const Node &) = 0;
    virtual void visit(const Reference &) = 0;
    virtual void visit(const Print &) = 0;
    virtual void visit(const Statement &) = 0;

};


#endif //PROJECTD_VISITOR_H
