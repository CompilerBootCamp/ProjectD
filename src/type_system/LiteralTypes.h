//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_LITERALTYPES_H
#define PROJECTD_LITERALTYPES_H
#include <map>
namespace TYPES {
    enum Type{
        _ARRAY,
        _TUPLE,
        _INT,
        _REAL,
        _BOOL,
        _STRING,
        _FUNCTION,
        _NOTHING
    };
    std::string type_to_string(const Type type);
}
#endif //PROJECTD_LITERALTYPES_H

