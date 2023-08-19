%{
#include<stdio.h>
#include<string.h>
#include "ast.h"
#include "table.h"
#include "utils.h"
#include "code.h"
extern void* arvore;
int yylex(void);
void yyerror (char const *s);
extern int yylineno;

extern Symbol *tabela_global;
extern Symbol *tabela_atual;
extern Tipo tipo_atual;
// extern List list;
extern List *nodo_inicial;
extern List *nodo_atual;

extern int current_temp;
extern int current_label;
extern int cbr_temp;

extern int disp_rfp;
extern int disp_rbss;

extern Code *code;

// O codigo é gerado em um passagem só

%}

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

%type<valor_lexico> type
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
%type<node> function_type

%type<node> command_block_func



%start init

%%

//%type<node> func_body %type<node> head

init: {inicializarLista();} program

program: %empty {$$ = NULL; arvore = NULL; printf("arvore vazia");}
        | list {$$ = $1;
                arvore = $$;
                // imprime_lista();
                // printf("\n\n\n\n");
                $$->valor_lexico.code = code;
                // printf("----------------\n"); 
                printCodeList();
                };

list: function list{ if($1!=NULL){add_children($1, $2); $$=$1;}else{$$=$2;}};
    | global_var list{ if($1!=NULL){add_children($1, $2); $$=$1;}else{$$=$2;}};
    | function {$$ = $1;};
    | global_var {$$ = NULL;};

/* Global variables */

global_var: type {set_tipo_atual($1);} list_global_var ';' {$$ = NULL; };

list_global_var: TK_IDENTIFICADOR ',' list_global_var{
                        $$ = NULL;
                        // isInTable(tabela_global, create_node($1));
                        // addVarSymbol(&tabela_global, create_node($1));
                        adicionarSymbol(nodo_atual, create_node($1));
                        }

                | TK_IDENTIFICADOR {
                        $$ = NULL;
                        // isInTable(tabela_global, create_node($1));
                        // addVarSymbol(&tabela_global, create_node($1));
                        adicionarSymbol(nodo_atual, create_node($1));
                        }

/* Function */


function: new_node TK_IDENTIFICADOR '(' ')' function_type command_block_func {
                $$ = create_node($2);                                   //$$ = create_node($1);
                if($5 != NULL){add_children($$, $6);}                   //if($5 != NULL){add_children($$, $5);}
                // isInTable(tabela_global, create_node($1));
                adicionarSymbol_DefFunc(nodo_atual, create_node($2));   //adicionarSymbol_DefFunc(nodo_atual, create_node($1));
                // displayTable(tabela_global);
                }
        
        | new_node TK_IDENTIFICADOR '(' parameter_list ')' function_type command_block_func {
                $$ = create_node($2);                                   //$$ = create_node($1); 
                if($6 != NULL) {add_children($$, $7);}                  //if($6 != NULL) {add_children($$, $6);}
                // isInTable(nodo_atual, create_node($1));
                adicionarSymbol_DefFunc(nodo_atual, create_node($2));   //adicionarSymbol_DefFunc(nodo_atual, create_node($1));
                // displayTable(tabela_atual);
                };

new_node: {adicionarNodo();};

function_type: TK_OC_MAP type{set_tipo_atual($2);};

parameter_list: parameter {$$ = NULL;}
	        | parameter ',' parameter_list {$$ = NULL;}; 

parameter: type_aux TK_IDENTIFICADOR {
                $$ = NULL;
                // isInTable(tabela_atual, create_node($2));
                // addVarSymbol(&tabela_atual, create_node($2));
                adicionarSymbol(nodo_atual, create_node($2));
                };

type_aux: type {set_tipo_atual($1);}

command_block: '{' '}' {$$ = NULL;}
                | abre_escopo command_list fecha_escopo {$$ = $2;};

abre_escopo:     '{' {adicionarNodo();};
fecha_escopo:   '}' {retrocederNodo();};

command_block_func: '{' '}' {$$ = NULL;}
                | abre_escopo_func command_list fecha_escopo_func {$$ = $2;};

abre_escopo_func: '{' {};
fecha_escopo_func: '}' {nodo_atual = nodo_inicial;};


command_list: command ';' command_list {if($1 == NULL) {$$ = $3;}else{add_children($1, $3); $$ = $1;}}
	    | command ';' { $$ = $1;};

command: var_declaration {$$ = $1;}
        | assignment {$$ = $1;}
        | flow_control  {$$ = $1;}
        | op_return  {$$ = $1;}
        | command_block {$$ = $1;}
        | function_call {$$ = $1;};

