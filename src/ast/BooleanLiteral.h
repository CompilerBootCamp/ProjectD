#ifndef BOOLEANLITERAL_H_INCLUDED
#define BOOLEANLITERAL_H_INCLUDED

#include "Literal.h"

namespace AST{

    class BooleanLiteral: public Literal
    {
    public:
        bool value;
    public:
        BooleanLiteral(bool);
        std::string to_string() override;

        Literal& evaluate() override;
        Literal& operator&&(Literal& rhs) override;
        Literal& operator||(Literal& rhs) override;
        Literal& operator^(Literal& rhs) override;

        Literal& and_operator(BooleanLiteral*) override;
        Literal& or_operator(BooleanLiteral*) override;
        Literal& xor_operator(BooleanLiteral*) override;
    };
}

#endif // BOOLEANLITERAL_H_INCLUDED
