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

program: statement_list | ;

statement_list: statement_list statement | statement;

statement: function | global_variable_declaration;

global_variable_declaration: type global_variable_list ';';

global_variable_list: global_variable_list ',' TK_IDENTIFICADOR | TK_IDENTIFICADOR;

function: header body;

header: TK_IDENTIFICADOR parameters TK_OC_MAP type;

parameters: '(' parameter_list ')' | '(' ')';

parameter_list: parameter_list ',' parameter | parameter;

parameter: type TK_IDENTIFICADOR;

body: command_block;

command_block: '{' simple_command_list '}' | '{' '}';

simple_command_list: simple_command_list command ';' | command ';';

command: command_block | local_variable_declaration | assignment | control_flow | return_statement | function_call;

local_variable_declaration: type local_variable_list;

local_variable_list: local_variable_list ',' local_variable | local_variable;

local_variable: TK_IDENTIFICADOR | TK_IDENTIFICADOR TK_OC_LE literal;

assignment: TK_IDENTIFICADOR '=' expression;

function_call: TK_IDENTIFICADOR '(' arguments ')' | TK_IDENTIFICADOR '(' ')';

arguments: arguments expression | expression;

return_statement: TK_PR_RETURN expression;

control_flow: conditional | iterative;

conditional: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block | TK_PR_IF '(' expression ')' command_block;

iterative: TK_PR_WHILE '(' expression ')' command_block;

// TODO: Consider operator precedence and test everything
expression: operands | operators;

operands: TK_IDENTIFICADOR | literal | function_call;

operators:
    '-' expression |
    '!' expression |
    '(' expression ')' |
    expression '+' expression |
    expression '-' expression |
    expression '*' expression |
    expression '/' expression |
    expression '%' expression |
    expression TK_OC_AND expression |
    expression TK_OC_EQ expression |
    expression TK_OC_GE expression |
    expression TK_OC_LE expression |
    expression TK_OC_NE expression |
    expression TK_OC_OR expression;

literal: TK_LIT_INT | TK_LIT_FLOAT | TK_LIT_FALSE | TK_LIT_TRUE;

type: TK_PR_INT | TK_PR_FLOAT | TK_PR_BOOL;


%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}