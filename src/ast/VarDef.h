#ifndef VARDEF_H_INCLUDED
#define VARDEF_H_INCLUDED

#include <utility>
#include <string>

namespace AST
{
class Expression;

class VarDef
{
public:
    std::pair<std::string, Expression*> variable;
public:
    VarDef(const char*, Expression*);
};
}

#endif // VARDEF_H_INCLUDED
