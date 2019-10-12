//
// Created by sovereign on 10/6/19.
//

#include "../ast/Print.h"
#include "../ast/Expression.h"
#include "../ast/Literal.h"
#include "../ast/StatementList.h"
#include "../ast/ExpressionList.h"
#include "Interpreter.h"
#include <iostream>
#include "BooleanLiteral.h"


void Interpreter::visit(const AST::Print &print)
{
    //std::cout << "size of expr: " << print.expressionsList->expressions.size() << std::endl;
    for(auto expression : print.expressionsList->expressions)
        std::cout << expression->evaluate().to_string()<< std::endl;
}

void Interpreter::visit(const AST::Node &node) {}
void Interpreter::visit(const AST::Reference &reference) {}
void Interpreter::visit(const AST::Statement &statement) {}
void Interpreter::visit(const AST::EmptyNode &empty_node) {}

void Interpreter::visit(const AST::StatementList &statementlist)
{
    //std::cout << "size of statements: " << statementlist.statements.size() << std::endl;
    for(auto statement : statementlist.statements)
        statement->accept(*this);
}

void Interpreter::visit(const AST::IfStatement &statement) {
    if (dynamic_cast<AST::BooleanLiteral*>(&statement.getExpression()->evaluate())->value) {
        statement.getThenStatements()->accept(*this);
    } else {
        if (statement.isElseIf()) {
            statement.getElseStatements()->accept(*this);
        }
    }
}
