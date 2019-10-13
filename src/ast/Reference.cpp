//
// Created by sovereign on 10/6/19.
//

#include "Reference.h"
#include "../visitor/AbstractVisitor.h"
#include "Literal.h"
#include "SymbolTable.h"
#include "ReferenceTail.h"
#include "TupleLiteral.h"
#include "StringLiteral.h"
#include "ArrayLiteral.h"
#include "ExpressionList.h"
#include "Expression.h"
#include "IntLiteral.h"
#include "TupleElementList.h"
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
    return SymbolTable::symbol_table[s_id]->getType();
}

void Reference::setType(TYPES::Type type)
{
    Reference::type = type;
}

void Reference::add_reference(ReferenceTail* rt)
{
    reference_tail.push_back(rt);
}

Literal& Reference::evaluate()
{
    auto value = SymbolTable::symbol_table[s_id];
    bool exception = false;
    for(auto ref: reference_tail)
    {
        if(exception)
            break;

        switch(ref->reference_list.second)
        {
        case TYPES::_ARRAY:
        {
            auto arr = static_cast<ArrayLiteral*>(value);
            auto index = static_cast<IntLiteral*>(ref->reference_list.first->expressions[0])->value;
            if(index < arr->array.size())
                value = static_cast<Literal*>(arr ->array[index]);
            else
            {
                //esception
                value = new Literal();
                exception = true;
            }
            break;
        }
        case TYPES::_TUPLE:
        {
            //std::cout << "value: " << value->to_string() << std::endl;
            try
            {
                auto tuple = static_cast<TupleLiteral*>(value);
                auto key = static_cast<StringLiteral*>(ref->reference_list.first->expressions[0])->value;
                auto tuple_elements = tuple->tu_list->elements;
                auto it = std::find_if(tuple_elements.begin(), tuple_elements.end(),
                                       [&key](std::pair<std::string, Expression*>&element)
                {
                    return element.first == key;
                });
                if(it != tuple_elements.end())
                {
                    value = static_cast<Literal*>((*it).second);
                }
                else
                {
                    //exception
                    value = new Literal();
                    exception = true;
                }
            }
            catch(...)
            {
                std::cout << "not here";
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
