%{
    #include <stdio.h>
    #include "parser.tab.h"
    #include "ast.h"
    #include "valor_lexico.h"
%}

%option noyywrap
%option yylineno


digit           [0-9]

integer         {digit}+


%%

{integer}           {yylval.valor_lexico = get_yylval(yylineno, LITERAL, yytext); return TK_LIT_INT;}


%%

int get_line_number() {
	return yylineno;
}
