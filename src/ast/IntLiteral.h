#ifndef INTLITERAL_H_INCLUDED
#define INTLITERAL_H_INCLUDED

#include "Literal.h"

class IntLiteral: public Literal {
public:
    int value;
public:
    IntLiteral(int);
    std::string to_string() override;

    Literal& evaluate() override;
    Literal& operator+(Literal& rhs) override;
    Literal& add_operator(IntLiteral*) override;
};

#endif // INTLITERAL_H_INCLUDED
