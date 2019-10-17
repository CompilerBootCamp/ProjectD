#ifndef TUPLELITERAL_H_INCLUDED
#define TUPLELITERAL_H_INCLUDED

#include "Literal.h"
#include <vector>

namespace AST{

class TupleElementList;

class TupleLiteral: public Literal
{
public:
    std::vector<std::pair<std::string, Literal*> > tu_list;
public:
    TupleLiteral();
    TupleLiteral(TupleElementList* tul);

    Literal& evaluate() override;
    std::string to_string() override;

    Literal& operator+(Literal& rhs) override;

    //Only for tuples
    Literal& concat(TupleLiteral*) override;

    Literal** get_value(std::string);

    [[nodiscard]] TYPES::Type getType() override;
};
}

#endif // TUPLELITERAL_H_INCLUDED
