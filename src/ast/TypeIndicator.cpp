//
// Created by sovereign on 10/13/19.
//

#include "TypeIndicator.h"
#include "BooleanLiteral.h"

AST::Literal &AST::TypeIndicator::evaluate() {
//    return AST::BooleanLiteral(this->reference->getType() == getType()); //fixme
}



AST::Reference *AST::TypeIndicator::getReference() const {
    return reference;
}

void AST::TypeIndicator::setReference(AST::Reference *reference) {
    TypeIndicator::reference = reference;
}

TYPES::Type AST::TypeIndicator::getType() const {
    return type;
}

void AST::TypeIndicator::setType(TYPES::Type type) {
    TypeIndicator::type = type;
}

AST::TypeIndicator::TypeIndicator(AST::Reference *reference, TYPES::Type type) : reference(reference), type(type) {}
