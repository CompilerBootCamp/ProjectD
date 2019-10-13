//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_TYPEINDICATOR_H
#define PROJECTD_TYPEINDICATOR_H


#include <type_system/LiteralTypes.h>
#include "Expression.h"
#include "Reference.h"
#include "BooleanLiteral.h"

namespace AST{
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
