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
#include "../ast/BinaryExpr.h"
#include "../ast/Expression.h"
#include "../ast/TypeIndicator.h"
#include "../ast/UnaryExpr.h"
#include "../ast/Assign.h"
#include "../ast/Reference.h"
#include "../ast/ArrayLiteral.h"
#include "../ast/TupleLiteral.h"
#include "../ast/StringLiteral.h"

void Interpreter::visit(const AST::Print &print)
{
    //std::cout << "size of expr: " << print.expressionsList.size() << std::endl;
    for (auto expression : print.expressionsList)
    {
        expression->scope = print.scope;
        while(!expression->scope->in_block)
            expression->scope = expression->scope->topScope;
        expression->accept(*this);

        std::cout << expression->evaluate().to_string() << std::endl;
    }
}

void Interpreter::visit(const AST::Node &node)
{
    //exception
}

void Interpreter::visit(const AST::Expression &node) {}

void Interpreter::visit(const AST::Reference &reference)
{
    if(reference.scope==nullptr)
    {
        std::cout << "scope not found in visit ref" << std::endl;
        return;
    }

    if (reference.scope->find_in_scope(reference.s_id) == nullptr)
    {
        //exception
        std::cout << "variable not declared: " + reference.s_id << std::endl;
    }
    else
    {
        for(auto ref: reference.reference_tail)
        {
            ref.first->scope = reference.scope;
            for(auto ref_expr : ref.first->expressions)
            {
                ref_expr->scope = reference.scope;
                ref_expr->accept(*this);
            }
        }
    }
}

void Interpreter::visit(const AST::Statement &statement) {}

void Interpreter::visit(const AST::EmptyNode &empty_node) {}

void Interpreter::visit(AST::StatementList &statementlist)
{
    //std::cout << "size of statements: " << statementlist.statements.size() << std::endl;
    if(statementlist.scope == nullptr)
        statementlist.scope = new Scope(true);

    for (auto statement : statementlist.statements)
    {
        statement->scope = new Scope(false);
        statement->scope->topScope = statementlist.scope;
        statement->accept(*this);
    }
}

void Interpreter::visit(const AST::IfStatement &statement)
{
    statement.getExpression()->scope = statement.scope;
    statement.getExpression()->accept(*this);

    if (statement.getExpression()->evaluate().getType() == TYPES::Type::_BOOL)
    {
        auto litResult = dynamic_cast<AST::BooleanLiteral *>(&statement.getExpression()->evaluate())->value;
        if (litResult)
        {
            statement.getThenStatements()->scope = new Scope(true);
            statement.getThenStatements()->scope->topScope = statement.scope;

            statement.getThenStatements()->accept(*this);
        }
        else
        {
            if (statement.isElseIf())
            {
                statement.getElseStatements()->scope = new Scope(true);
                statement.getElseStatements()->scope->topScope = statement.scope;

                statement.getElseStatements()->accept(*this);
            }
        }
    }
    else
    {
        std::cout << "Cannot evaluate if, cant eval "
                  << TYPES::type_to_string(statement.getExpression()->evaluate().getType()) << " to bool" << std::endl;
    }
}

void Interpreter::visit(const AST::WhileStatement &statement)
{
    statement.getExpression()->scope = new Scope(false);
    statement.getExpression()->scope->topScope = statement.scope->topScope;
    statement.getExpression()->accept(*this);

    if (statement.getExpression()->evaluate().getType() == TYPES::Type::_BOOL)
    {
        while (dynamic_cast<AST::BooleanLiteral *>(&statement.getExpression()->evaluate())->value)
        {
            statement.getWhileStatement()->scope = new Scope(true);
            statement.getWhileStatement()->scope->topScope = statement.scope;

            statement.getWhileStatement()->accept(*this);
            if (statement.getExpression()->evaluate().getType() != TYPES::Type::_BOOL)
                break;
            else
            {
                //exception
            }
        }
    }
    else
    {
        //exception
    }
}

void Interpreter::visit(const AST::DefinitionList &statement)
{
    for (auto var : statement.var_list)
    {
        if (statement.scope->find_only_in_scope(var.first) != nullptr)
        {
            //exception
            std::cout << std::endl << "conflict declaration: " << var.first << std::endl;
        }
        else
        {
            var.second->scope = statement.scope;
            var.second->accept(*this);

            statement.scope->topScope->symbols.insert(make_pair(var.first, &var.second->evaluate()));
        }
    }
}

