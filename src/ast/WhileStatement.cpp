//
// Created by sovereign on 10/13/19.
//

#include "WhileStatement.h"
#include "../visitor/AbstractVisitor.h"

void AST::WhileStatement::accept(AbstractVisitor &visitor) const {
    visitor.visit(*this);
}

AST::Expression *AST::WhileStatement::getExpression() const {
    return expression;
}

void AST::WhileStatement::setExpression(AST::Expression *expression) {
    WhileStatement::expression = expression;
}

AST::StatementList *AST::WhileStatement::getWhileStatement() const {
    return whileStatement;
}

void AST::WhileStatement::setWhileStatement(AST::StatementList *whileStatement) {
    WhileStatement::whileStatement = whileStatement;
}

AST::WhileStatement::WhileStatement(AST::Expression *expression, AST::StatementList *whileStatement) : expression(
        expression), whileStatement(whileStatement) {}
