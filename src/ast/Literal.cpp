//
// Created by sovereign on 10/6/19.
//

#include "Literal.h"

namespace AST
{

    std::string Literal::to_string()
    {
        return "empty";
    }

    Literal& Literal::evaluate()
    {
        //exception
    }

    Literal& Literal::operator+(Literal& rhs)
    {
        //exception
    }

    Literal& Literal::add_operator(IntLiteral* rhs)
    {
        //exception
    }

}
