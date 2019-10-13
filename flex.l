/*
    c++                 generate C++ parser class
    8bit                don't fail on 8-bit input characters
    warn                warn about inconsistencies
    nodefault           don't create default echo-all rule
    noyywrap            don't use yywrap() function
    yylineno            store number of line in yylineno variable
 */
%option 8bit warn nodefault
%option noyywrap
%option yylineno

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
stringliteral '{AlphaDigit}*'


%%

"var"		    {ECHO; return VAR; }
";"		        {ECHO; return SEMICOLON; }
":="		    {ECHO; return ASSIGN; }
"and"		    {ECHO; return AND; }
"or"		    {ECHO; return OR; }
"xor"		    {ECHO; return XOR; }
"<"		        {ECHO; return LESS; }
"<="		    {ECHO; return LESSOREQUAL; }
">"             {ECHO; return GREAT; }
">="		    {ECHO; return GREATOREQUAL; }
"="		        {ECHO; return EQUAL; }
"/="		    {ECHO; return DIVIDEQUAL; }
"+"		        {ECHO; return PLUS; }
"-"		        {ECHO; return MINUS; }
"*"		        {ECHO; return MULT; }
"/"		        {ECHO; return DIVIDE; }
"not"		    {ECHO; return NOT; }
"is"		    {ECHO; return IS; }
"("		        {ECHO; return LEFTCIRCLEBRACKET; }
")"		        {ECHO; return RIGHTCIRCLEBRACKET; }
"["		        {ECHO; return LEFTSQUAREBRACKET; }
"]"		        {ECHO; return RIGHTSQUAREBRACKET; }
"{"		        {ECHO; return LEFTCURLYBRACKET; }
"}"		        {ECHO; return RIGHTCURLYBRACKET; }
"readInt"	    {ECHO; return READINT; }
"readReal"      {ECHO; return READREAL; }
"readString"    {ECHO; return READSTRING; }
"print"		    {ECHO; return PRINT; }
"return"	    {ECHO; return RETURN; }
"if"		    {ECHO; return IF; }
"then"		    {ECHO; return THEN; }
"else"		    {ECHO; return ELSE; }
"end"		    {ECHO; return END; }
"while"		    {ECHO; return WHILE; }
"for"		    {ECHO; return FOR; }
"in"		    {ECHO; return IN; }
"loop"		    {ECHO; return LOOP; }
"."		        {ECHO; return DOT; }
".."	        {ECHO; return DOUBLEDOT; }
"int"		    {ECHO; return INT; }
"real"		    {ECHO; return REAL; }
"bool"		    {ECHO; return BOOL; }
"string"	    {ECHO; return STRING; }
"empty"		    {ECHO; return EMPTY; }
"func"		    {ECHO; return FUNC; }
"true"		    {ECHO; yylval.u.bval = true; return booleanLiteral; }
"false"		    {ECHO; yylval.u.bval = false; return booleanLiteral; }
","		        {ECHO; return COMMA; }
"=>"		    {ECHO; return ARROW; }
{integerliteral} {ECHO;   yylval.u.ival = atoi(yytext);  return integerLiteral;}
{realliteral}    {ECHO;  yylval.u.dval = atof(yytext);  return realLiteral;}
{stringliteral}  {ECHO; yylval.u.sval = yytext; return stringLiteral;}
{identifier}     {ECHO; yylval.u.sval = yytext; return identifier;}
\n               {ECHO; lines++; }
[ \t\r]+       { ECHO;}
.                {printf("unknown symbol: %s in line %d\n", yytext, yylineno);}


%%
