//
// Created by sovereign on 10/13/19.
//

#include "LiteralTypes.h"
#include <string>

namespace TYPES {

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
}