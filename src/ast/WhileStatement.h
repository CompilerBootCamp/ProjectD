//
// Created by sovereign on 10/13/19.
//

#ifndef PROJECTD_WHILESTATEMENT_H
#define PROJECTD_WHILESTATEMENT_H

#include "Statement.h"

namespace AST {

    class Expression;
    class StatementList;


    class WhileStatement : public Statement {
    private:
        Expression* expression;
        StatementList* whileStatement;
    public:
        WhileStatement(Expression *expression, StatementList *whileStatement);

        void accept(AbstractVisitor &visitor) const override;

        [[nodiscard]] Expression *getExpression() const;

        void setExpression(Expression *expression);

        [[nodiscard]] StatementList *getWhileStatement() const;

        void setWhileStatement(StatementList *whileStatement);
    };
}


#endif //PROJECTD_WHILESTATEMENT_H
