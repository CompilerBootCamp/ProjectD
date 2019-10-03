
/*
* bison tbison.y
* gcc -o tbsion tbsion.tab.c -lm
* ./tbsion
*   2 2 +
* >>> 4
*  ^D
*/

%{
#include <stdio.h>
#include <math.h>
int yylex (void);
void yyerror (char const *);

struct my_types
  {
    union
    {
        int     ival;
        double  dval;
        bool    bval;
        char* sval;
    } u;
  };
%}

%define api.value.type {my_types}
%token<u.dval> NUM

%token<u.bval> booleanliteral
%token<u.sval> identifier // ??????
%token<u.ival> integerliteral
%token<u.dval> realliteral
%token<u.sval> stringLiteral

%token PRINT VAR SEMICOLON ASIGN AND OR XOR LESS LESSOREQUAL GREATOREQUAL EQUAL DIVIDEQUAL PLUS
%token MINUS MULT DIVIDE NOT IS LEFTCIRCLEBRACKET RIGHTCIRCLEBRACKET LEFTSQUAREBRACKET RIGHTSQUAREBRACKET LEFTCURLYBRACKET RIGHTCURLYBRACKET
%token READINT READREAL READSTRING RETURN DOUBLEDOT INT REAL BOOL STRING EMPTY IF THEN ELSE END WHILE FOR IN LOOP DOT
%token FUNC TRUE FALSE COMMA ARROW GREAT

%%
//-----------------------------------------------------

program:
    statementList

statementList:
    statement
    | statementList SEMICOLON statement
    
statement:
    assignment
    | print
    | return
    | if
    | loop
    | declaration

assignment:
    primary ASIGN expression

print:
    PRINT expressionlist

return:
    RETURN
    |"return" expression

if:
    IF expression THEN body END
    | IF expression THEN body ELSE body END

loop:
    WHILE expression loopBody
    | FOR identifier IN typeIndicator loopBody

loopBody:
    LOOP body END

declaration:
    VAR variableDefinitionList
    
variableDefinitionList:
    variableDefinition
    | variableDefinitionList COMMA variableDefinition 

variableDefinition:
    identifier
    | identifier ASIGN expression

expression:
    relation
    | relation AND relation
    | relation OR relation
    | relation XOR relation

relation:
    factor
    | factor LESS factor
    | factor LESSOREQUAL factor
    | factor GREAT factor
    | factor GREATOREQUAL factor
    | factor EQUAL factor
    | factor DIVIDEQUAL factor

factor:
    term
    | factor PLUS term
    | factor MINUS term

term:
    unary
    | term MULT unary
    | term DIVIDE unary

unary:
    | primary
    | PLUS primary
    | MINUS primary
    | NOT primary
    | primary IS typeIndicator
    | PLUS primary IS typeIndicator
    | MINUS primary IS typeIndicator
    | NOT primary IS typeIndicator
    | literal
    | LEFTCIRCLEBRACKET expression RIGHTCIRCLEBRACKET   
    
primary:
    identifier
    | primary tail
    | READINT | READREAL | READSTRING

tail:
    DOT integerliteral
    | DOT identifier
    | LEFTSQUAREBRACKET expression RIGHTSQUAREBRACKET
    | LEFTCIRCLEBRACKET expressionlist RIGHTCIRCLEBRACKET
    
expressionlist:
    expression
    | expressionlist COMMA expression

typeIndicator:
    INT | REAL | BOOL | STRING
    | EMPTY         // no type
    | LEFTSQUAREBRACKET RIGHTSQUAREBRACKET // vector type
    | LEFTCURLYBRACKET RIGHTCIRCLEBRACKET  // tuple type
    | FUNC        // functional type
    | expression DOUBLEDOT expression //range

literal:
    integerliteral
    | realliteral
    | booleanliteral
    | stringLiteral
    | arrayLiteral
    | tupleLiteral
    | functionLiteral
    | EMPTY

arrayLiteral:
    LEFTSQUAREBRACKET expressionlist RIGHTSQUAREBRACKET

tupleLiteral :
    LEFTCURLYBRACKET RIGHTCURLYBRACKET 
    |LEFTCURLYBRACKET tupleElementList RIGHTCIRCLEBRACKET
    
tupleElementList:
    tupleElement
    | tupleElementList COMMA tupleElement

tupleElement:
	expression
	| identifier ASIGN expression

functionLiteral:
    FUNC funBody
    | FUNC Parameters funBody

Parameters:
    LEFTCIRCLEBRACKET identifierList RIGHTCIRCLEBRACKET

identifierList:
    identifier
    | identifierList COMMA identifier
    
funBody:
    IS body END
    | ARROW expression

body: 
    statementList

//    ---------------------------------------------------------------------------

%%

int
main (void)
{
     yyparse ();     
}

#include <stdio.h>
#include "lex.yy.c"
/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
    fprintf (stderr, "%s\n", s);
}