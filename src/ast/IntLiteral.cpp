#include "IntLiteral.h"
#include "RealLiteral.h"

namespace AST
{
    IntLiteral::IntLiteral(int val): value(val) {}

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
    Literal& IntLiteral::operator-(Literal& rhs)
    {
        return rhs.sub_operator(this);
    }
    Literal& IntLiteral::operator*(Literal& rhs)
    {
        return rhs.mul_operator(this);
    }
    Literal& IntLiteral::operator/(Literal& rhs)
    {
        return rhs.div_operator(this);
    }

    Literal& IntLiteral::add_operator(IntLiteral* rhs)
    {
        auto temp = new IntLiteral(rhs->value + this->value);
        return *temp;
    }
    Literal& IntLiteral::sub_operator(IntLiteral* rhs)
    {
        auto temp = new IntLiteral(rhs->value - this->value);
        return *temp;
    }
    Literal& IntLiteral::mul_operator(IntLiteral* rhs)
    {
        auto temp = new IntLiteral(rhs->value * this->value);
        return *temp;
    }
    Literal& IntLiteral::div_operator(IntLiteral* rhs)
    {
        auto temp = new IntLiteral(rhs->value / this->value);
        return *temp;
    }

    Literal& IntLiteral::add_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value + this->value);
        return *temp;
    }
    Literal& IntLiteral::sub_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value - this->value);
        return *temp;
    }
    Literal& IntLiteral::mul_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value * this->value);
        return *temp;
    }
    Literal& IntLiteral::div_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value / this->value);
        return *temp;
    }
}
