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

    class Literal: public Expression
    {
    public:
        virtual ~Literal() = default;
        virtual std::string to_string();
        virtual AST::Literal& evaluate();

        virtual Literal& operator+(Literal& rhs);
        virtual Literal& operator-(Literal& rhs);
        virtual Literal& operator*(Literal& rhs);
        virtual Literal& operator/(Literal& rhs);

        //IntLiteral operations
        virtual Literal& add_operator(IntLiteral*);
        virtual Literal& sub_operator(IntLiteral*);
        virtual Literal& mul_operator(IntLiteral*);
        virtual Literal& div_operator(IntLiteral*);

        //RealLiteral operations
        virtual Literal& add_operator(RealLiteral*);
        virtual Literal& sub_operator(RealLiteral*);
        virtual Literal& mul_operator(RealLiteral*);
        virtual Literal& div_operator(RealLiteral*);
    };
}


#endif //PROJECTD_LITERAL_H
