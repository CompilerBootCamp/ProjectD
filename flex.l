/*
*   flex tlex.l
*   gcc -o tlex lex.yy.c
*   ./tlex tlex.l
*/

%option noyywrap

%{
#include <string.h>
#include <stdio.h>

int lines = 0;
%}

%%

[a-zA-Z]+       { }
"var"		{ return VAR; }
";"		{ return SEMICOLON; }
":="		{ return ASIIGN; }
"and"		{ return AND; }
"or"		{ return OR; }
"xor"		{ return XOR; }
"<"		{ return LESS; }
"<="		{ retrun LESSOREQUAL; }
">="		{ return GREATOREQAL; }
"="		{ return EQUAL; }
"/="		{ return DIVIDEQUAL; }
"+"		{ return PLUS; }
"-"		{ return MINUS; }
"*"		{ return MULT; }
"/"		{ return DIVIDE; }
"not"		{ return NOT; }
"is"		{ return IS; }
"("		{ return LEFTCIRCLEBRACKET; }
")"		{ return RIGHTCIRCLEBRACKET; }
"["		{ return LEFTSQUAREBRACKET; }
"]"		{ return RIGHTSQUAREBRACKET; }
"{"		{ return LEFTCURLYBRACKET; }
"}"		{ return RIGHTCURLYBRACKET; }
"readInt"	{ return READINT; }
"readReal"	{ return READREAL; }
"readString"	{ return READSTRING; }
"print"		{ return PRINT; }
"return"	{ return RETURN; }
"if"		{ return IF; }
"then"		{ return THEN; }
"else"		{ return ELSE; }
"end"		{ return END; }
"while"		{ return WHILE; }
"for"		{ return FOR; }
"in"		{ return IN; }
"loop"		{ return LOOP; }
"."		{ return DOT; }
"int"		{ return INT; }
"real"		{ return REAL; }
"bool"		{ return BOOL; }
"string"	{ return STRING; }
"empty"		{ return EMPTY; }
"func"		{ return FUNC; }
"true"		{ return TRUE; }
"false"		{ return FALSE; }
","		{ return COMMA; }
"=>"		{ return ARROW; }
\n              { lines++; }
.               { }

%%

int main(int argc, char *argv[])
{
    if(argc > 1) {
        if(!(yyin = fopen(argv[1], "r"))) {
            perror(argv[1]);
            return 1;
        }
    }
    
    yylex();
    printf("%8d%8d%8d\n", lines);
    return 0;
}
