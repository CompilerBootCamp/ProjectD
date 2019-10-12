#ifndef ARRAYLITERAL_H_INCLUDED
#define ARRAYLITERAL_H_INCLUDED

#include "Literal.h"
#include <map>

namespace AST
{
class ExpressionList;

class ArrayLiteral: public Literal
{
private:
    size_t _size;
public:
    //int or Literal??
    std::map<int, Literal*> array;
public:
    ArrayLiteral();
    ArrayLiteral(ExpressionList*);

    std::string to_string() override;
    Literal& evaluate() override;
    Literal& operator+(Literal& rhs) override;

    size_t size();
    //Only for arrays
    Literal& concat(ArrayLiteral*) override;
};
}

#endif // ARRAYLITERAL_H_INCLUDED
