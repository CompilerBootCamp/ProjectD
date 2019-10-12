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

    bool IntLiteral::operator<(Literal& rhs)
    {
        return rhs.less_operator(this);
    }
    bool IntLiteral::operator>(Literal& rhs)
    {
        return rhs.great_operator(this);
    }
    bool IntLiteral::operator<=(Literal& rhs)
    {
        return rhs.lesseq_operator(this);
    }
    bool IntLiteral::operator>=(Literal& rhs)
    {
        return rhs.greateq_operator(this);
    }
    bool IntLiteral::operator==(Literal& rhs)
    {
        return rhs.eq_operator(this);
    }
    bool IntLiteral::operator!=(Literal& rhs)
    {
        return rhs.neq_operator(this);
    }

    //IntLiterals
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

    bool IntLiteral::less_operator(IntLiteral* rhs)
    {
        return rhs->value < this->value;
    }
    bool IntLiteral::great_operator(IntLiteral* rhs)
    {
        return rhs->value > this->value;
    }
    bool IntLiteral::lesseq_operator(IntLiteral* rhs)
    {
        return rhs->value <= this->value;
    }
    bool IntLiteral::greateq_operator(IntLiteral* rhs)
    {
        return rhs->value >= this->value;
    }
    bool IntLiteral::eq_operator(IntLiteral* rhs)
    {
        return rhs->value == this->value;
    }
    bool IntLiteral::neq_operator(IntLiteral* rhs)
    {
        return rhs->value != this->value;
    }

    //RealLiterals
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

    bool IntLiteral::less_operator(RealLiteral* rhs)
    {
        return rhs->value < this->value;
    }
    bool IntLiteral::great_operator(RealLiteral* rhs)
    {
        return rhs->value > this->value;
    }
    bool IntLiteral::lesseq_operator(RealLiteral* rhs)
    {
        return rhs->value <= this->value;
    }
    bool IntLiteral::greateq_operator(RealLiteral* rhs)
    {
        return rhs->value >= this->value;
    }
    bool IntLiteral::eq_operator(RealLiteral* rhs)
    {
        return rhs->value == this->value;
    }
    bool IntLiteral::neq_operator(RealLiteral* rhs)
    {
        return rhs->value != this->value;
    }

}
