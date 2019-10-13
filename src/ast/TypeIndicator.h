//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_TYPEINDICATOR_H
#define PROJECTD_TYPEINDICATOR_H

#include "Literal.h"

namespace AST{
    class Reference;

    class TypeIndicator: public Literal {

    private:
        Reference* reference;
        TYPES::Type type;
    public:

        TypeIndicator(Reference *reference, TYPES::Type type);

        Literal &evaluate() override;

        [[nodiscard]] Reference *getReference() const;

        void setReference(Reference *reference);

        [[nodiscard]] TYPES::Type getType() const;

        void setType(TYPES::Type type);
    };
}

#endif //PROJECTD_TYPEINDICATOR_H