/* Commands */

var_declaration: type_aux var_in_func {
                $$ = $2;};

var_in_func: TK_IDENTIFICADOR TK_OC_LE literal ',' var_in_func {
                $$ = create_node($2);
                add_children($$, create_node($1)); 
                add_children($$, $3);
                add_children($$, $5);
                // isInTable(tabela_atual, create_node($1));
                // addVarSymbol(&tabela_atual, create_node($1));
                adicionarSymbol(nodo_atual, create_node($1));

                // Instruction *instruction_load = add_loadI($3->valor_lexico.valor,$3->valor_lexico.temp);
                // $$->valor_lexico.code = addInstruction(instruction_load);
                // int disp = find_disp(nodo_atual, $1.valor);
                // Instruction *instruction_store = add_storeAI($3->valor_lexico.temp, "rfp", disp);
                // $$->valor_lexico.code = addInstruction(instruction_store);
                }
 
        | TK_IDENTIFICADOR TK_OC_LE literal {
                $$ = create_node($2);
                add_children($$, create_node($1));
                add_children($$, $3);
                // isInTable(tabela_atual, create_node($1));
                // addVarSymbol(&tabela_atual, create_node($1));
                adicionarSymbol(nodo_atual, create_node($1));
                // printf("\nUAU UAU UAU UAU");
                Instruction *instruction_load = add_loadI($3->valor_lexico.valor,$3->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction_load);
                int disp = find_disp(nodo_atual, $1.valor);
                char *base = find_base(nodo_atual, $1.valor);
                Instruction *instruction_store = add_storeAI($3->valor_lexico.temp, base, disp);
                $$->valor_lexico.code = addInstruction(instruction_store);
                }

        | TK_IDENTIFICADOR ',' var_in_func {
                $$ = $3; //$$ = $1
                // free_lexical_value($1);
                // free_lexical_value($2);
                // isInTable(tabela_atual, create_node($1));
                // addVarSymbol(&tabela_atual, create_node($1));
                adicionarSymbol(nodo_atual, create_node($1)); //$3
                }
 
        | TK_IDENTIFICADOR {
                $$ = NULL;
                // free_lexical_value($1);
                // isInTable(tabela_atual, create_node($1));
                // addVarSymbol(&tabela_atual, create_node($1));
                adicionarSymbol(nodo_atual, create_node($1));
                };

assignment: TK_IDENTIFICADOR '=' expression {
                $$ = create_node($2);
                add_children($$, create_node($1));
                add_children($$, $3);
                // printf("aushuashasuhaushuashush");
                // verifyCorrectUsage(tabela_atual, create_node($1), VARIAVEL);
                char *base = find_base(nodo_atual, $1.valor);
                int disp = find_disp(nodo_atual, $1.valor);
                Instruction *instruction = add_storeAI($3->valor_lexico.temp, base, disp);
                // printf("\t base - %s", instruction->parameter_2);
                $$->valor_lexico.code = addInstruction(instruction);
                };

function_call: TK_IDENTIFICADOR '(' args ')' {
                $$ = create_node($1);
                add_children($$, $3);
                // verifyCorrectUsage(tabela_global, $$, DEF_FUNCAO);
                };

args: %empty {$$ = NULL;}
        | expression ',' args {$$ = $1; add_children($$, $3);}
        | expression {$$ = $1;};

op_return: TK_PR_RETURN expression {$$ = create_node($1); add_children($$, $2);};

flow_control: conditional {$$ = $1;}
            | iterative {$$ = $1;};

add_label_to_code: {
            add_label(current_label);
            current_label+=1;
        }

add_cbr: {
            add_cbr(cbr_temp, current_label, current_label+1);
        }

add_jumpI_else: {
            /* this jumpI goes at the end of the command_block of the if statement*/
            /* in case the if statement is true it won't go throught the else ;) */
            add_jumpI(current_label+1);
            /* not +2 since it already has a add_label_to_code before it, which gives it the +1  */
        }

conditional: TK_PR_IF '(' expression ')' add_cbr add_label_to_code command_block add_jumpI_else TK_PR_ELSE add_label_to_code command_block add_label_to_code{
                $$ = create_node($1); 
                add_children($$, $3);
                add_children($$, $7);
                add_children($$, $11);
                }
            | TK_PR_IF '(' expression ')' add_cbr add_label_to_code command_block add_label_to_code {
                $$ = create_node($1);
                add_children($$, $3);
                add_children($$, $7);
                };

