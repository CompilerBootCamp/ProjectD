//
// Created by sovereign on 10/6/19.
//

#include "Reference.h"
#include "../visitor/AbstractVisitor.h"
#include "Literal.h"
#include "ReferenceTail.h"
#include "TupleLiteral.h"
#include "StringLiteral.h"
#include "ArrayLiteral.h"
#include "ExpressionList.h"
#include "Expression.h"
#include "IntLiteral.h"
#include "TupleElementList.h"
#include "Scope.h"
#include <iostream>
#include <algorithm>

namespace AST
{

Reference::Reference(const char* id): s_id(id)
{

}

void Reference::accept(AbstractVisitor &visitor) const
{
    visitor.visit(*this);
}

TYPES::Type Reference::getType() const
{
    return scope->find_in_scope(s_id)->getType();
}

void Reference::setType(TYPES::Type type)
{
    Reference::type = type;
}

void Reference::add_reference(ReferenceTail* rt)
{
    reference_tail.push_back(rt->reference_list);
}

Literal& Reference::evaluate()
{
    auto value = scope->find_in_scope(s_id);
    bool exception = false;
    for(auto ref: reference_tail)
    {
        if(exception)
            break;

        switch(ref.second)
        {
        case TYPES::_ARRAY:
        {
            auto arr = static_cast<ArrayLiteral*>(value);
            auto index = static_cast<IntLiteral*>(&ref.first->expressions[0]->evaluate())->value;
            if(index < arr->array.size()){
                value = &arr ->array[index]->evaluate();
            }
            else
            {
                //exception
                value = new Literal();
                exception = true;
            }
            break;
        }
        case TYPES::_TUPLE:
        {

            auto tuple = static_cast<TupleLiteral*>(value);
            auto key = static_cast<StringLiteral*>(ref.first->expressions[0])->value;
            auto tuple_value = tuple->get_value(key);
            if(tuple_value == nullptr)
            {
                //exception
                value = new Literal();
                exception = true;
            }
            else
            {
                value = &tuple_value->evaluate();
            }
            break;
        }
        case TYPES::_FUNCTION:
            break;
        }
    }

    return *value;
}
}
