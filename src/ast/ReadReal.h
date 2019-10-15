//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READREAL_H
#define PROJECTD_READREAL_H


#include "Expression.h"

namespace AST{
    class ReadReal: public Expression {

    public:

        Literal &evaluate() override;
    };

}

#endif //PROJECTD_READREAL_H
