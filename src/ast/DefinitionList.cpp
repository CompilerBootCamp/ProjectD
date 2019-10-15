#include "DefinitionList.h"
#include "VarDef.h"
#include "../visitor/AbstractVisitor.h"


namespace AST{

    DefinitionList::DefinitionList()
    {
    }

    DefinitionList::DefinitionList(VarDef* var)
    {
        var_list.push_back(var->variable);
    }

    void DefinitionList::add_defenition(VarDef* var)
    {
        var_list.push_back(var->variable);
    }

    void DefinitionList::accept(AbstractVisitor &visitor) const
    {
        visitor.visit(*this);
    }
}
