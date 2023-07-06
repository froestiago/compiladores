%{
#include <stdio.h>
int yylex(void);
void yyerror (char const *s);
extern int yylineno;
%}

%define parse.error verbose
%code requires { #include "ast.h" }

%union {
    Node* valor_lexico;
}

%token<valor_lexico> TK_PR_INT
%token<valor_lexico> TK_PR_FLOAT
%token<valor_lexico> TK_PR_BOOL
%token<valor_lexico> TK_PR_IF
%token<valor_lexico> TK_PR_ELSE
%token<valor_lexico> TK_PR_WHILE
%token<valor_lexico> TK_PR_RETURN
%token<valor_lexico> TK_OC_LE
%token<valor_lexico> TK_OC_GE
%token<valor_lexico> TK_OC_EQ
%token<valor_lexico> TK_OC_NE
%token<valor_lexico> TK_OC_AND
%token<valor_lexico> TK_OC_OR
%token<valor_lexico> TK_OC_MAP
%token<valor_lexico> TK_IDENTIFICADOR
%token<valor_lexico> TK_LIT_INT
%token<valor_lexico> TK_LIT_FLOAT
%token<valor_lexico> TK_LIT_FALSE
%token<valor_lexico> TK_LIT_TRUE
%token<valor_lexico> TK_ERRO

%type<valor_lexico> program
%type<valor_lexico> list
%type<valor_lexico> global_var
%type<valor_lexico> list_global_var
%type<valor_lexico> function
%type<valor_lexico> head
%type<valor_lexico> parameter_list
%type<valor_lexico> parameter
%type<valor_lexico> func_body
%type<valor_lexico> command_block
%type<valor_lexico> command
%type<valor_lexico> var_declaration
%type<valor_lexico> var_in_func
%type<valor_lexico> assignment
%type<valor_lexico> function_call
%type<valor_lexico> args
%type<valor_lexico> arg_list
%type<valor_lexico> op_return
%type<valor_lexico> flow_control
%type<valor_lexico> conditional
%type<valor_lexico> iterative
%type<valor_lexico> expression
%type<valor_lexico> expression_1
%type<valor_lexico> expression_2
%type<valor_lexico> expression_3
%type<valor_lexico> expression_4
%type<valor_lexico> expression_5
%type<valor_lexico> expression_6
%type<valor_lexico> expression_7
%type<valor_lexico> operands
%type<valor_lexico> literal
%type<valor_lexico> type


%start program

%%
program:  { 
    $$ = NULL; 
    arvore = NULL; 
};

program: list { 
    $$ = $1; 
    arvore = $$;
};

list: list function { 
    $$ = $1;
    addChild($$, $2);
};

list: list global_var {
    $$ = $2;
};

list: function { 
    $$ = $1;
};

list: global_var { 
    $$ = NULL;
};


/* Global variables */

global_var: type list_global_var ';' { 
    $$ = NULL;
    libera($2);
    freeLexicalValue($3);
};

list_global_var: TK_IDENTIFICADOR ',' list_global_var {
    $$ = NULL;
    freeLexicalValue($1);
    freeLexicalValue($2);
};


list_global_var: TK_IDENTIFICADOR { 
    $$ = NULL; 
    freeLexicalValue($1);
};

global_var: type list_global_var ';';
list_global_var: list_global_var ',' TK_IDENTIFICADOR
        | TK_IDENTIFICADOR;

/* Function */

function: head func_body {
    $$ = $1;
    addChild($$, $2);
};

head: TK_IDENTIFICADOR '(' parameter_list ')' TK_OC_MAP type {
    $$ = createNode($2);
};

parameter_list: %empty
        | parameter
        | parameter_list ',' parameter;

parameter: type TK_IDENTIFICADOR;

/* func body */

func_body: '{' command_block '}' {$$ = $1;};
        | '{' '}';

command_block: command_block command ';'
        | command ';';

command: var_declaration
        | assignment
        | flow_control 
        | op_return 
        | func_body
        | function_call;


command: var_declaration ';' { 
    $$ = $1;
    freeLexicalValue($2);
};

command: assignment ';' { 
    $$ = $1;
    freeLexicalValue($2);
};

command: flow_control ';' { 
    $$ = $1;
    freeLexicalValue($2);
};

command: op_return ';' {
    $$ = $1;
    freeLexicalValue($2);
};

//func_body

command: function_call ';' { 
    $$ = $1;
    freeLexicalValue($2);
};

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

expression: expression TK_OC_OR expression_7 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression: expression_7 { 
    $$ = $1;
};


/* expression 7 */

expression_7: expression_7 TK_OC_AND expression_6 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_7: expression_6 { 
    $$ = $1;
};

/* expression 6 */

expression_6: expression_6 TK_OC_EQ expression_5 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_6: expression_6 TK_OC_NE expression_5 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);    
};

expression_6: expression_5 { 
    $$ = $1;
};

/* expression 5 */
expression_5: expression_5 '<' expression_4 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_5: expression_5 '>' expression_4 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_5: expression_5 TK_OC_LE expression_4 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_5: expression_5 TK_OC_GE expression_4 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_5: expression_4 { 
    $$ = $1;
};

/* expression 4 */

expression_4: expression_4 '+' expression_3 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_4: expression_4 '-' expression_3 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_4: expression_3 {
    $$ = $1;
};

/* expression 3 */

expression_3: expression_3 '*' expression_2 {
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_3: expression_3 '/' expression_2 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_3: expression_3 '%' expression_2 { 
    $$ = createNode($2);
    addChild($$, $1);
    addChild($$, $3);
};

expression_3: expression_2 {
    $$ = $1;
};

/* expression 2 */

expression_2: '-' expression_1 { 
    $$ = createNode($1);
    addChild($$, $2);
};

expression_2: '!' expression_1 { 
    $$ = createNode($1);
    addChild($$, $2);
};

expression_2: expression_1 {
    $$ = $1;
};

/* expression 1 */

expression_1: TK_IDENTIFICADOR { 
    $$ = createNode($1);
};

expression_1: literal { 
    $$ = $1;
};

expression_1: function { //function or function_call??
    $$ = $1;
};

 expression_1: '(' expression ')' { 
    $$ = $2;
    freeLexicalValue($1);
    freeLexicalValue($3);
};


/* Literals */ 

literal: TK_LIT_INT { 
    $$ = createNode($1);
};

literal: TK_LIT_FLOAT { 
    $$ = createNode($1);
};

literal: TK_LIT_TRUE { 
    $$ = createNode($1);
};

literal: TK_LIT_FALSE { 
    $$ = createNode($1);
};


/* Types */
type: TK_PR_INT { 
    $$ = NULL; 
    freeLexicalValue($1);
};

type: TK_PR_FLOAT { 
    $$ = NULL; 
    freeLexicalValue($1);
};

type: TK_PR_BOOL { 
    $$ = NULL; 
    freeLexicalValue($1);
};

%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}
