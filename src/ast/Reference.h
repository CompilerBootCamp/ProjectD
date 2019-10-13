//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_REFERENCE_H
#define PROJECTD_REFERENCE_H

#include "Expression.h"
#include "../type_system/LiteralTypes.h"
#include <vector>

namespace AST{

    class ReferenceTail;

    class Reference: public Expression
    {
    public:
        std::string s_id;
        TYPES::Type type;
        std::vector<ReferenceTail*> reference_tail;

    public:

        Reference(const char*);

        void accept(AbstractVisitor &) const;

        TYPES::Type getType() const;

        void setType(TYPES::Type type);

        void add_reference(ReferenceTail*) override;

        Literal& evaluate() override;
    };
}


#endif //PROJECTD_REFERENCE_H
