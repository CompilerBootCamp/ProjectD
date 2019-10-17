//
// Created by sovereign on 10/6/19.
//

#include "Literal.h"
#include <iostream>

namespace AST
{

    std::string Literal::to_string()
    {
        return "empty";
    }

    Literal& Literal::evaluate()
    {
        return *this;
    }

    Literal& Literal::operator+(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator-(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator*(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator/(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator&&(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator||(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::operator^(Literal& rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    bool Literal::operator<(Literal &rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator>(Literal &rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator<=(Literal& rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator>=(Literal& rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator==(Literal& rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator!=(Literal& rhs){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::operator!(){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //Int
    Literal& Literal::add_operator(IntLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::sub_operator(IntLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::mul_operator(IntLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::div_operator(IntLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::less_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::great_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::lesseq_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::greateq_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::eq_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::neq_operator(IntLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //Real
    Literal& Literal::add_operator(RealLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::sub_operator(RealLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::mul_operator(RealLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::div_operator(RealLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    bool Literal::less_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::great_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::lesseq_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::greateq_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::eq_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    bool Literal::neq_operator(RealLiteral*){
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //Bool
    Literal& Literal::and_operator(BooleanLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::or_operator(BooleanLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }
    Literal& Literal::xor_operator(BooleanLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //String
    Literal& Literal::add_operator(StringLiteral* rhs)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //Array
    Literal& Literal::concat(ArrayLiteral*)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    //Tuple
    Literal& Literal::concat(TupleLiteral*)
    {
        //exception
        std::cerr << "The type of the variable is not defined" << std::endl;
        exit(1);
    }

    TYPES::Type Literal::getType() {
        return TYPES::_NOTHING;
    }


}
