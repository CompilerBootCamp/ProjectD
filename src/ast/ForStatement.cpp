//
// Created by sovereign on 10/13/19.
//

#include "ForStatement.h"
#include "AbstractVisitor.h"
#include "VarDef.h"

AST::ForStatement::ForStatement(AST::StatementList *forStatements, AST::Expression *expression) : forStatements(
        forStatements), expression(expression) {}

AST::StatementList *AST::ForStatement::getForStatements() const {
    return forStatements;
}

void AST::ForStatement::setForStatements(AST::StatementList *forStatements) {
    ForStatement::forStatements = forStatements;
}

void AST::ForStatement::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}

AST::ForStatement::ForStatement(AST::StatementList *forStatements, AST::Expression *startExpression,
                                AST::Expression *endExpression, const char *define) : forStatements(forStatements),
                                                                                      startExpression(startExpression),
                                                                                      endExpression(endExpression) {
    def = new VarDef(define, startExpression);
}

AST::Expression *AST::ForStatement::getStartExpression() const {
    return startExpression;
}

void AST::ForStatement::setStartExpression(AST::Expression *startExpression) {
    ForStatement::startExpression = startExpression;
}

AST::Expression *AST::ForStatement::getEndExpression() const {
    return endExpression;
}

void AST::ForStatement::setEndExpression(AST::Expression *endExpression) {
    ForStatement::endExpression = endExpression;
}

AST::VarDef *AST::ForStatement::getDef() const {
    return def;
}

void AST::ForStatement::setDef(AST::VarDef *def) {
    ForStatement::def = def;
}
