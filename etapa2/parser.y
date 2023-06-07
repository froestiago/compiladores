%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *s);
%}

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_OC_MAP
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%

programa:;
programa: lista;
lista: lista elemento | elemento;
elemento: funcao | declaracao_variavel_global;
funcao: 'a';
declaracao_variavel_global: 'b';

tipo: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;

%%

void yyerror (char const *s){
    printf("%s\n", s);
}