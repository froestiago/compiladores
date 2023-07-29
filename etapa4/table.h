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


typedef struct Content {
    int line;
    int size;
    Tipo tipo;
    Nature nature;
    valorLexico valor_lexico;
} Content;

typedef struct TableItem
{
    char *key;
    Content item_atr;
} TableItem;

typedef struct Pile {
    TableItem *top;
    int table_size;
    int n_table_nodes;
    struct Pile *the_rest;
} Pile;

TableItem *_malloc_table();
void _inicializa_entrada(TableItem *entrada);
void empilha();
void desempilha();

TableItem *push_to_hash(Nature nature, valorLexico valor_lexico);
char *get_chave(valorLexico valor_lexico);
Content get_content(valorLexico valor_lexico, Nature nature);
int validate_declaration(valorLexico valor_lexico);
