//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_FUNCTIONLITERAL_H
#define PROJECTD_FUNCTIONLITERAL_H


#include "Literal.h"
#include <vector>
#include <string>

namespace AST{

    class StatementList;
    class IdentifierList;
    class Expression;
    class FuncBody;

    class FunctionLiteral: public Literal {
    private:
        StatementList* statementList;
        Expression* expression;
        std::vector<std::string> identifierList;
    public:
        FunctionLiteral(FuncBody*);
        FunctionLiteral(IdentifierList*, FuncBody*);

        [[nodiscard]] StatementList *getStatementList() const;

        void setStatementList(StatementList *statementList);

        [[nodiscard]] Expression *getExpression() const;

        void setExpression(Expression *expression);

        [[nodiscard]] IdentifierList *getIdentifierList() const;

        void setIdentifierList(IdentifierList *identifierList);

        [[nodiscard]] TYPES::Type getType() override;
    };
}

#endif //PROJECTD_FUNCTIONLITERAL_H
