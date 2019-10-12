//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_STRINGLITERAL_H
#define PROJECTD_STRINGLITERAL_H

#include <string>
#include "Literal.h"

namespace AST{

    class StringLiteral: public Literal
    {
    public:
        std::string value;
    public:
        StringLiteral(char*);
        StringLiteral(std::string);
        std::string to_string() override;

        [[nodiscard]] TYPES::Type getType() const override;

        Literal& evaluate() override;
        Literal& operator+(Literal& rhs) override;

        Literal& add_operator(StringLiteral*) override;
    };
}



#endif //PROJECTD_STRINGLITERAL_H
