#include "TupleLiteral.h"
#include "TupleElementList.h"
#include <sstream>

namespace AST{

TupleLiteral::TupleLiteral(TupleElementList* tul)
{
    tu_list = tul;
}
TupleLiteral::TupleLiteral()
{
    tu_list = new AST::TupleElementList();
}

Literal& TupleLiteral::evaluate()
{
    return *this;
}

std::string TupleLiteral::to_string()
{
    std:: string result = "{";

    for(size_t i = 0; i < tu_list->elements.size(); ++i)
    {
        std::stringstream ss(tu_list->elements[i].first);
        int index;
        if((ss>>index).fail())
            result += tu_list->elements[i].first + "=" + tu_list->elements[i].second->evaluate().to_string();
        else
            result += tu_list->elements[i].second->evaluate().to_string();
        if(i != tu_list->elements.size() - 1)
            result += ", ";
    }
    result += "}";
    return result;
}

}
