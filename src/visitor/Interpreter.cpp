//
// Created by sovereign on 10/6/19.
//

#include "Interpreter.h"
#include <iostream>
#include "../type_system/LiteralTypes.h"
#include "../ast/Print.h"
#include "../ast/Expression.h"
#include "../ast/Literal.h"
#include "../ast/StatementList.h"
#include "../ast/ExpressionList.h"
#include "../ast/IfStatement.h"
#include "../ast/BooleanLiteral.h"
#include "../ast/WhileStatement.h"
#include "../ast/DefinitionList.h"
#include "../ast/VarDef.h"
#include "../ast/Reference.h"
#include "../ast/IntLiteral.h"
#include "../ast/VarDef.h"
#include "../ast/ForStatement.h"
#include "../ast/ReferenceTail.h"
#include "../ast/ReadInt.h"
#include "../ast/ReadString.h"
#include "../ast/ReadReal.h"
#include "../ast/Scope.h"

void Interpreter::visit(const AST::Print &print) {
    //std::cout << "size of expr: " << print.expressionsList->expressions.size() << std::endl;
    for (auto expression : print.expressionsList->expressions) {
        expression->accept(*this);
        std::cout << expression->evaluate().to_string() << std::endl;
    }
}

void Interpreter::visit(const AST::Node &node) {}

void Interpreter::visit(const AST::Reference &reference) {
    if (reference.scope->find_in_scope(reference.s_id) == nullptr) {
        //exception
        std::cout << "variable not declared: " + reference.s_id << std::endl;
    }
}

void Interpreter::visit(const AST::Statement &statement) {}

void Interpreter::visit(const AST::EmptyNode &empty_node) {}

void Interpreter::visit(const AST::StatementList &statementlist) {
    //std::cout << "size of statements: " << statementlist.statements.size() << std::endl;
    for (auto statement : statementlist.statements)
        statement->accept(*this);
}

void Interpreter::visit(const AST::IfStatement &statement) {
    if (statement.getExpression()->evaluate().getType() == TYPES::Type::_BOOL) {
        auto litResult = dynamic_cast<AST::BooleanLiteral *>(&statement.getExpression()->evaluate())->value;
        if (litResult) {
            statement.getThenStatements()->accept(*this);
        } else {
            if (statement.isElseIf()) {
                statement.getElseStatements()->accept(*this);
            }
        }
    } else {
        std::cout << "Cannot evaluate if, cant eval "
                  << TYPES::type_to_string(statement.getExpression()->evaluate().getType()) << " to bool" << std::endl;
    }
}

void Interpreter::visit(const AST::WhileStatement &statement) {
    if (statement.getExpression()->evaluate().getType() == TYPES::Type::_BOOL) {
        while (dynamic_cast<AST::BooleanLiteral *>(&statement.getExpression()->evaluate())->value) {
            statement.getWhileStatement()->accept(*this);
            if (statement.getExpression()->evaluate().getType() != TYPES::Type::_BOOL)
                break;
            else {
                //exception
            }
        }
    } else {
        //exception
    }
}

void Interpreter::visit(const AST::DefinitionList &statement) {
    for (auto var : statement.var_list) {
        if (statement.scope->find_in_scope(var.first) != nullptr) {
            //exception
            std::cout << std::endl << "conflict declaration: " << var.first << std::endl;
        } else {
            var.second->accept(*this);
            statement.scope->topScope->symbols.insert(make_pair(var.first, &var.second->evaluate()));
        }
    }
}

void Interpreter::visit(const AST::ForStatement &statement) {
    if (statement.getStartExpression()->evaluate().getType() == TYPES::_INT
        && statement.getEndExpression()->evaluate().getType() == TYPES::_INT) {
        auto startForVar = dynamic_cast<AST::IntLiteral *>(&statement.getStartExpression()->evaluate())->getValue();
        auto endForVar = dynamic_cast<AST::IntLiteral *>(&statement.getEndExpression()->evaluate())->getValue();
        for (int i = startForVar; i < endForVar; ++i) {
            statement.getForStatements()->accept(*this);
        }
    } else {
        std::cout << "Cannot evaluate for, cant eval "
                  << TYPES::type_to_string(statement.getStartExpression()->evaluate().getType())
                  << " OR " << TYPES::type_to_string(statement.getEndExpression()->evaluate().getType()) << " to int"
                  << std::endl;
    }
}

void Interpreter::visit(const AST::ReadInt &statement) {
    int readInt;
    std::cin >> readInt;
    statement.accept(*this);
}

void Interpreter::visit(const AST::ReadString &statement) {
    std::string readStr;
    std::cin >> readStr;
    statement.accept(*this);
}

void Interpreter::visit(const AST::ReadReal &statement) {
    double readReal;
    std::cin >> readReal;
    statement.accept(*this);
}
