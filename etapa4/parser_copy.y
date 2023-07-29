%{
#include<stdio.h>
#include<string.h>
#include "ast.h"
#include "table.h"
extern void* arvore;
int yylex(void);
void yyerror (char const *s);
extern int yylineno;
extern void *arvore;
%}

%code requires { 
    #include "ast.h" 
    #include "table.h"
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
%token<valor_lexico> '(' ')' '!' '-' '*' '/' '%' '+' '<' '>' '=' ';' ','

%type<node> program
%type<node> list
%type<node> global_var
%type<node> list_global_var
%type<node> function
%type<node> parameter_list
%type<node> parameter
%type<node> command_block
%type<node> command_list
%type<node> command
%type<node> var_declaration
%type<node> var_in_func
%type<node> assignment
%type<node> function_call
%type<node> args
%type<node> op_return
%type<node> flow_control
%type<node> conditional
%type<node> iterative
%type<node> expression
%type<node> expression_1
%type<node> expression_2
%type<node> expression_3
%type<node> expression_4
%type<node> expression_5
%type<node> expression_6
%type<node> expression_7
%type<node> literal


%start program

%%

//%type<node> func_body %type<node> head

//new_start: create_scope program close_scope

program: %empty {$$ = NULL; arvore = NULL; printf("arvore vazia");}
        | list {$$ = $1; arvore = $$;};

list: function list{ if($1!=NULL){add_children($1, $2); $$=$1;}else{$$=$2;}};
    | global_var list{ if($1!=NULL){add_children($1, $2); $$=$1;}else{$$=$2;}};
    | function {$$ = $1;};
    | global_var {$$ = NULL;};

/* Global variables */

global_var: type list_global_var ';' {$$ = NULL; free_node($2); free_lexical_value($3);};

list_global_var: TK_IDENTIFICADOR ',' list_global_var{$$ = NULL; free_node($3); free_lexical_value($1);}
                | TK_IDENTIFICADOR {$$ = NULL; free_lexical_value($1);};

/* Function */

function: TK_IDENTIFICADOR '(' ')' TK_OC_MAP type command_block {$$ = create_node($1); if($6 != NULL){add_children($$, $6);}}
        | TK_IDENTIFICADOR '(' parameter_list ')' TK_OC_MAP type command_block {$$ = create_node($1); if($7 != NULL){add_children($$, $7);}};

parameter_list: parameter {$$ = NULL;}
	        | parameter_list ',' parameter  {$$ = NULL;}; 

parameter: type TK_IDENTIFICADOR {$$ = NULL;};

/*
command_block: '{' '}' {$$ = NULL;}
             | {empilha();} '{' command_list '}' {desempilha();} {$$ = $2;};*/

command_block: '{' '}' {$$ = NULL;}
            | begin_command_block command_list end_command_block {$$ = $2;};

begin_command_block: '{' {empilha();};
end_command_block: '}' {desempilha();};

command_list: command ';' command_list {if($1 == NULL) {$$ = $3;}else{add_children($1, $3); $$ = $1;}}
	    | command ';' { $$ = $1;};

command: var_declaration {$$ = $1;}
        | assignment {$$ = $1;}
        | flow_control  {$$ = $1;}
        | op_return  {$$ = $1;}
        | command_block {$$ = $1;}
        | function_call {$$ = $1;};

/* Commands */

/*
var_declaration: type var_in_func {
    $$ = $2;
    // Verificar se o identificador já foi declarado
    if (!validate_declaration($2->valor_lexico)) {
        yyerror("throw ERR_DECLARED");
        $$ = NULL;
    }
};
*/

var_declaration: type var_in_func {$$ = $2; };

var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func 
    {$$ = create_node($2);  add_children($$, create_node($1));  add_children($$, $3); add_children($$, $5);}
 | TK_IDENTIFICADOR TK_OC_LE literal 
    {$$ = create_node($2); add_children($$, create_node($1)); add_children($$, $3);}
 | TK_IDENTIFICADOR ',' var_in_func 
    {$$ = $3; free_lexical_value($1); free_lexical_value($2);}
 | TK_IDENTIFICADOR 
    {$$ = NULL; free_lexical_value($1); printf("entrou aqui");}
;

/*var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func {$$ = create_node($2); add_children($$, create_node($1)); add_children($$, $3); add_children($$, $5);
    // Cria uma variável do tipo valorLexico para armazenar informações do identificador encontrado
    valorLexico identificador;
    identificador.linha = $1->valor_lexico.linha;
    identificador.tipo = $1->valor_lexico.tipo;
    identificador.valor = strdup($1->valor_lexico.valor);

    // Verificar se o identificador já foi declarado
    if (!verificar_declaracao(identificador)) {
        yyerror("Undeclared variable");
        free_node($$);
        $$ = NULL;
    }
}
| TK_IDENTIFICADOR TK_OC_LE literal { $$ = create_node($2); add_children($$, create_node($1)); add_children($$, $3);
    // Cria uma variável do tipo valorLexico para armazenar informações do identificador encontrado
    valorLexico identificador;
    identificador.linha = $1->valor_lexico.linha;
    identificador.tipo = $1->valor_lexico.tipo;
    identificador.valor = strdup($1->valor_lexico.valor);

    // Verificar se o identificador já foi declarado
    if (!verificar_declaracao(identificador)) {
        yyerror("Undeclared variable");
        free_node($$);
        $$ = NULL;
    }
}
| TK_IDENTIFICADOR ',' var_in_func {$$ = $3; free_lexical_value($1); free_lexical_value($2);}  // O identificador já foi verificado ao ser declarado, não é necessário verificar novamente aqui.
| TK_IDENTIFICADOR {$$ = NULL; free_lexical_value($1);};  // O identificador já foi verificado ao ser declarado, não é necessário verificar novamente aqui.
*/

assignment: TK_IDENTIFICADOR '=' expression {$$ = create_node($2); add_children($$, create_node($1)); add_children($$, $3);};

function_call: TK_IDENTIFICADOR '(' args ')' {$$ = create_node($1); add_children($$, $3);};

args: %empty {$$ = NULL;}
        | expression ',' args {$$ = $1; add_children($$, $3);}
        | expression {$$ = $1;};

op_return: TK_PR_RETURN expression {$$ = create_node($1); add_children($$, $2);};

flow_control: conditional {$$ = $1;}
            | iterative {$$ = $1;};

conditional: TK_PR_IF '(' expression ')' command_block TK_PR_ELSE command_block {$$ = create_node($1);  add_children($$, $3); add_children($$, $5); add_children($$, $7);}
            | TK_PR_IF '(' expression ')' command_block {$$ = create_node($1); add_children($$, $3); add_children($$, $5);};

iterative: TK_PR_WHILE '(' expression ')' command_block {$$ = create_node($1); add_children($$, $3); add_children($$, $5);};

/* Expressions */
/* regressão a direita ate aqui */
expression: expression TK_OC_OR expression_7 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_7 {$$ = $1;};

expression_7: expression_7 TK_OC_AND expression_6 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
             | expression_6 {$$ = $1;};

expression_6: expression_6 TK_OC_EQ expression_5 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_6 TK_OC_NE expression_5 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_5 {$$ = $1;};

expression_5: expression_5 '<' expression_4 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_5 '>' expression_4 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);};
            | expression_5 TK_OC_LE expression_4 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_5 TK_OC_GE expression_4 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_4 {$$ = $1;};

