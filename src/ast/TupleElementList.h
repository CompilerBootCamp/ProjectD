#ifndef TUPLEELEMENTLIST_H_INCLUDED
#define TUPLEELEMENTLIST_H_INCLUDED

#include <vector>
#include <string>
#include "Node.h"

namespace AST
{
class Expression;
class TupleElement;
class Literal;

class TupleElementList: public Node
{
public:
    std::vector<std::pair<std::string, Literal*> > elements;
public:
    TupleElementList();
    TupleElementList(TupleElement*);

    void add_tuple_element(TupleElement*);
};
}

#endif // TUPLEELEMENTLIST_H_INCLUDED
