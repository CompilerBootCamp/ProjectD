//
// Created by sovereign on 10/6/19.
//

#include "Node.h"

template<class T>
void Node<T>::accept(Visitor visitor) {
    visitor.visit((T) this);
}