
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
        std::string* sval;
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

%%
//-----------------------------------------------------

program:
    statementList

statementList:
    statement
    | statementList ";" statement
    
statement:
    assignment
    | print
    | return
    | if
    | loop
    | declaration

assignment:
    primary ":=" expression

print:
    "print" expressionlist

return:
    "return"
    |"return" expression

if:
    "if" expression "then" body "end"
    | "if" expression "then" body "else" body "end"

loop:
    "while" expression loopBody
    | "for" identifier "in" typeIndicator loopBody

loopBody:
    "loop" body "end"

declaration:
    "var" variableDefinitionList
    
variableDefinitionList:
    variableDefinition
    | variableDefinitionList "," variableDefinition 

variableDefinition:
    identifier
    | identifier ":=" expression

expression:
    relation
    | relation "and" relation
    | relation "or" relation
    | relation "xor" relation

relation:
    factor
    | factor "<" factor
    | factor "<=" factor
    | factor ">" factor
    | factor ">=" factor
    | factor "=" factor
    | factor "/=" factor

factor:
    term
    | factor "+" term
    | factor "-" term

term:
    unary
    | term "*" unary
    | term "/" unary

unary:
    | primary
    | "+" primary
    | "-" primary
    | "not" primary
    | primary "is" typeIndicator
    | "+" primary "is" typeIndicator
    | "-" primary "is" typeIndicator
    | "not" primary "is" typeIndicator
    | literal
    | "(" expression ")"
    
primary:
    identifier
    | primary tail
    | "readInt" | "readReal" | "readString"

tail:
    "." integerliteral
    | "." identifier
    | "[" expression "]"
    | "(" expressionlist ")"
    
expressionlist:
    expression
    | expressionlist "," expression

typeIndicator:
    "int" | "real" | "bool" | "string"
    | "empty"         // no type
    | "[""]"           // vector type
    | "{""}"           // tuple type
    | "func"        // functional type
    | expression ".." expression //range

literal:
    integerliteral
    | realliteral
    | booleanliteral
    | stringLiteral
    | arrayLiteral
    | tupleLiteral
    | functionLiteral
    | "empty"

arrayLiteral:
    "[" expressionlist "]"

tupleLiteral :
    "{" "}" 
    |"{" tupleElementList "}"
    
tupleElementList:
    tupleElement
    | tupleElementList "," tupleElement

tupleElement:
	expression
	| identifier ":=" expression

functionLiteral:
    "func" funBody
    | "func" Parameters funBody

Parameters:
    '(' identifierList ')'

identifierList:
    identifier
    | identifierList "," identifier
    
funBody:
    "is" body "end"
    | "=>" expression

body: 
    statementList

//    ---------------------------------------------------------------------------

%%

/* The lexical analyzer returns a double floating point
   number on the stack and the token NUM, or the numeric code
   of the character read if not a number.  It skips all blanks
   and tabs, and returns 0 for end-of-input.  */

#include <ctype.h>
int
yylex (void)
{
    int c;

    /* Skip white space.  */
    while ((c = getchar ()) == ' ' || c == '\t')
        continue;
    /* Process numbers.  */
    if (c == '.' || isdigit (c))
    {
        ungetc (c, stdin);
        scanf ("%lf", &yylval);
        return NUM;
    }
    /* Return end-of-input.  */
    if (c == EOF)
        return 0;
    /* Return a single char.  */
    return c;
}

int
main (void)
{
    return yyparse ();
}

#include <stdio.h>

/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
    fprintf (stderr, "%s\n", s);
}