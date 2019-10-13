//
// Created by sovereign on 10/13/19.
//

#include "FunctionLiteral.h"

AST::StatementList *AST::FunctionLiteral::getStatementList() const {
    return statementList;
}

void AST::FunctionLiteral::setStatementList(AST::StatementList *statementList) {
    FunctionLiteral::statementList = statementList;
}

AST::Expression *AST::FunctionLiteral::getExpression() const {
    return expression;
}

void AST::FunctionLiteral::setExpression(AST::Expression *expression) {
    FunctionLiteral::expression = expression;
}

AST::IdentifierList *AST::FunctionLiteral::getIdentifierList() const {
    return identifierList;
}

void AST::FunctionLiteral::setIdentifierList(AST::IdentifierList *identifierList) {
    FunctionLiteral::identifierList = identifierList;
}

AST::FunctionLiteral::FunctionLiteral(AST::StatementList *statementList, AST::Expression *expression,
                                      AST::IdentifierList *identifierList) : statementList(statementList),
                                                                             expression(expression),
                                                                             identifierList(identifierList) {}

TYPES::Type AST::FunctionLiteral::getType() const {
    return TYPES::_FUNCTION;
}
