#ifndef REFERENCETAIL_H_INCLUDED
#define REFERENCETAIL_H_INCLUDED

#include "utility"
#include "../type_system/LiteralTypes.h"

namespace AST
{
class ExpressionList;

class ReferenceTail
{
public:
    std::pair<ExpressionList*, TYPES::Type> reference_list;
public:
    ReferenceTail(ExpressionList*, TYPES::Type);
    ReferenceTail();
};
}

#endif // REFERENCETAIL_H_INCLUDED
