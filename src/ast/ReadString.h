//
// Created by sovereign on 10/15/19.
//

#ifndef PROJECTD_READSTRING_H
#define PROJECTD_READSTRING_H

#include "Read.h"

namespace AST{

    class ReadString: public Read {

    public:

        void accept(AbstractVisitor &visitor) const override;

    };
}


#endif //PROJECTD_READSTRING_H
