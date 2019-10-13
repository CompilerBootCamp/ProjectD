//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_FORSTATEMENT_H
#define PROJECTD_FORSTATEMENT_H

#include "Statement.h"

namespace AST{

    class StatementList;
    class Expression;
    class VarDef;

    class ForStatement: public Statement {
    private:
        StatementList* forStatements;
        Expression* startExpression;
        Expression* endExpression;
        VarDef* def;

    public:
        ForStatement(StatementList *forStatements, Expression *expression);

        [[nodiscard]] StatementList *getForStatements() const;

        void setForStatements(StatementList *forStatements);

        void accept(AbstractVisitor &visitor) const override;

        ForStatement(StatementList *forStatements, Expression *startExpression, Expression *endExpression, const char* define);

        [[nodiscard]] Expression *getStartExpression() const;

        void setStartExpression(Expression *startExpression);

        [[nodiscard]] Expression *getEndExpression() const;

        void setEndExpression(Expression *endExpression);

        [[nodiscard]] VarDef *getDef() const;

        void setDef(VarDef *def);
    };
}


#endif //PROJECTD_FORSTATEMENT_H