expression_4: expression_4 '+' expression_3 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_4 '-' expression_3 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_3 {$$ = $1;};

expression_3: expression_3 '*' expression_2 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_3 '/' expression_2 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_3 '%' expression_2 {$$ = create_node($2);add_children($$, $1);add_children($$, $3);}
            | expression_2 {$$ = $1;};

expression_2: '-' expression_1 {$$ = create_node($1); add_children($$, $2);}
            |'!' expression_1 {$$ = create_node($1); add_children($$, $2);}
            | expression_1 {$$ = $1;};

expression_1: TK_IDENTIFICADOR {$$ = create_node($1);}
            | literal {$$ = $1;}
            | function_call {$$ = $1;}
            | '(' expression ')' { $$ = $2; };

/*expression_1: TK_IDENTIFICADOR {$$ = create_node($1);
    valorLexico valor_lexico;
    valor_lexico.linha = $1->valor_lexico.linha; //pega a linha do token
    valor_lexico.tipo = $1->valor_lexico.tipo; //copia o tipo
    valor_lexico.valor = strdup($1->valor_lexico.valor); //copia o valor
    // Verifica se o identificador já foi declarado
    if (!validate_declaration(valor_lexico)) {
        yyerror("throw ERR_UNDECLARED");//UPDATE: aqui precisa lançar mensagem de erro com função especifica
        free_node($$);
        $$ = NULL;
    }}
        | literal {$$ = $1;}
        | function_call {$$ = $1;}
        | '(' expression ')' { $$ = $2; };
*/

/* Literals */ 

literal: TK_LIT_INT    {$$ = create_node($1);}
        | TK_LIT_FLOAT {$$ = create_node($1);}
        | TK_LIT_TRUE  {$$ = create_node($1);}
        | TK_LIT_FALSE {$$ = create_node($1);};

// /* Types */

type:   TK_PR_INT
        |TK_PR_FLOAT
        |TK_PR_BOOL;

%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}