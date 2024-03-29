#include "TupleElement.h"
#include "Expression.h"
#include "Literal.h"

namespace AST{

TupleElement::TupleElement(const char* id, Expression* expr)
{
    element = make_pair(std::string(id), &expr->evaluate());
}
}
