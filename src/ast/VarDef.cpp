#include "VarDef.h"


namespace AST{

VarDef::VarDef(const char* name, Expression* value)
{
    variable = make_pair(std::string(name), value);
}
}