iterative: TK_PR_WHILE '(' expression ')' command_block {
                $$ = create_node($1);
                add_children($$, $3);
                add_children($$, $5);
                };

/* Expressions */
/* regressão a direita ate aqui */
expression: expression TK_OC_OR expression_7 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("or", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            | expression_7 {$$ = $1;};

expression_7: expression_7 TK_OC_AND expression_6 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("and", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
             | expression_6 {$$ = $1;};

expression_6: expression_6 TK_OC_EQ expression_5 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_EQ", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            | expression_6 TK_OC_NE expression_5 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_NE", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            | expression_5 {$$ = $1;};

expression_5: expression_5 '<' expression_4 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_LT", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            | expression_5 '>' expression_4 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_GT", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                };
            
            
            | expression_5 TK_OC_LE expression_4 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_LE", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            
            
            | expression_5 TK_OC_GE expression_4 {
                $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                
                $$->valor_lexico.temp = current_temp;
                cbr_temp = current_temp;
                current_temp++;
                Instruction *instruction = add_custom_instruction("cmp_GE", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                $$->valor_lexico.code = addInstruction(instruction);
                }
            
            | expression_4 {$$ = $1;};

expression_4: expression_4 '+' expression_3 {
                        // add node
                        $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                        
                        // add code
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("add", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                        $$->valor_lexico.code = addInstruction(instruction);
                        }
            
            | expression_4 '-' expression_3 {
                        $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                        
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("sub", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                        $$->valor_lexico.code = addInstruction(instruction);
                        // printf("%s", $$->valor_lexico.code.instruction.oper);
                        // printListFromNode($$->valor_lexico.code);
                        }


            | expression_3 {$$ = $1;};

expression_3: expression_3 '*' expression_2 {
                        $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                        
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("mult", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                        $$->valor_lexico.code = addInstruction(instruction);
                        // printListFromNode($$->valor_lexico.code);
                        // printf("\n\t\t%u\n", $$->valor_lexico.code);
                        // printf("\n\n1 - %s\n\n", $$->valor_lexico.code->next_instruction->instruction->oper);
                        
                        }
            
            | expression_3 '/' expression_2 {
                        $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                        
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        Instruction *instruction = add_custom_instruction("div", $1->valor_lexico.temp, $3->valor_lexico.temp, $$->valor_lexico.temp);
                        $$->valor_lexico.code = addInstruction(instruction);
                        }
            
            | expression_3 '%' expression_2 {
                        $$ = create_node($2);add_children($$, $1);add_children($$, $3);
                        }
            | expression_2 {$$ = $1;};

expression_2: '-' expression_1 {$$ = create_node($1); add_children($$, $2);}
            |'!' expression_1 {$$ = create_node($1); add_children($$, $2);}
            | expression_1 {$$ = $1;};

expression_1: TK_IDENTIFICADOR {
                        Node *node = create_node($1);
                        $$ = node;
                        // printf(" - %s", $$->valor_lexico.linha);
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp++;
                        // achar disp, percorer lista de tabelas da atual para tras
                        int disp = find_disp(nodo_atual, $$->valor_lexico.valor);
                        char *base = find_base(nodo_atual, $$->valor_lexico.valor);
                        Instruction *instruction = add_loadAI($$->valor_lexico.temp, base, disp);
                        $$->valor_lexico.code = addInstruction(instruction);
                        }
            | literal {$$ = $1;
                        // printf("um dois tres quatro cinco");
                        // printf("\n\t\tpra cima - %d\n",$$->valor_lexico.temp);
                        Instruction *instruction_load = add_loadI($1->valor_lexico.valor,$1->valor_lexico.temp);
                        $$->valor_lexico.code = addInstruction(instruction_load);
                        
                        
            }
            | function_call {$$ = $1;}
            | '(' expression ')' { $$ = $2; };


/* Literals */ 

literal: TK_LIT_INT    {$$ = create_node($1);
                        $$->valor_lexico.temp = current_temp;
                        cbr_temp = current_temp;
                        current_temp = current_temp + 1;
                        
                        };
        | TK_LIT_FLOAT {$$ = create_node($1);}
        | TK_LIT_TRUE  {$$ = create_node($1);}
        | TK_LIT_FALSE {$$ = create_node($1);};

// /* Types */

type:   TK_PR_INT       { $$ = $1; }
        |TK_PR_FLOAT    { $$ = $1; }
        |TK_PR_BOOL     { $$ = $1; };

%%

void yyerror (char const *s){
    fprintf(stderr, "Error on line %d: %s\n", yylineno, s);
}