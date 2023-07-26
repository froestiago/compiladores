%{
    #include<stdio.h>
    #include<string.h>
    #include "ast.h"
    #include "parser.tab.h"
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

"int"               {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_INT;}
"float"             {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_FLOAT;}
"bool"              {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_BOOL;}
"if"                {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_IF;}
"else"              {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_ELSE;}
"while"             {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_WHILE;}
"return"            {yylval.valor_lexico = get_yylval(yylineno, PALAVRA_RESERVADA, INF_ND, yytext); return TK_PR_RETURN;}

"false"             {yylval.valor_lexico = get_yylval(yylineno, LITERAL, INF_BOOL, yytext); return TK_LIT_FALSE;}
"true"              {yylval.valor_lexico = get_yylval(yylineno, LITERAL, INF_BOOL, yytext); return TK_LIT_TRUE;}
{integer}           {yylval.valor_lexico = get_yylval(yylineno, LITERAL, INF_INT, yytext); return TK_LIT_INT;}
{float}             {yylval.valor_lexico = get_yylval(yylineno, LITERAL, INF_FLOAT, yytext); return TK_LIT_FLOAT;}

{identificador}     {yylval.valor_lexico = get_yylval(yylineno, IDENTIFICADOR, INF_ND, yytext); return TK_IDENTIFICADOR;}

{special}           {yylval.valor_lexico = get_yylval(yylineno, CARACTERE_ESPECIAL, INF_ND, yytext); return yytext[0];}

"<="			    {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_LE;}
">="			    {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_GE;}
"=="			    {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_EQ;}
"!="			    {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_NE;}
"&"                 {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_AND;}
"|"                 {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_OR;}
"->"                {yylval.valor_lexico = get_yylval(yylineno, OPERADOR_COMPOSTO, INF_ND, yytext); return TK_OC_MAP;}


"//"                        BEGIN(COMMENT_LINE);
<COMMENT_LINE>{new_line}    BEGIN(INITIAL);

"/*"                        BEGIN(COMMENT_BLOCK);
<COMMENT_BLOCK>[^*\n]*
<COMMENT_BLOCK>"*"+[^*/\n]*
<COMMENT_BLOCK>{new_line}   {}
<COMMENT_BLOCK>"*"+"/"      BEGIN(INITIAL);


.                   return TK_ERRO;

%%

int get_line_number() {
	return yylineno;
}
