//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_FUNCTIONLITERAL_H
#define PROJECTD_FUNCTIONLITERAL_H


#include "Literal.h"

namespace AST{

    class StatementList;
    class IdentifierList;
    class Expression;

    class FunctionLiteral: public Literal {
    private:
        StatementList* statementList;
        Expression* expression;
        IdentifierList* identifierList;
    public:
        FunctionLiteral(StatementList *statementList, Expression *expression, IdentifierList *identifierList);

        [[nodiscard]] StatementList *getStatementList() const;

        void setStatementList(StatementList *statementList);

        [[nodiscard]] Expression *getExpression() const;

        void setExpression(Expression *expression);

        [[nodiscard]] IdentifierList *getIdentifierList() const;

        void setIdentifierList(IdentifierList *identifierList);

        [[nodiscard]] TYPES::Type getType() const override;
    };
}

#endif //PROJECTD_FUNCTIONLITERAL_H
