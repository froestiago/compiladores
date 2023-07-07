%{
#include<stdio.h>
#include<string.h>
#include "ast.h"
// #include "main.h"
extern void* arvore;
int yylex(void);
void yyerror (char const *s);
extern int yylineno;
%}

%code requires { 
    #include "ast.h" 
    #include "valor_lexico.h"
}

%union {
    Node* node;
    valorLexico valor_lexico;
}

%define parse.error verbose

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

/* %token<node> '!' */
// %type<node> program
// %type<node> list
/* %type<node> global_var */
/* %type<node> list_global_var */
// %type<node> function
// %type<node> head
// %type<node> parameter_list
// %type<node> parameter
// %type<node> func_body
// %type<node> command_block
// %type<node> command
// %type<node> var_declaration
// %type<node> var_in_func
// %type<node> assignment
// %type<node> function_call
// %type<node> args
// %type<node> arg_list
// %type<node> op_return
// %type<node> flow_control
// %type<node> conditional
// %type<node> iterative
// %type<node> expression
/* %type<node> expression_1 */
/* %type<node> expression_2 */
//%type<node> expression_3
// %type<node> expression_4
// %type<node> expression_5
// %type<node> expression_6
// %type<node> expression_7
%type<node> literal
/* %type<node> type */


%start literal

%%

// program:  { 
//     $$ = $$; 
// };

// program: list { 
//     $$ = $$; 
// };

// list: list function { 
//     $$ = $1;
//     add_children($$, $2);
// };

// list: list global_var {
//     $$ = $2;
// };

// list: function { 
//     $$ = $1;
// };

// list: global_var { 
//     $$ = NULL;
// };


// /* Global variables */

/* global_var: type list_global_var ';' { 
    $$ = NULL;
    libera($2);
    freeLexicalValue($3);
}; */

/* list_global_var: TK_IDENTIFICADOR ',' list_global_var {
    $$ = NULL;
    freeLexicalValue($1);
    freeLexicalValue($2);
}; */


// list_global_var: TK_IDENTIFICADOR { 
//     $$ = NULL; 
//     freeLexicalValue($1);
// };

// global_var: type list_global_var ';';
// list_global_var: list_global_var ',' TK_IDENTIFICADOR
//         | TK_IDENTIFICADOR;

// /* Function */

// function: head func_body {
//     $$ = $1;
//     add_children($$, $2);
// };

// head: TK_IDENTIFICADOR '(' parameter_list ')' TK_OC_MAP type {
//     $$ = create_node($2);
// };

// parameter_list: %empty
//         | parameter
//         | parameter_list ',' parameter;

// parameter: type TK_IDENTIFICADOR;

// /* func body */

// func_body: '{' command_block '}' {$$ = $1;};
//         | '{' '}';

// command_block: command_block command ';'
//         | command ';';

// command: var_declaration
//         | assignment
//         | flow_control 
//         | op_return 
//         | func_body
//         | function_call;


// command: var_declaration ';' { 
//     $$ = $1;
//     freeLexicalValue($2);
// };

// command: assignment ';' { 
//     $$ = $1;
//     freeLexicalValue($2);
// };

// command: flow_control ';' { 
//     $$ = $1;
//     freeLexicalValue($2);
// };

// command: op_return ';' {
//     $$ = $1;
//     freeLexicalValue($2);
// };

// //func_body

// command: function_call ';' { 
//     $$ = $1;
//     freeLexicalValue($2);
// };

// /* Commands */

// var_declaration: type var_in_func;
// var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func
//         | TK_IDENTIFICADOR TK_OC_LE literal
//         | TK_IDENTIFICADOR ',' var_in_func
//         | TK_IDENTIFICADOR;

// assignment: TK_IDENTIFICADOR '=' expression;

// function_call: TK_IDENTIFICADOR '(' args ')';
// args: arg_list
//         | %empty;
// arg_list: expression ',' arg_list
//         | expression;

// /* return */

// op_return: TK_PR_RETURN expression;

// flow_control: conditional | iterative;

// conditional: TK_PR_IF '(' expression ')' func_body TK_PR_ELSE func_body 
//         | TK_PR_IF '(' expression ')' func_body;

// iterative: TK_PR_WHILE '(' expression ')' func_body;


// /* Expressions */

// expression: expression TK_OC_OR expression_7 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression: expression_7 { 
//     $$ = $1;
// };


// /* expression 7 */

// expression_7: expression_7 TK_OC_AND expression_6 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_7: expression_6 { 
//     $$ = $1;
// };

// /* expression 6 */

// expression_6: expression_6 TK_OC_EQ expression_5 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_6: expression_6 TK_OC_NE expression_5 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);    
// };

// expression_6: expression_5 { 
//     $$ = $1;
// };

// /* expression 5 */
// expression_5: expression_5 '<' expression_4 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_5: expression_5 '>' expression_4 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_5: expression_5 TK_OC_LE expression_4 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_5: expression_5 TK_OC_GE expression_4 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_5: expression_4 { 
//     $$ = $1;
// };

// /* expression 4 */

// expression_4: expression_4 '+' expression_3 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_4: expression_4 '-' expression_3 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_4: expression_3 {
//     $$ = $1;
// };

// /* expression 3 */

// expression_3: expression_3 '*' expression_2 {
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_3: expression_3 '/' expression_2 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_3: expression_3 '%' expression_2 { 
//     $$ = create_node($2);
//     add_children($$, $1);
//     add_children($$, $3);
// };

// expression_3: expression_2 {
//     $$ = $1;
// };

// /* expression 2 */

// expression_2: '-' expression_1 { 
//     $$ = create_node($1);
//     add_children($$, $2);
// };

/* expression_2: '!' expression_1 { 
    $$ = create_node($1);
    add_children($$, $2);
}; */

// expression_2: expression_1 {
//     $$ = $1;
// };

// /* expression 1 */

// expression_1: TK_IDENTIFICADOR { 
//     $$ = create_node($1);
// };

/* expression_1: literal { 
    $$ = $1;
}; */

// expression_1: function { //function or function_call??
//     $$ = $1;
// };

//  expression_1: '(' expression ')' { 
//     $$ = $2;
//     freeLexicalValue($1);
//     freeLexicalValue($3);
// };


// /* Literals */ 

literal: TK_LIT_INT { $$ = create_node($1); };
//
// literal: TK_LIT_FLOAT { 
//     $$ = create_node($1);
// };

// literal: TK_LIT_TRUE { 
//     $$ = create_node($1);
// };

// literal: TK_LIT_FALSE { 
//     $$ = create_node($1);
// };


// /* Types */

/* type: TK_PR_INT { 
    $$ = NULL; 
    freeLexicalValue($1);
}; */

// type: TK_PR_FLOAT { 
//     $$ = NULL; 
//     freeLexicalValue($1);
// };

// type: TK_PR_BOOL { 
//     $$ = NULL; 
//     freeLexicalValue($1);
// };
// */
%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}