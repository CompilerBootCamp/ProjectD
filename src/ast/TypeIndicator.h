//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_TYPEINDICATOR_H
#define PROJECTD_TYPEINDICATOR_H

#include "Expression.h"

namespace AST{
    class Reference;

    class TypeIndicator: public Expression {

    private:
        Expression* reference;
        TYPES::Type type;
    public:

        TypeIndicator(Expression *reference, TYPES::Type type);

        Literal &evaluate() override;

        [[nodiscard]] Expression *getReference() const;

        void setReference(Expression *reference);

        [[nodiscard]] TYPES::Type getType() const;

        void setType(TYPES::Type type);

        void accept(AbstractVisitor&) const;
    };
}

#endif //PROJECTD_TYPEINDICATOR_H
