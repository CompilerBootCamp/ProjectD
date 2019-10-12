#ifndef TUPLELITERAL_H_INCLUDED
#define TUPLELITERAL_H_INCLUDED

#include "Literal.h"

namespace AST{

class TupleElementList;

class TupleLiteral: public Literal
{
public:
    TupleElementList* tu_list;
public:
    TupleLiteral();
    TupleLiteral(TupleElementList* tul);

    Literal& evaluate() override;
    std::string to_string() override;
};
}

#endif // TUPLELITERAL_H_INCLUDED
