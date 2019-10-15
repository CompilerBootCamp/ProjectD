#include "TupleLiteral.h"
#include "TupleElementList.h"
#include <sstream>
#include <iostream>

namespace AST
{

TupleLiteral::TupleLiteral(TupleElementList* tul)
{
    tu_list = tul->elements;
}

TupleLiteral::TupleLiteral()
{
}

Literal& TupleLiteral::evaluate()
{
    return *this;
}

std::string TupleLiteral::to_string()
{
    std:: string result = "{";

    for(size_t i = 0; i < tu_list.size(); ++i)
    {
        std::stringstream ss(tu_list[i].first);
        int index;
        if((ss>>index).fail())
            result += tu_list[i].first + "=" + tu_list[i].second->evaluate().to_string();
        else
            result += tu_list[i].second->evaluate().to_string();
        if(i != tu_list.size() - 1)
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
    temp->tu_list = rhs->tu_list;
    for(auto element : this->tu_list)
    {
        std::stringstream ss(element.first);
        int index;
        if(!(ss>>index).fail())
            temp->tu_list.push_back(make_pair(std::to_string(temp->tu_list.size()), element.second));
        else
            temp->tu_list.push_back(make_pair(element.first, element.second));
    }
    return *temp;
}

Expression* TupleLiteral::get_value(std::string key)
{
    std::stringstream ss(key);
    int index;
    if((ss>>index).fail())
    {
        for(auto element : tu_list)
            if(element.first == key)
                return element.second;
        //exception
        std::cout << "tuple key: " + key + " not exist" << std::endl;
        return nullptr;
    }
    else
    {
        if(index < tu_list.size())
            return tu_list[index].second;
        //exception
        std::cout << "index of tuple out of range" << std::endl;
        return nullptr;
    }
}

TYPES::Type TupleLiteral::getType()
{
    return TYPES::_TUPLE;
}

}
