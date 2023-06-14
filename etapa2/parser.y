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

program: %empty
        |list;

list: list statement
        | statement;

statement: function
        | global_var;

/* Global variables */

global_var: type list_global_var ';';
                
list_global_var: list_global_var ',' TK_IDENTIFICADOR
        | TK_IDENTIFICADOR;

/* Function */

function: head command_block;

head: TK_IDENTIFICADOR '(' parameter_list ')' TK_OC_MAP type;

parameter_list: %empty
        | parameter
        | parameter_list ',' parameter;

parameter: type TK_IDENTIFICADOR;

/* Command Blocks */

command_block: '{' '}'
      | '{' command_list '}';

command_list: command ';'
        | command_list ';' command;

command: var_declaration
        | assignment
        | flow_control 
        | op_return 
        | command_block
        | function_call;

/* Commands */

var_declaration: type; //WIP

assignment: TK_IDENTIFICADOR '=' expression;

function_call: TK_IDENTIFICADOR '(' expression ')';

op_return: TK_PR_RETURN expression;

flow_control: conditional | iterative;

conditional: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block 
        | TK_PR_IF '(' expression ')' command_block;

iterative: TK_PR_WHILE '(' expression ')' command_block;

/* Expressions */

expression: operands
    | '(' expression ')'
    | '-' expression
    | '!' expression
    | expression '*' expression
    | expression '/' expression
    | expression '%' expression    
    | expression '+' expression
    | expression '-' expression
    | expression '<' expression
    | expression '>' expression
    | expression TK_OC_LE expression
    | expression TK_OC_GE expression
    | expression TK_OC_EQ expression
    | expression TK_OC_NE expression
    | expression TK_OC_AND expression
    | expression TK_OC_OR expression;

operands: TK_IDENTIFICADOR
        | literal
        | function_call

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