#include "TupleElementList.h"
#include "TupleElement.h"

namespace AST{

TupleElementList::TupleElementList(TupleElement* tup)
{
    if(tup->element.first == "")
        tup->element.first = std::to_string(elements.size());
    elements.push_back(tup->element);
}

TupleElementList::TupleElementList():elements()
{

}

void TupleElementList::add_tuple_element(TupleElement* tup)
{
    if(tup->element.first == "")
        tup->element.first = std::to_string(elements.size());
    elements.push_back(tup->element);
}

}