void Interpreter::visit(const AST::ForStatement &statement)
{
    Scope* temp = new Scope(false);
    //todo fix duplicate
    statement.getStartExpression()->scope = temp;
    statement.getEndExpression()->scope = temp;
    statement.getStartExpression()->scope->topScope = statement.scope->topScope;
    statement.getEndExpression()->scope->topScope = statement.scope->topScope;
    statement.getStartExpression()->accept(*this);
    statement.getEndExpression()->accept(*this);


    if (statement.getStartExpression()->evaluate().getType() == TYPES::_INT
            && statement.getEndExpression()->evaluate().getType() == TYPES::_INT)
    {
        auto startForVar = dynamic_cast<AST::IntLiteral *>(&statement.getStartExpression()->evaluate())->getValue();
        auto endForVar = dynamic_cast<AST::IntLiteral *>(&statement.getEndExpression()->evaluate())->getValue();

        statement.getForStatements()->scope = new Scope(true);
        statement.getForStatements()->scope->topScope = statement.scope;
        statement.getForStatements()->scope->symbols.insert(make_pair(statement.getDef()->variable.first, &statement.getDef()->variable.second->evaluate()));
        for (int i = startForVar; i < endForVar; ++i)
        {
            statement.getForStatements()->accept(*this);
            statement.getForStatements()->scope->symbols.clear();
            statement.getForStatements()->scope->symbols[statement.getDef()->variable.first] = new AST::IntLiteral(i+1);
        }
    }
    else
    {
        std::cout << "Cannot evaluate for, cant eval "
                  << TYPES::type_to_string(statement.getStartExpression()->evaluate().getType())
                  << " OR " << TYPES::type_to_string(statement.getEndExpression()->evaluate().getType()) << " to int"
                  << std::endl;
    }
}

void Interpreter::visit(const AST::ReadInt &statement)
{
    int readInt;
    std::cin >> readInt;
    statement.accept(*this);
}

void Interpreter::visit(const AST::ReadString &statement)
{
    std::string readStr;
    std::cin >> readStr;
    statement.accept(*this);
}

void Interpreter::visit(const AST::ReadReal &statement)
{
    double readReal;
    std::cin >> readReal;
    statement.accept(*this);
}

void Interpreter::visit(const AST::BinaryExpr &bin_expr)
{
    bin_expr.left->scope = bin_expr.scope;
    while(!bin_expr.left->scope->in_block)
        bin_expr.left->scope = bin_expr.left->scope->topScope;
    bin_expr.right->scope = bin_expr.left->scope;

    bin_expr.left->accept(*this);
    bin_expr.right->accept(*this);
}

void Interpreter::visit(const AST::TypeIndicator &type_indicator)
{
    type_indicator.getReference()->scope = type_indicator.scope;
    while(!type_indicator.getReference()->scope->in_block)
        type_indicator.getReference()->scope = type_indicator.getReference()->scope->topScope;
    type_indicator.getReference()->accept(*this);
}

void Interpreter::visit(const AST::UnaryExpr &un_expr)
{
    un_expr.expression->scope = un_expr.scope;
    while(!un_expr.expression->scope->in_block)
        un_expr.expression->scope = un_expr.expression->scope->topScope;
    un_expr.expression->accept(*this);
}

void swap_spec(AST::Literal &a, AST::Literal &b)
{
    AST::Literal tmp = a;

    a = b; // Since you are using references, this will actually modify test[0] at its memory location
    b = tmp;
}

void Interpreter::visit(const AST::Assign &as)
{
    as.ref_variable->scope = as.scope;
    as.ref_variable->accept(*this);
    as.expression->scope = as.scope;
    as.expression->accept(*this);

    auto r = static_cast<AST::Reference*>(as.ref_variable);
    auto da = as.scope;

    while(da != nullptr)
    {

        if(da->symbols.find(r->s_id) != da->symbols.end())
        {
            auto value = &da->symbols[r->s_id]->evaluate();
            auto inner_ref = &da->symbols[r->s_id];//

            for(auto ref: r->reference_tail)
            {
                switch(ref.second)
                {
                case TYPES::_ARRAY:
                {
                    auto arr = static_cast<AST::ArrayLiteral*>(value);
                    auto index = static_cast<AST::IntLiteral*>(&ref.first->expressions[0]->evaluate())->value;

                    if(index >= arr->_size)
                        arr->_size = index + 1;

                    if(arr->array.find(index) == arr->array.end())
                        arr->array[index] = new AST::Literal();
                    value = arr ->array[index];
                    inner_ref = &arr ->array[index];

                    break;
                }
                case TYPES::_TUPLE:
                {

                    auto tuple = static_cast<AST::TupleLiteral*>(value);
                    auto key = static_cast<AST::StringLiteral*>(ref.first->expressions[0])->value;
                    auto tuple_value = tuple->get_value(key);
                    if(tuple_value != nullptr)
                    {
                        value = *tuple_value;
                        inner_ref = tuple_value;
                    }
                    else
                    {
                        //exception
                        std::cout << "error in assign identifier(tuple)" << std::endl;
                        return;
                    }
                    break;
                }
                case TYPES::_FUNCTION:
                {
                    std::cout << "you cant assign function" << std::endl;
                    return;
                }
                }
            }
            *inner_ref = &as.expression->evaluate();
            //swap_spec(*value, as.expression->evaluate());
            //&inner_ref = &as.expression->evaluate();
        }
        da = da->topScope;
    }


}
