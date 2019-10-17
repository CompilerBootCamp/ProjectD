//
// Created by sovereign on 10/16/19.
//

#ifndef PROJECTD_SCOPE_H
#define PROJECTD_SCOPE_H

#include <map>
#include <string>

namespace AST
{
    class Literal;
}

class Scope {
public:
    bool in_block = false;
    Scope* topScope = nullptr;
    std::map<std::string, AST::Literal*> symbols;
    Scope(bool);
    AST::Literal* find_in_scope(std::string);
    AST::Literal* find_only_in_scope(std::string);
};


#endif //PROJECTD_SCOPE_H
