#include "table.h"

Pile *global_pilha_hash = NULL;

void _inicializa_entrada(TableItem *entrada) {
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

    TableItem *table = _malloc_table();
    pilha_aux->top = table;
    pilha_aux->the_rest = global_pilha_hash;

    global_pilha_hash = pilha_aux;
    printf("%f", global_pilha_hash->table_size);
}

void desempilha()
{
    printf("desempilhou!");
}

TableItem *_malloc_table() {

    TableItem *table = malloc(sizeof(TableItem) * INIT_TABLE_SIZE);

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        TableItem* entrada = &table[i];
        _inicializa_entrada(entrada);
    }

    return table;
}
//declara_literal_em_escopo
TableItem *push_to_hash(Nature nature, valorLexico valor_lexico)
{
    Pile *pile = global_pilha_hash;

    char *chave = get_chave(valor_lexico);

    Cell cell = get_cell(valor_lexico, nature);
    
    // return _insere_topo_pilha(chave, pilha, cell)

}

char *get_chave(valorLexico valor_lexico)
{
    return strdup(valor_lexico.valor);
}

Cell get_cell(valorLexico valor_lexico, Nature nature)
{
    Cell cell;

    cell.line = valor_lexico.linha;
    cell.size = 8;
    cell.tipo = valor_lexico.tipo;
    cell.nature = nature;
    printf("dentro do get_cell");
    // valorLexico valor_lexico;
}