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

AST::FunctionLiteral::FunctionLiteral(FuncBody* func_body)
{

}

AST::FunctionLiteral::FunctionLiteral(IdentifierList* identifierList, FuncBody* func_body)
{

}

TYPES::Type AST::FunctionLiteral::getType() {
    return TYPES::_FUNCTION;
}
