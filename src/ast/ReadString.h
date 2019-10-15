//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READSTRING_H
#define PROJECTD_READSTRING_H

#include "Expression.h"

namespace AST{

    class ReadString: public Expression {

    public:

        Literal &evaluate() override;

    };
}


#endif //PROJECTD_READSTRING_H
