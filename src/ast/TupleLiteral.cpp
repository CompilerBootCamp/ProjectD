#include "TupleLiteral.h"
#include "TupleElementList.h"
#include <sstream>

namespace AST
{

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

Literal& TupleLiteral::operator+(Literal& rhs)
{
    return rhs.concat(this);
}

Literal& TupleLiteral::concat(TupleLiteral* rhs)
{
    //rhs->value + this->value
    auto temp = new TupleLiteral();
    temp->tu_list->elements = rhs->tu_list->elements;
    for(auto element : this->tu_list->elements)
    {
        std::stringstream ss(element.first);
        int index;
        if(!(ss>>index).fail())
            temp->tu_list->elements.push_back(make_pair(std::to_string(temp->tu_list->elements.size()), element.second));
        else
            temp->tu_list->elements.push_back(make_pair(element.first, element.second));
    }
    return *temp;
}

}
