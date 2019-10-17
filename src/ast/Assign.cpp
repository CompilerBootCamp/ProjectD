
#include "Assign.h"
#include "../visitor/AbstractVisitor.h"

namespace AST
{
Assign::Assign(Expression* ref_var, Expression* expr):ref_variable(ref_var), expression(expr)
{

}
void Assign::accept(AbstractVisitor &visitor) const
{
    visitor.visit(*this);
}
}
