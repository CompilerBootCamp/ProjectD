#include "BooleanLiteral.h"

namespace AST
{
    BooleanLiteral::BooleanLiteral(bool val): value(val) {}

    std::string BooleanLiteral::to_string()
    {
        return value?"true":"false";
    }

    Literal& BooleanLiteral::evaluate()
    {
        return *this;
    }

    Literal& BooleanLiteral::operator&&(Literal& rhs)
    {
        return rhs.and_operator(this);
    }
    Literal& BooleanLiteral::operator||(Literal& rhs)
    {
        return rhs.or_operator(this);
    }
    Literal& BooleanLiteral::operator^(Literal& rhs)
    {
        return rhs.xor_operator(this);
    }
    bool BooleanLiteral::operator!()
    {
        return !this->value;
    }

    Literal& BooleanLiteral::and_operator(BooleanLiteral* rhs)
    {
        auto temp = new BooleanLiteral(rhs->value && this->value);
        return *temp;
    }
    Literal& BooleanLiteral::or_operator(BooleanLiteral* rhs)
    {
        auto temp = new BooleanLiteral(rhs->value || this->value);
        return *temp;
    }
    Literal& BooleanLiteral::xor_operator(BooleanLiteral* rhs)
    {
        auto temp = new BooleanLiteral(rhs->value ^ this->value);
        return *temp;
    }

    TYPES::Type BooleanLiteral::getType() const {
        return TYPES::_BOOL;
    }
}
