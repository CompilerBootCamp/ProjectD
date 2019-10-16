//
// Created by sovereign on 10/16/19.
//

#include "Scope.h"

Scope::Scope()
{
}


AST::Literal* Scope::find_in_scope(std::string name) {
    if(symbols.find(name) != symbols.end())
        return symbols[name];
    else{
        if(topScope == nullptr)
            return nullptr;
        else
            return topScope->find_in_scope(name);
    }
}