//
// Created by sovereign on 10/6/19.
//
#include "StringLiteral.h"

namespace AST
{
    StringLiteral::StringLiteral(char* val): value(val)
    {
        value = value.substr(1, value.size() - 2);
    }
    StringLiteral::StringLiteral(std::string val): value(val) {}

    std::string StringLiteral::to_string()
    {
        return value;
    }

    Literal& StringLiteral::evaluate()
    {
        return *this;
    }

    Literal& StringLiteral::operator+(Literal& rhs)
    {
        return rhs.add_operator(this);
    }

    Literal& StringLiteral::add_operator(StringLiteral* rhs)
    {
        auto temp = new StringLiteral(rhs->value + this->value);
        return *temp;
    }
}
