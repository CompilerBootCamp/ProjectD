//
// Created by sovereign on 10/13/19.
//

#include "TypeIndicator.h"
#include "BooleanLiteral.h"
#include "Reference.h"
#include "../visitor/AbstractVisitor.h"

namespace AST
{
Literal &TypeIndicator::evaluate()
{
    auto result = new BooleanLiteral(this->reference->getType() == getType());
    return *result;
}

void TypeIndicator::accept(AbstractVisitor &visitor) const
{
    visitor.visit(*this);
}

Expression *TypeIndicator::getReference() const
{
    return reference;
}

void TypeIndicator::setReference(Expression *reference)
{
    TypeIndicator::reference = reference;
}

TYPES::Type TypeIndicator::getType() const
{
    return type;
}

void TypeIndicator::setType(TYPES::Type type)
{
    TypeIndicator::type = type;
}

TypeIndicator::TypeIndicator(Expression *reference, TYPES::Type type) : reference(reference), type(type) {}
}
