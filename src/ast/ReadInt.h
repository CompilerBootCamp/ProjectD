//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READINT_H
#define PROJECTD_READINT_H

#include "Expression.h"

namespace AST {

    class ReadInt : public Expression {
    public:
        ReadInt();

        Literal &evaluate() override;
    };
}


#endif //PROJECTD_READINT_H
