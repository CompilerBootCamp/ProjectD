//
// Created by sovereign on 10/6/19.
//

#ifndef PROJECTD_IFSTATEMENT_H
#define PROJECTD_IFSTATEMENT_H

#include "Statement.h"

namespace AST {

    class Expression;
    class ExpressionList;
    class StatementList;

    class IfStatement: public  Statement {
    private:
        Expression* expression;
        StatementList* thenStatements;
        StatementList* elseStatements;
        bool elseIf;

    public:
        IfStatement(Expression *expression, StatementList *thenStatements, StatementList *elseStatements);

        IfStatement(Expression *expression, StatementList *thenStatements);

        void accept(AbstractVisitor &visitor) const override;

        StatementList *getThenStatements() const;

        void setThenStatements(StatementList *thenStatements);

        StatementList *getElseStatements() const;

        void setElseStatements(StatementList *elseStatements);

        Expression *getExpression() const;

        void setExpression(Expression *expression);

        bool isElseIf() const;

        void setElseIf(bool elseIf);
    };
}


#endif //PROJECTD_IFSTATEMENT_H
