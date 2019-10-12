//
// Created by sovereign on 10/13/19.
//

#include "LiteralTypes.h"
#include <string>

namespace TYPES {

    std::string type_to_string(const Type type) {
        std::map<Type, std::string> typeMap;
        typeMap[_ARRAY] =  "Array";
        typeMap[_TUPLE] = "Tuple";
        typeMap[_INT] = "Int";
        typeMap[_REAL] = "Real";
        typeMap[_BOOL] = "Bool";
        typeMap[_STRING] = "String";
        typeMap[_FUNCTION] = "Function";
        typeMap[_NOTHING] = "Nothing";
        return typeMap[type];
    }
}
