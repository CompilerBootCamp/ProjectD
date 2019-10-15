//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READINT_H
#define PROJECTD_READINT_H

#include "Read.h"

namespace AST {


    class ReadInt : public Read {

    public:

        void accept(AbstractVisitor &visitor) const override;

    };
}


#endif //PROJECTD_READINT_H
