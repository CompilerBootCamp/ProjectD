//
// Created by sovereign on 10/13/19.
//

#include "TypeIndicator.h"
#include "BooleanLiteral.h"
#include "Reference.h"

namespace AST{
Literal &TypeIndicator::evaluate() {
    auto result = new BooleanLiteral(this->reference->getType() == getType()); //fixme
    return *result;
}



Expression *TypeIndicator::getReference() const {
    return reference;
}

void TypeIndicator::setReference(Expression *reference) {
    TypeIndicator::reference = reference;
}

TYPES::Type TypeIndicator::getType() const {
    return type;
}

void TypeIndicator::setType(TYPES::Type type) {
    TypeIndicator::type = type;
}

TypeIndicator::TypeIndicator(Expression *reference, TYPES::Type type) : reference(reference), type(type) {}
}
