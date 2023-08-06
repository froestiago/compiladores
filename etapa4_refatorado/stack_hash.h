#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

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
    // char *valor;

    /* - - - - - - - - - - - */
    struct Symbol *next;
} Symbol;

typedef struct List {
    struct List *next;
    struct List *prev;
    Symbol *current;


    int count;
} List;

void addVarSymbol(Symbol **table, Node *node);
void addDefFuncSymbol(Symbol **table, Node *node);

void set_tipo_atual(valorLexico valor_lexico);

void displayTable(struct Symbol* table);

void isInTable(struct Symbol* table, Node *node);
void notInTable(struct Symbol* table, Node *node);

void err_declared(struct Symbol* table, Node *node);
void err_undeclared(struct Symbol* table, Node *node);

void verifyCorrectUsage(Symbol *table, Node *node, Natureza expected_natureza);

// pega o escopo atual e joga pra list
void abre_escopo(List **lista, Symbol *tabela);
