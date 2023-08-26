#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "code.h"

#define MAX_SYMBOLS 100

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_FUNCTION 21 //2.3

typedef struct Symbol {
    char *chave;
    
    // Content (basicamente valor lexico)
    int linha;
    Tipo tipo;
    Natureza natureza;
    char *valor;

    /* - - - - - - - - - - - */
    struct Symbol *next;

    int disp;
    char *base;
} Symbol;

typedef struct List {
    struct List *next;
    struct List *prev;
    struct Symbol *current;
    int index;
} List;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

typedef struct AssemblySymbol{
    char *base;
    char *disp;
    char *value;
    char *temp;
    struct AssemblySymbol *next; // Pointer to the next node
} AssemblySymbol;

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void addVarSymbol(Symbol **table, Node *node);
void addDefFuncSymbol(Symbol **table, Node *node);

void set_tipo_atual(valorLexico valor_lexico);

void displayTable(struct Symbol* table);

void isInTable(struct Symbol* table, Node *node);
void notInTable(struct Symbol* table, Node *node);

void err_declared(struct Symbol* table, Node *node);
void err_undeclared(struct Symbol* table, Node *node);

void verifyCorrectUsage(Symbol *table, Node *node, Natureza expected_natureza);

void clearTable(Symbol **table);

// pega o escopo atual e joga pra list
void abre_escopo(List **lista, Symbol *tabela);

void add_to_list(Symbol **tabela_atual, List **global_list);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void inicializarLista();
void adicionarNodo();
void adicionarSymbol(List *lista, Node *node);
void adicionarSymbol_DefFunc(List *lista, Node *node);

void imprime_nodo(List *nodo);
void imprime_lista();

void retrocederNodo();

int find_disp(struct List *startNode, char *key);
char * find_base(struct List *startNode, char *key);
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
// assembly symbol table

AssemblySymbol *createNodeWithValueTemp(char *value, char *temp);
AssemblySymbol *createNodeWithBaseDisp(char *base, char *disp);
void addToAssemblyTable(AssemblySymbol *newSymbol);
void print_code_list_assembly();
void updateBaseDisp(char *targetTemp, char *updateBase, char *updateDisp);
void updateTemp(char *updateTemp, char *targetBase, char *targetDisp);

char * getBase(char *targetTemp);
char * getDisp(char *targetTemp);
