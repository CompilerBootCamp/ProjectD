
#include "IntLiteral.h"

IntLiteral::IntLiteral(int val): value(val){}

std::string IntLiteral::to_string()
{
    return std::to_string(value);
}

Literal& IntLiteral::evaluate()
{
    return *this;
}

Literal& IntLiteral::operator+(Literal& rhs)
{
    return rhs.add_operator(this);
}

Literal& IntLiteral::add_operator(IntLiteral* rhs)
{
    auto temp = new IntLiteral(this->value + rhs->value);
    return *temp;
}
