#ifndef DEFINITIONLIST_H_INCLUDED
#define DEFINITIONLIST_H_INCLUDED

#include "Statement.h"
#include <vector>
#include <string>

namespace AST{

class VarDef;
class Expression;

class DefinitionList: public Statement
{
public:
    std::vector<std::pair<std::string, Expression*>> var_list;
public:
    DefinitionList();
    DefinitionList(VarDef*);

    void add_defenition(VarDef*);
    void accept(AbstractVisitor&) const;
};
}

#endif // DEFINITIONLIST_H_INCLUDED
