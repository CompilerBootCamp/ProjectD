//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READREAL_H
#define PROJECTD_READREAL_H


#include "Read.h"

namespace AST{
    class ReadReal: public Read {

    public:
        void accept(AbstractVisitor &visitor) const override;
    };

}

#endif //PROJECTD_READREAL_H
