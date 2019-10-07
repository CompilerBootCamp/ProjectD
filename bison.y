
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

// Identidier and numbers
%token VAR

// Keywords
%token AND OR XOR NOT IS
%token READINT READREAL READSTRING PRINT
%token RETURN IF THEN ELSE END WHILE FOR
%token IN LOOP
%token INT REAL BOOL STRING EMPTY
%token FUNC TRUE FALSE

// Delimiters
%token LEFTCIRCLEBRACKET    // (
%token RIGHTCIRCLEBRACKET   // )
%token LEFTSQUAREBRACKET    // [
%token RIGHTSQUAREBRACKET   // ]
%token LEFTCURLYBRACKET     // }
%token RIGHTCURLYBRACKET    // }
%token DOT                  // .
%token DOUBLEDOT            // ..
%token COMMA                // ,
%token ARROW                // =>

// Operator signs
%token ASSIGN               // :=  
%token SEMICOLON            // ;
%token LESS                 // <
%token LESSOREQUAL          // <=
%token GREAT                // >
%token GREATOREQUAL         // >=
%token EQUAL                // =
%token DIVIDEQUAL           // /=
%token PLUS                 // +
%token MINUS                // -
%token MULT                 // *
%token DIVIDE               // /

%start program
%%
//-----------------------------------------------------

program:
    statementList

statementList:
    statement 
    | statementList SEMICOLON statement
    
statement:
    %empty
    | assignment
    | print
    | return
    | if
    | loop
    | declaration

assignment:
    reference ASSIGN expression

print:
    PRINT expressionlist

return:
    RETURN
    | RETURN expression

if:
    IF expression THEN body END
    | IF expression THEN body ELSE body END

loop:
    WHILE expression loopBody
    | FOR identifier IN expression DOUBLEDOT expression loopBody

loopBody:
    LOOP body END

declaration:
    VAR variableDefinitionList
    
variableDefinitionList:
    variableDefinition
    | variableDefinitionList COMMA variableDefinition 

variableDefinition:
    identifier
    | identifier ASSIGN expression

expression:
    relationlist
    
relationlist:
    relation
    | relationlist AND relation
    | relationlist OR relation
    | relationlist XOR relation
    
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
    reference
    | reference IS typeIndicator
    | PLUS reference
    | MINUS reference
    | NOT reference
    | primary
    | PLUS primary
    | MINUS primary
    | NOT primary

primary:
      literal
    | READINT | READREAL | READSTRING //??????
    | LEFTCIRCLEBRACKET expression RIGHTCIRCLEBRACKET  
    
reference:
    identifier
    | reference tail

tail:
    DOT integerliteral // access to unnamed tuple element
    | DOT identifier // access to named tuple element
    | LEFTSQUAREBRACKET expression RIGHTSQUAREBRACKET // access to array element
    | LEFTCIRCLEBRACKET expressionlist RIGHTCIRCLEBRACKET // function call
    
expressionlist:
    expression
    | expressionlist COMMA expression

typeIndicator:
    INT | REAL | BOOL | STRING
    | EMPTY         // no type
    | LEFTSQUAREBRACKET RIGHTSQUAREBRACKET // vector type
    | LEFTCURLYBRACKET RIGHTCURLYBRACKET  // tuple type
    | FUNC        // functional type

literal:
    integerliteral
    | realliteral
    | booleanliteral
    | stringLiteral
    | arrayLiteral
    | tupleLiteral
    | functionLiteral

arrayLiteral:
    LEFTSQUAREBRACKET RIGHTSQUAREBRACKET
    | LEFTSQUAREBRACKET expressionlist RIGHTSQUAREBRACKET

tupleLiteral :
    LEFTCURLYBRACKET RIGHTCURLYBRACKET 
    |LEFTCURLYBRACKET tupleElementList RIGHTCURLYBRACKET
    
tupleElementList:
    tupleElement
    | tupleElementList COMMA tupleElement

tupleElement:
	expression
	| identifier ASSIGN expression

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

#include <stdio.h>
#include "lex.yy.c"
/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
    printf ("\n%s: '%s' in line %d\n", s, yytext, yylineno);
}

int
main (int argc, char *argv[])
{
    if (argc == 1)
    {
        if ((yyin = fopen( "input.txt", "r" )) == NULL)
        {
            yyin = stdin;
            printf("STDIN is used\n");
        }
        yyparse();
    }

    if(argc == 2)
    {
        yyin = fopen(argv[1], "r");
        yyparse();
    }
    
    if (argc == 3) {
       yyout = fopen(argv[2],"w");

       yyin = fopen(argv[1], "r");
       yyparse();
       fclose(yyout);
    }
    
    //yyout = fopen( "out_debug.txt", "w" );  // Write in file
    return 0;
}
