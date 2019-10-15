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

        [[nodiscard]] TYPES::Type getType() override;

        Literal& evaluate() override;
        Literal& operator+(Literal& rhs) override;
        Literal& operator-(Literal& rhs) override;
        Literal& operator*(Literal& rhs) override;
        Literal& operator/(Literal& rhs) override;

        bool operator<(Literal&) override;
        bool operator>(Literal&) override;
        bool operator<=(Literal&) override;
        bool operator>=(Literal&) override;
        bool operator==(Literal&) override;
        bool operator!=(Literal&) override;

        //IntLiterals
        Literal& add_operator(IntLiteral*) override;
        Literal& sub_operator(IntLiteral*) override;
        Literal& mul_operator(IntLiteral*) override;
        Literal& div_operator(IntLiteral*) override;

        bool less_operator(IntLiteral*) override;
        bool great_operator(IntLiteral*) override;
        bool lesseq_operator(IntLiteral*) override;
        bool greateq_operator(IntLiteral*) override;
        bool eq_operator(IntLiteral*) override;
        bool neq_operator(IntLiteral*) override;

        //RealLiterals
        Literal& add_operator(RealLiteral*) override;
        Literal& sub_operator(RealLiteral*) override;
        Literal& mul_operator(RealLiteral*) override;
        Literal& div_operator(RealLiteral*) override;

        bool less_operator(RealLiteral*) override;
        bool great_operator(RealLiteral*) override;
        bool lesseq_operator(RealLiteral*) override;
        bool greateq_operator(RealLiteral*) override;
        bool eq_operator(RealLiteral*) override;
        bool neq_operator(RealLiteral*) override;
    };
}

#endif // REALLITERAL_H_INCLUDED
