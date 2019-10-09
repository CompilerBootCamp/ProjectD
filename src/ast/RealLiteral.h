#ifndef REALLITERAL_H_INCLUDED
#define REALLITERAL_H_INCLUDED

#include "Literal.h"

namespace AST{

    class RealLiteral: public Literal
    {
    public:
        double value;
    public:
        RealLiteral(double);
        std::string to_string() override;

        Literal& evaluate() override;
        Literal& operator+(Literal& rhs) override;
        Literal& operator-(Literal& rhs) override;
        Literal& operator*(Literal& rhs) override;
        Literal& operator/(Literal& rhs) override;

        Literal& add_operator(IntLiteral*) override;
        Literal& sub_operator(IntLiteral*) override;
        Literal& mul_operator(IntLiteral*) override;
        Literal& div_operator(IntLiteral*) override;

        Literal& add_operator(RealLiteral*) override;
        Literal& sub_operator(RealLiteral*) override;
        Literal& mul_operator(RealLiteral*) override;
        Literal& div_operator(RealLiteral*) override;
    };
}

#endif // REALLITERAL_H_INCLUDED
