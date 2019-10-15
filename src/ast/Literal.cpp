//
// Created by sovereign on 10/6/19.
//

#include "Literal.h"

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
    }
    Literal& Literal::operator-(Literal& rhs)
    {
        //exception
    }
    Literal& Literal::operator*(Literal& rhs)
    {
        //exception
    }
    Literal& Literal::operator/(Literal& rhs)
    {
        //exception
    }
    Literal& Literal::operator&&(Literal& rhs)
    {
        //exception
    }
    Literal& Literal::operator||(Literal& rhs)
    {
        //exception
    }
    Literal& Literal::operator^(Literal& rhs)
    {
        //exception
    }

    bool Literal::operator<(Literal &rhs){
        //exception
    }
    bool Literal::operator>(Literal &rhs){
        //exception
    }
    bool Literal::operator<=(Literal& rhs){
        //exception
    }
    bool Literal::operator>=(Literal& rhs){
        //exception
    }
    bool Literal::operator==(Literal& rhs){
        //exception
    }
    bool Literal::operator!=(Literal& rhs){
        //exception
    }
    bool Literal::operator!(){
        //exception
    }

    //Int
    Literal& Literal::add_operator(IntLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::sub_operator(IntLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::mul_operator(IntLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::div_operator(IntLiteral* rhs)
    {
        //exception
    }
    bool Literal::less_operator(IntLiteral*){
        //exception
    }
    bool Literal::great_operator(IntLiteral*){
        //exception
    }
    bool Literal::lesseq_operator(IntLiteral*){
        //exception
    }
    bool Literal::greateq_operator(IntLiteral*){
        //exception
    }
    bool Literal::eq_operator(IntLiteral*){
        //exception
    }
    bool Literal::neq_operator(IntLiteral*){
        //exception
    }

    //Real
    Literal& Literal::add_operator(RealLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::sub_operator(RealLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::mul_operator(RealLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::div_operator(RealLiteral* rhs)
    {
        //exception
    }

    bool Literal::less_operator(RealLiteral*){
        //exception
    }
    bool Literal::great_operator(RealLiteral*){
        //exception
    }
    bool Literal::lesseq_operator(RealLiteral*){
        //exception
    }
    bool Literal::greateq_operator(RealLiteral*){
        //exception
    }
    bool Literal::eq_operator(RealLiteral*){
        //exception
    }
    bool Literal::neq_operator(RealLiteral*){
        //exception
    }

    //Bool
    Literal& Literal::and_operator(BooleanLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::or_operator(BooleanLiteral* rhs)
    {
        //exception
    }
    Literal& Literal::xor_operator(BooleanLiteral* rhs)
    {
        //exception
    }

    //String
    Literal& Literal::add_operator(StringLiteral* rhs)
    {
        //exception
    }

    //Array
    Literal& Literal::concat(ArrayLiteral*)
    {
        //exception
    }

    //Tuple
    Literal& Literal::concat(TupleLiteral*)
    {
        //exception
    }

    TYPES::Type Literal::getType() const {
        return TYPES::_NOTHING;
    }


}
