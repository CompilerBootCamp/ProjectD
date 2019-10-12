//
// Created by sovereign on 10/6/19.
//

#include "IfStatement.h"
#include "../visitor/AbstractVisitor.h"

namespace AST {

    void IfStatement::accept(AbstractVisitor &visitor) const {
        visitor.visit(*this);
    }

    IfStatement::IfStatement(Expression *expression, StatementList *thenStatements, StatementList *elseStatements)
            : expression(expression), thenStatements(thenStatements), elseStatements(elseStatements), elseIf(true) {}

    StatementList *IfStatement::getThenStatements() const {
        return thenStatements;
    }

    void IfStatement::setThenStatements(StatementList *thenStatements) {
        IfStatement::thenStatements = thenStatements;
    }

    StatementList *IfStatement::getElseStatements() const {
        return elseStatements;
    }

    void IfStatement::setElseStatements(StatementList *elseStatements) {
        IfStatement::elseStatements = elseStatements;
    }

    Expression *IfStatement::getExpression() const {
        return expression;
    }

    void IfStatement::setExpression(Expression *expression) {
        IfStatement::expression = expression;
    }

    IfStatement::IfStatement(Expression *expression, StatementList *thenStatements) : expression(expression),
                                                                                      thenStatements(thenStatements), elseIf(false) {}

    bool IfStatement::isElseIf() const {
        return elseIf;
    }

    void IfStatement::setElseIf(bool elseIf) {
        IfStatement::elseIf = elseIf;
    }
}
