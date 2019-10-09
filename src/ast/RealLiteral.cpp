#include "RealLiteral.h"
#include "IntLiteral.h"

namespace AST
{
    RealLiteral::RealLiteral(double val): value(val) {}

    std::string RealLiteral::to_string()
    {
        return std::to_string(value);
    }

    Literal& RealLiteral::evaluate()
    {
        return *this;
    }

    Literal& RealLiteral::operator+(Literal& rhs)
    {
        return rhs.add_operator(this);
    }
    Literal& RealLiteral::operator-(Literal& rhs)
    {
        return rhs.sub_operator(this);
    }
    Literal& RealLiteral::operator*(Literal& rhs)
    {
        return rhs.mul_operator(this);
    }
    Literal& RealLiteral::operator/(Literal& rhs)
    {
        return rhs.div_operator(this);
    }

    Literal& RealLiteral::add_operator(IntLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value + this->value);
        return *temp;
    }
    Literal& RealLiteral::sub_operator(IntLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value - this->value);
        return *temp;
    }
    Literal& RealLiteral::mul_operator(IntLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value * this->value);
        return *temp;
    }
    Literal& RealLiteral::div_operator(IntLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value / this->value);
        return *temp;
    }

    Literal& RealLiteral::add_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value + this->value);
        return *temp;
    }
    Literal& RealLiteral::sub_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value - this->value);
        return *temp;
    }
    Literal& RealLiteral::mul_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value * this->value);
        return *temp;
    }
    Literal& RealLiteral::div_operator(RealLiteral* rhs)
    {
        auto temp = new RealLiteral(rhs->value / this->value);
        return *temp;
    }
}
