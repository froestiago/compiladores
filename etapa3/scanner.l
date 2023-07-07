%{
    #include<stdio.h>
    #include<string.h>
    #include "ast.h"
    #include "parser.tab.h"
    #include "valor_lexico.h"
%}

%option noyywrap
%option yylineno

%x COMMENT_BLOCK
%x COMMENT_LINE

digit           [0-9]

float           [0-9]?*\.?[0-9]+
integer         {digit}+

identificador   [A-Za-z_]+

special         [-!*/%+<>{}()=,;]

space           [ \t]+
new_line        [\n]

%%

{new_line}          {}; /* tem que ter */
{space}             {};

"int"               return TK_PR_INT;
"float"             return TK_PR_FLOAT;
"bool"              return TK_PR_BOOL;
"if"                return TK_PR_IF;
"else"              return TK_PR_ELSE;
"while"             return TK_PR_WHILE;
"return"            return TK_PR_RETURN;

"false"             return TK_LIT_FALSE;
"true"              return TK_LIT_TRUE;
{integer}           {yylval.valor_lexico = get_yylval(yylineno, LITERAL, yytext); return TK_LIT_INT;}
{float}             return TK_LIT_FLOAT;

{identificador}     return TK_IDENTIFICADOR;

"<="			    return TK_OC_LE;
">="			    return TK_OC_GE;
"=="			    return TK_OC_EQ;
"!="			    return TK_OC_NE;
"&"                 return TK_OC_AND;
"|"                 return TK_OC_OR;
"->"                return TK_OC_MAP;


"//"                        BEGIN(COMMENT_LINE);
<COMMENT_LINE>{new_line}    BEGIN(INITIAL);

"/*"                        BEGIN(COMMENT_BLOCK);
<COMMENT_BLOCK>[^*\n]*
<COMMENT_BLOCK>"*"+[^*/\n]*
<COMMENT_BLOCK>{new_line}   {}
<COMMENT_BLOCK>"*"+"/"      BEGIN(INITIAL);


{special}           return yytext[0];
.                   return TK_ERRO;

%%

int get_line_number() {
	return yylineno;
}
