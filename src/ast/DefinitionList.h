#ifndef DEFINITIONLIST_H_INCLUDED
#define DEFINITIONLIST_H_INCLUDED

#include "Statement.h"
#include <vector>

namespace AST{

class VarDef;

class DefinitionList: public Statement
{
public:
    std::vector<VarDef*> var_list;
public:
    DefinitionList();
    DefinitionList(VarDef*);

    void add_defenition(VarDef*);
    void accept(AbstractVisitor&) const;
};
}

#endif // DEFINITIONLIST_H_INCLUDED
