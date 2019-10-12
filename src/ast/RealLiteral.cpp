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

    bool RealLiteral::operator<(Literal& rhs)
    {
        return rhs.less_operator(this);
    }
    bool RealLiteral::operator>(Literal& rhs)
    {
        return rhs.great_operator(this);
    }
    bool RealLiteral::operator<=(Literal& rhs)
    {
        return rhs.lesseq_operator(this);
    }
    bool RealLiteral::operator>=(Literal& rhs)
    {
        return rhs.greateq_operator(this);
    }
    bool RealLiteral::operator==(Literal& rhs)
    {
        return rhs.eq_operator(this);
    }
    bool RealLiteral::operator!=(Literal& rhs)
    {
        return rhs.neq_operator(this);
    }

    //IntLiterals
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

    bool RealLiteral::less_operator(IntLiteral* rhs)
    {
        return rhs->value < this->value;
    }
    bool RealLiteral::great_operator(IntLiteral* rhs)
    {
        return rhs->value > this->value;
    }
    bool RealLiteral::lesseq_operator(IntLiteral* rhs)
    {
        return rhs->value <= this->value;
    }
    bool RealLiteral::greateq_operator(IntLiteral* rhs)
    {
        return rhs->value >= this->value;
    }
    bool RealLiteral::eq_operator(IntLiteral* rhs)
    {
        return rhs->value == this->value;
    }
    bool RealLiteral::neq_operator(IntLiteral* rhs)
    {
        return rhs->value != this->value;
    }

    //RealLiterals
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

    bool RealLiteral::less_operator(RealLiteral* rhs)
    {
        return rhs->value < this->value;
    }
    bool RealLiteral::great_operator(RealLiteral* rhs)
    {
        return rhs->value > this->value;
    }
    bool RealLiteral::lesseq_operator(RealLiteral* rhs)
    {
        return rhs->value <= this->value;
    }
    bool RealLiteral::greateq_operator(RealLiteral* rhs)
    {
        return rhs->value >= this->value;
    }
    bool RealLiteral::eq_operator(RealLiteral* rhs)
    {
        return rhs->value == this->value;
    }
    bool RealLiteral::neq_operator(RealLiteral* rhs)
    {
        return rhs->value != this->value;
    }

    TYPES::Type RealLiteral::getType() const {
        return TYPES::_REAL;
    }
}
