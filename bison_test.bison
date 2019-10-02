
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
%}
%define api.value.type {double}
%token NUM

%%
//-----------------------------------------------------

program:
    statement
    | statement ';' statement

statement:
    assignment
    | print
    | return
    | if
    | loop
    | declaration


assignment:
    primay ':=' expression

print:
    print expression
	|print expression ',' expression

return:
    'return' expression

if:
    'if' exression 'then' body 'end'
    | 'if' expression 'then' body 'else' body 'end'


loop:
    'while' expression loop_body
    | 'for' identifier in type_indication loop_body

loop_body:
    'loop' body 'end'


declaration:
    'var' identifier ';'
    | 'var' identifier ':=' expression ';'

expression:
    relation
    | relation 'and' relation

relation:
    factor
    | relation '<' factor
    | relation '<=' factor
    | relation '>' factor
    | relation '>=' factor
    | relation '=' factor
    | relation '/=' factor

factor:
    term
    | term '+' term
    | term '-' term

term:
    unary
    | unary '*' unary
    | unary '/' unary

unary:
    primary
    | '+' primary
    | '-' primary
    | 'not' primary
    | '+' primary 'is' type_indicator
    | '-' primary 'is' type_indicator
    | 'not' primary 'is' type_indicator
    | literal
    | '(' expression ')'

primary:
    identifier
    | identifier tail
    | 'readInt'
    | 'readReal'
    | 'readString'

tail:
    '.' integerliteral
    | '.' identifier
    | '[' expression ']'
    | '(' expression ')'
    | '(' expression ',' expression ')'

typeIndicator:
    'int' | 'real' | 'bool' | 'string'
    | 'empty'         // no type
    | '['']'           // vector type
    | '{''}'           // tuple type
    | 'func'        // functional type
    | expression '..' expression //range

literal:
    integerlteral
    | realliteral
    | booleanliteral
    | stringLiteral
    | arrayLiteral
    | tupleLiteral

arrayLiteral:
    | '[' expression ']'
    | '[' expression',' expression ']'

tupleLiteral :
    '{' '}' 
    |'{' tupleElement '}'
	|'{' tupleElement ',' tupleElement '}'

tupleElement:
	expression
	| identifier ':=' expression

functionLiteral:
    'func' funBody
    | 'func' parameters funBody

Parameters:
    identifier
    | identifier ',' identifier

funBody:
    'is' body 'end'
    | '=>' expression

body:
    declaration
    | statement
    | expression

//    ---------------------------------------------------------------------------
        input:
%empty
| input line
;
line:
    '\n'
    | exp '\n'      { printf ("%.10g\n", $1); }
    ;
exp:
NUM           { $$ = $1;           }
| exp exp '+'   { $$ = $1 + $2;      }
| exp exp '-'   { $$ = $1 - $2;      }
| exp exp '*'   { $$ = $1 * $2;      }
| exp exp '/'   { $$ = $1 / $2;      }
| exp exp '^'   { $$ = pow ($1, $2); }  /* Exponentiation */
| exp 'n'       { $$ = -$1;          }  /* Unary minus    */
;

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