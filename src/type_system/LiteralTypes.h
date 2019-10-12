//
// Created by sovereign on 10/13/19.
//

#include <map>

#ifndef PROJECTD_LITERALTYPES_H
#define PROJECTD_LITERALTYPES_H

#endif //PROJECTD_LITERALTYPES_H

enum Type{
    ARRAY,
    TUPLE,
    INT,
    REAL,
    BOOL,
    STRING,
    FUNCTION,
    NOTHING
};

std::string type_to_string(const Type type) {
    std::map<Type, std::string> typeMap;
    typeMap[ARRAY] =  "Array";
    typeMap[TUPLE] = "Tuple";
    typeMap[INT] = "Int";
    typeMap[REAL] = "Real";
    typeMap[BOOL] = "Bool";
    typeMap[STRING] = "String";
    typeMap[FUNCTION] = "Function";
    typeMap[NOTHING] = "Nothing";
    return typeMap[type];
}