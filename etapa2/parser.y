%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *s);
extern int yylineno;
%}

%define parse.error verbose

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

program:        list
                |%empty;

list:   list function
        | list global_var
        | function
        | global_var;


/* Global variables */

global_var: type list_global_var ';';
list_global_var: list_global_var ',' TK_IDENTIFICADOR
        | TK_IDENTIFICADOR;

/* Function */

function: head func_body;

head: TK_IDENTIFICADOR '(' parameter_list ')' TK_OC_MAP type;

parameter_list: %empty
        | parameter
        | parameter_list ',' parameter;

parameter: type TK_IDENTIFICADOR;

/* func body */

func_body: '{' command_block '}'
        | '{' '}';

command_block: command_block command ';'
        | command ';';

command: var_declaration
        | assignment
        | flow_control 
        | op_return 
        | func_body
        | function_call;

/* Commands */

var_declaration: type var_in_func;
var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func
        | TK_IDENTIFICADOR TK_OC_LE literal
        | TK_IDENTIFICADOR ',' var_in_func
        | TK_IDENTIFICADOR;

assignment: TK_IDENTIFICADOR '=' expression;

function_call: TK_IDENTIFICADOR '(' args ')';
args: arg_list
        | %empty;
arg_list: expression ',' arg_list
        | expression;

/* return */

op_return: TK_PR_RETURN expression;

flow_control: conditional | iterative;

conditional: TK_PR_IF '(' expression ')' func_body TK_PR_ELSE func_body 
        | TK_PR_IF '(' expression ')' func_body;

iterative: TK_PR_WHILE '(' expression ')' func_body;


/* Expressions */

expression : expression TK_OC_OR expression_7
        | expression_7;

expression_7: expression_7 TK_OC_AND expression_6
        | expression_6;

expression_6: expression_6 TK_OC_EQ expression_5
        | expression_6 TK_OC_NE expression_5
        | expression_5;

expression_5: expression_5 '<' expression_4
        | expression_5 '>' expression_4
        | expression_5 TK_OC_LE expression_4
        | expression_5 TK_OC_GE expression_4
        | expression_4;

expression_4: expression_4 '+' expression_3
        | expression_4 '-' expression_3
        | expression_3;

expression_3: expression_3 '*' expression_2
        | expression_3 '/' expression_2
        | expression_3 '%' expression_2
        | expression_2;

expression_2: '-' expression_1
        | '!' expression_1
        | expression_1 ;

expression_1: operands
        | '(' expression ')';

operands: TK_IDENTIFICADOR
        | literal
        | function;

literal: TK_LIT_INT
        | TK_LIT_FLOAT
        | TK_LIT_TRUE
        | TK_LIT_FALSE;

type:   TK_PR_INT
        | TK_PR_FLOAT
        | TK_PR_BOOL;

%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}