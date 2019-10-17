#ifndef TUPLEELEMENT_H_INCLUDED
#define TUPLEELEMENT_H_INCLUDED

#include<utility>
#include<string>

namespace AST
{
    class Expression;
    class Literal;

    class TupleElement
    {
    public:
        std::pair<std::string, Literal*> element;
    public:
        TupleElement(const char*, Expression*);
    };
}

#endif // TUPLEELEMENT_H_INCLUDED
