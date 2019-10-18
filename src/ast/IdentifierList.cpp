//
// Created by sovereign on 10/13/19.
//

#include "IdentifierList.h"

#include <utility>

const std::vector<std::string> &AST::IdentifierList::getIdentifiers() const {
    return identifiers;
}

void AST::IdentifierList::addIdentifier(const char* identifier) {
    this->identifiers.push_back(std::string(identifier));
}

AST::IdentifierList::IdentifierList(const char* identifier) {
    this->identifiers.push_back(std::string(identifier));
}
