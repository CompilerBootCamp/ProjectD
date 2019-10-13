/* require bison version */
%require  "3.0"

/* increase usefulness of error messages */
%define parse.error verbose


%{
#include <stdio.h>
#include <math.h>

#include "Node.h"
#include "EmptyNode.h"
#include "StatementList.h"
#include "Statement.h"
#include "Expression.h"
#include "ExpressionList.h"
#include "Print.h"
#include "BinaryExpr.h"
#include "Literal.h"
#include "IntLiteral.h"
#include "RealLiteral.h"
#include "BooleanLiteral.h"
#include "StringLiteral.h"
#include "UnaryExpr.h"
#include "ArrayLiteral.h"
#include "IfStatement.h"

#include "Interpreter.h"

int yylex (void);
void yyerror (char const *);

AST::StatementList* root;

struct my_types
  {
    union
    {
        int     ival;
        double  dval;
        bool    bval;
        char* sval; // ???
        AST::Node* nval; // empty???
        AST::StatementList* stlistval;
        AST::Statement* stval;
        AST::ExpressionList* exlistval;
        AST::Expression* exval;
    } u;    
  };
%}

%define api.value.type {my_types}

%token<u.bval> booleanLiteral
%token<u.sval> identifier // ??????
%token<u.ival> integerLiteral
%token<u.dval> realLiteral
%token<u.sval> stringLiteral

// Identidier and numbers
%token VAR

// Keywords
%token AND OR XOR NOT IS
%token READINT READREAL READSTRING PRINT
%token RETURN IF THEN ELSE END WHILE FOR
%token IN LOOP
%token INT REAL BOOL STRING EMPTY
%token FUNC

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

%type<u.stval> statement print emptyStatement if
%type<u.stlistval> statementList body//costyl
%type<u.exlistval> expressionlist //costyl
%type<u.exval> expression literal factor term unary primary andexpression relation arrayLiteral


%left OR XOR
%left AND
%left LESS GREAT EQUAL LESSOREQUAL GREATOREQUAL DIVIDEQUAL
%left PLUS MINUS
%left MULT DIVIDE

%%
//-----------------------------------------------------

program:
    statementList { root = $1; } ;

statementList:
    statement 
        { 
            $$ = new AST::StatementList($1);
        }
    | statementList SEMICOLON statement 
        {  
            $1->add_statement($3);
            $$ = $1;
        }
    ;
    
statement:
      emptyStatement { $$ = $1; }
    | assignment
    | print          { $$ = $1; }
    | return        
    | if            
    | loop          
    | declaration
    
emptyStatement:
    %empty  { $$ = new AST::EmptyNode(); };

assignment:
    reference ASSIGN expression

print:
    PRINT expressionlist { $$ = new AST::Print($2); };

return:
    RETURN
    | RETURN expression

if:
    IF expression THEN body END { $$ = new AST::IfStatement($2, $4); }
    | IF expression THEN body ELSE body END { $$ = new AST::IfStatement($2, $4, $6); }

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
    expression OR andexpression     { $$ = new AST::BinaryExpr($1, $3, _OR);}
    |expression XOR andexpression   { $$ = new AST::BinaryExpr($1, $3, _XOR);}
    | andexpression                 { $$ = $1; }
    ;
    
andexpression:
    andexpression AND relation  { $$ = new AST::BinaryExpr($1, $3, _AND);}
    |relation                   { $$ = $1; }
    ;
    
relation:
    factor                          { $$ = $1; }
    | factor LESS factor            { $$ = new AST::BinaryExpr($1, $3, _LESS); }
    | factor LESSOREQUAL factor     { $$ = new AST::BinaryExpr($1, $3, _LESS_OR_EQUAL); }
    | factor GREAT factor           { $$ = new AST::BinaryExpr($1, $3, _GREATER); }
    | factor GREATOREQUAL factor    { $$ = new AST::BinaryExpr($1, $3, _GREATER_OR_EQUAL); }
    | factor EQUAL factor           { $$ = new AST::BinaryExpr($1, $3, _EQUAL); }
    | factor DIVIDEQUAL factor      { $$ = new AST::BinaryExpr($1, $3, _DIVIDE_EQUAL); }

factor:
    term                { $$ = $1; }
    | factor PLUS term  { $$ = new AST::BinaryExpr($1, $3, _ADD);}
    | factor MINUS term { $$ = new AST::BinaryExpr($1, $3, _SUB);}

term:
    unary               { $$ = $1; }
    | term MULT unary   { $$ = new AST::BinaryExpr($1, $3, _MULTIPLY);}
    | term DIVIDE unary { $$ = new AST::BinaryExpr($1, $3, _DIVIDE);}

unary:
    reference
    | reference IS typeIndicator
    | PLUS reference
    | MINUS reference
    | NOT reference
    | primary           { $$ = $1; }
    | PLUS primary      { $$ = new AST::UnaryExpr($2, _PLUS); }
    | MINUS primary     { $$ = new AST::UnaryExpr($2, _MINUS); }
    | NOT primary       { $$ = new AST::UnaryExpr($2, _NOT); }

primary:
      literal
    | READINT | READREAL | READSTRING //??????
    | LEFTCIRCLEBRACKET expression RIGHTCIRCLEBRACKET  { $$ = $2; }
    
reference:
    identifier
    | reference tail

tail:
    DOT integerLiteral // access to unnamed tuple element
    | DOT identifier // access to named tuple element
    | LEFTSQUAREBRACKET expression RIGHTSQUAREBRACKET // access to array element
    | LEFTCIRCLEBRACKET expressionlist RIGHTCIRCLEBRACKET // function call
    
expressionlist:
    expression 
        {
            $$ = new AST::ExpressionList($1);
        }
    | expressionlist COMMA expression 
        {
            $1->add_expression($3);
            $$ = $1;
        }
    ;

typeIndicator:
    INT | REAL | BOOL | STRING
    | EMPTY         // no type
    | LEFTSQUAREBRACKET RIGHTSQUAREBRACKET // vector type
    | LEFTCURLYBRACKET RIGHTCURLYBRACKET  // tuple type
    | FUNC        // functional type

literal:
    integerLiteral  { $$ = new AST::IntLiteral($1); }
    | realLiteral   { $$ = new AST::RealLiteral($1); }
    | booleanLiteral{ $$ = new AST::BooleanLiteral($1); }
    | stringLiteral { $$ = new AST::StringLiteral($1); }
    | arrayLiteral  { $$ = $1; }
    | tupleLiteral  
    | functionLiteral
    ;

arrayLiteral:
    LEFTSQUAREBRACKET RIGHTSQUAREBRACKET                    { $$ = new AST::ArrayLiteral(); }
    | LEFTSQUAREBRACKET expressionlist RIGHTSQUAREBRACKET   { $$ = new AST::ArrayLiteral($2); }

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
#include "lexer.cpp"
/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
    printf ("\n%s but recive '%s' in line %d\n", s, yytext, yylineno);
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
        
        Interpreter my;
        root->accept(my);
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
