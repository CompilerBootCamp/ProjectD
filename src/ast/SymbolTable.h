#ifndef SYMBOLTABLE_H_INCLUDED
#define SYMBOLTABLE_H_INCLUDED

#include<map>

namespace AST
{
class Literal;
}

class SymbolTable
{
public:
    static std::map<std::string, AST::Literal*> symbol_table;
};
#endif // SYMBOLTABLE_H_INCLUDED
