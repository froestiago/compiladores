#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ast.h"

#define INIT_TABLE_SIZE 512

typedef enum Nature
{
    NAT_LIT,
    NAT_VAR,
    NAT_FUNC
} Nature;

typedef struct Item {
    int line;
    int size;
    Tipo tipo;
    Nature nature;
    valorLexico valor_lexico;
} Item;

typedef struct TableNode
{
    char *key;
    Item item_atr;
} TableNode;

typedef struct Pile {
    TableNode *top;
    int table_size;
    int n_table_nodes;
    struct Pile *the_rest;
} Pile;

TableNode *_malloc_table();
void _inicializa_entrada(TableNode *entrada);
void empilha();