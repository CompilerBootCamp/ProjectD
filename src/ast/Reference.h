//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_REFERENCE_H
#define PROJECTD_REFERENCE_H

#include "Node.h"
#include "../type_system/LiteralTypes.h"

namespace AST{

    class Reference: public Node
            //todo ссылка на литерал
            //имя ноды
    {
    private:
        TYPES::Type type;

    public:

        void accept(AbstractVisitor &) const;

        TYPES::Type getType() const;

        void setType(TYPES::Type type);
    };
}


#endif //PROJECTD_REFERENCE_H
