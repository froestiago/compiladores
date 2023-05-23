%{
    #include <stdio.h>
    #include "tokens.h"
    #include "main.c"
%}

%option noyywrap
%option yylineno

digit [0-9]
integer {digit}+
float [-+]?[0-9]?*\.?[0-9]+

char [a-zA-Z]

%%

"int"           return TK_PR_INT;
"float"         return TK_PR_FLOAT;
"bool"          return TK_PR_BOOL;
"if"            return TK_PR_IF;
"else"          return TK_PR_ELSE;
"while"         return TK_PR_WHILE;
"return"        return TK_PR_RETURN;

"<="			      return TK_OC_LE;
">="			      return TK_OC_GE;
"=="			      return TK_OC_EQ;
"!="			      return TK_OC_NE;
"&"             return TK_OC_AND;
"|"             return TK_OC_OR;
"->"            return TK_OC_MAP;

{integer}       return TK_LIT_INT;
{float}         return TK_LIT_FLOAT;
"false"         return TK_LIT_FALSE;
"true"          return TK_LIT_TRUE;

.               return TK_ERRO;

%%

int get_line_number() {
	return yylineno;
}
