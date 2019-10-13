//
// Created by sovereign on 10/13/19.
//

#include "IdentifierList.h"

#include <utility>

const std::vector<std::string> &AST::IdentifierList::getIdentifiers() const {
    return identifiers;
}

void AST::IdentifierList::setIdentifiers(const std::vector<std::string> &new_identifiers) {
    IdentifierList::identifiers = new_identifiers;
}

void AST::IdentifierList::addIdentifier(const std::string &identifier) {
    this->identifiers.push_back(identifier);
}

AST::IdentifierList::IdentifierList(std::vector<std::string> identifiers) : identifiers(std::move(identifiers)) {}
