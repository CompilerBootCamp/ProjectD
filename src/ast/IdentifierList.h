//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_IDENTIFIERLIST_H
#define PROJECTD_IDENTIFIERLIST_H

#include <vector>
#include <string>


namespace AST{

    class IdentifierList {
    private:
        std::vector<std::string> identifiers;

    public:
        IdentifierList(const char* identifiers);

        [[nodiscard]] const std::vector<std::string> &getIdentifiers() const;

        void addIdentifier(const char* identifier);
    };
}


#endif //PROJECTD_IDENTIFIERLIST_H
