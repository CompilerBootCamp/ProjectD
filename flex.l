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

Alpha 	[a-zA-Z_]
Digit   [0-9] 
AlphaDigit {Alpha}|{Digit}
integerliteral  {Digit}+
realliteral {integerliteral}\.{integerliteral}
identifier {Alpha}{AlphaDigit}* 

%%

"var"		{ return VAR; }
";"		{ return SEMICOLON; }
":="		{ return ASSIGN; }
"and"		{ return AND; }
"or"		{ return OR; }
"xor"		{ return XOR; }
"<"		{ return LESS; }
"<="		{ return LESSOREQUAL; }
">"         { return GREAT; }
">="		{ return GREATOREQUAL; }
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
"print"		{  return PRINT; }
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
".."	{ return DOUBLEDOT; }
"int"		{ return INT; }
"real"		{ return REAL; }
"bool"		{ return BOOL; }
"string"	{ return STRING; }
"empty"		{ return EMPTY; }
"func"		{ return FUNC; }
"true"		{ yylval.u.bval = true; return booleanliteral; }
"false"		{ yylval.u.bval = false; return booleanliteral; }
","		{ return COMMA; }
"=>"		{ return ARROW; }
{integerliteral} {   yylval.u.ival = atoi(yytext);  return integerliteral;}
{realliteral}    {   yylval.u.ival = atof(yytext);  return realliteral;}
{identifier}       { yylval.u.sval = yytext; return identifier;}
\n              { lines++; }
.               { }

%%

