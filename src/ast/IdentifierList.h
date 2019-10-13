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
        IdentifierList(std::vector<std::string> identifiers);

        [[nodiscard]] const std::vector<std::string> &getIdentifiers() const;

        void setIdentifiers(const std::vector<std::string> &identifiers);

        void addIdentifier(const std::string &identifier);
    };
}


#endif //PROJECTD_IDENTIFIERLIST_H
