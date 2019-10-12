//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_LITERAL_H
#define PROJECTD_LITERAL_H

#include "Expression.h"
#include <string>

namespace AST
{
    class IntLiteral;
    class RealLiteral;
    class BooleanLiteral;
    class StringLiteral;
    class ArrayLiteral;

    class Literal: public Expression
    {
    public:
        virtual ~Literal() = default;
        virtual std::string to_string();
        virtual AST::Literal& evaluate();

        virtual Literal& operator+(Literal&);
        virtual Literal& operator-(Literal&);
        virtual Literal& operator*(Literal&);
        virtual Literal& operator/(Literal&);

        virtual Literal& operator&&(Literal&);
        virtual Literal& operator||(Literal&);
        virtual Literal& operator^(Literal&);

        virtual bool operator<(Literal&);
        virtual bool operator>(Literal&);
        virtual bool operator<=(Literal&);
        virtual bool operator>=(Literal&);
        virtual bool operator==(Literal&);
        virtual bool operator!=(Literal&);
        virtual bool operator!();

        //IntLiteral operations
        virtual Literal& add_operator(IntLiteral*);
        virtual Literal& sub_operator(IntLiteral*);
        virtual Literal& mul_operator(IntLiteral*);
        virtual Literal& div_operator(IntLiteral*);

        virtual bool less_operator(IntLiteral*);
        virtual bool great_operator(IntLiteral*);
        virtual bool lesseq_operator(IntLiteral*);
        virtual bool greateq_operator(IntLiteral*);
        virtual bool eq_operator(IntLiteral*);
        virtual bool neq_operator(IntLiteral*);

        //RealLiteral operations
        virtual Literal& add_operator(RealLiteral*);
        virtual Literal& sub_operator(RealLiteral*);
        virtual Literal& mul_operator(RealLiteral*);
        virtual Literal& div_operator(RealLiteral*);

        virtual bool less_operator(RealLiteral*);
        virtual bool great_operator(RealLiteral*);
        virtual bool lesseq_operator(RealLiteral*);
        virtual bool greateq_operator(RealLiteral*);
        virtual bool eq_operator(RealLiteral*);
        virtual bool neq_operator(RealLiteral*);

        //BooleanLiteral
        virtual Literal& and_operator(BooleanLiteral*);
        virtual Literal& or_operator(BooleanLiteral*);
        virtual Literal& xor_operator(BooleanLiteral*);

        //StringLiteral
        virtual Literal& add_operator(StringLiteral*);

        //ArrayLiteral
        virtual Literal& concat(ArrayLiteral*);
    };
}


#endif //PROJECTD_LITERAL_H
