%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *s);
extern int yylineno;
%}

%define parse.error detailed

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

%start program

%%

program: list
        | ;

list: list statement
        | statement
        | ;

statement: function
        | global_var
        | ;

/* Global variables */

global_var: type list_global_var ';';
                
list_global_var: list_global_var ',' TK_IDENTIFICADOR
        | TK_IDENTIFICADOR
        | ;

/* Function */

function: head body;
head: TK_IDENTIFICADOR '(' params_list ')' TK_OC_MAP type;
body:  %empty ; //WIP

params_list: params_list ',' param
        | param
        | %empty;

param: type TK_IDENTIFICADOR

/* Command Blocks */

command_block:  %empty //WIP

command: op_assignment
        | flow_control
        | op_return
        | command_block

flow_control: conditional | iterative;

conditional: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block | TK_PR_IF '(' expression ')' command_block;

iterative: TK_PR_WHILE '(' expression ')' command_block;

op_assignment: TK_IDENTIFICADOR '=' expression;

op_return: TK_PR_RETURN expression;

expression: %empty; //WIP

literal: TK_LIT_INT
        | TK_LIT_FLOAT
        | TK_LIT_TRUE
        | TK_LIT_FALSE;

type:   TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_BOOL;

functions: %empty; //WIP

%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}