//
// Created by sovereign on 10/16/19.
//

#include "Scope.h"
#include "Literal.h"
#include <iostream>

Scope::Scope(bool block):in_block(block)
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

AST::Literal* Scope::find_only_in_scope(std::string name) {
    if(symbols.find(name) != symbols.end()){
        return symbols[name];
    }
    else{
        if(topScope == nullptr || in_block == true)
            return nullptr;
        else
            return topScope->find_only_in_scope(name);
    }
}
