#include "ReferenceTail.h"

namespace AST{

ReferenceTail::ReferenceTail(ExpressionList* exprlist, TYPES::Type typ)
{

    reference_list = std::make_pair(exprlist, typ);
}
ReferenceTail::ReferenceTail()
{

}
}
