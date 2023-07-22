#include "table.h"

Pile *global_pilha_hash = NULL;


void _inicializa_entrada(TableNode *entrada) {
    entrada->key = NULL;
    entrada->item_atr.tipo = -1;
    entrada->item_atr.nature = -1;
    entrada->item_atr.line = -1;
    entrada->item_atr.size = -1;
    // entrada->item_atr.argumentos = NULL;
}

void empilha()
{
    Pile *pilha_aux;
    pilha_aux = malloc(sizeof(Pile));

    pilha_aux->n_table_nodes = 0;
    pilha_aux->table_size = INIT_TABLE_SIZE;

    TableNode *table = _malloc_table();
    pilha_aux->top = table;
    pilha_aux->the_rest = global_pilha_hash;

    global_pilha_hash = pilha_aux;
}

TableNode *_malloc_table() {

    TableNode *table = malloc(sizeof(TableNode) * INIT_TABLE_SIZE);

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        TableNode* entrada = &table[i];
        _inicializa_entrada(entrada);
    }

    return table;
}
