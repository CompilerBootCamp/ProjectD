#include "ArrayLiteral.h"
#include "ExpressionList.h"

namespace AST
{

ArrayLiteral::ArrayLiteral():_size(0) {}

ArrayLiteral::ArrayLiteral(ExpressionList* expr_list)
{
    for(size_t i = 0; i < expr_list->expressions.size(); ++i)
    {
        array.insert(std::make_pair(i, expr_list->expressions[i]));
        _size++;
    }
}

Literal& ArrayLiteral::evaluate()
{
    return *this;
}

size_t ArrayLiteral::size()
{
    return _size;
}

std::string ArrayLiteral::to_string()
{
    std:: string result = "[";
    for(size_t i = 0; i < size(); ++i)
    {
        if(array.find(i) != array.end())
            result += array[i]->evaluate().to_string();
        else
            result += "empty";
        if(i != size() - 1)
            result += ", ";
    }
    result += "]";
    return result;
}

Literal& ArrayLiteral::operator+(Literal& rhs)
{
    return rhs.concat(this);
}

Literal& ArrayLiteral::concat(ArrayLiteral* rhs)
    {
        //rhs->value + this->value
        auto temp = new ArrayLiteral();
        temp->_size = rhs->size() + this->size();
        for(auto element : rhs->array)
            temp->array.insert(element);
        for(auto element : this->array)
            temp->array.insert(std::make_pair(element.first + rhs->size(),element.second));

        return *temp;
    }

    TYPES::Type ArrayLiteral::getType() const {
        return TYPES::ARRAY;
    }
}
