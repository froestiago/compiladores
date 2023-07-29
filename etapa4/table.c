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

//cria escopo
void empilha()
{
    Pile *pilha_aux;
    pilha_aux = malloc(sizeof(Pile));

    pilha_aux->n_table_nodes = 0;
    pilha_aux->table_size = INIT_TABLE_SIZE;

    TableItem *table = _malloc_table(); //criei tabela sem preencher
    pilha_aux->top = table;
    pilha_aux->the_rest = global_pilha_hash;

    global_pilha_hash = pilha_aux;
     printf("empilhou!\n");
}

void desempilha()
{
    if (global_pilha_hash == NULL) {
        printf("Error: Stack underflow\n");
        return;
    }

    Pile *old_top = global_pilha_hash; //current scope

    global_pilha_hash = global_pilha_hash->the_rest; //remove top pile

    free(old_top->top);
    free(old_top);

    printf("desempilhou!\n");
}

TableItem *_malloc_table() {

    TableItem *table = malloc(sizeof(TableItem) * INIT_TABLE_SIZE);

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        TableItem* entrada = &table[i];
        _inicializa_entrada(entrada);
    }

    return table;
}
/*
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

int validate_declaration(valorLexico valor_lexico) {
    Pile *pilha_aux = global_pilha_hash;

    while (pilha_aux != NULL) {
        TableItem *entry = pilha_aux->top;
        for (int i = 0; i < pilha_aux->n_table_nodes; i++) {
            if (entry[i].key != NULL && strcmp(entry[i].key, valor_lexico.valor) == 0) {
                // Identificador já foi declarado em algum escopo
                return 0;
            }
        }
        pilha_aux = pilha_aux->the_rest;
    }

    // Identificador ainda não foi declarado em nenhum escopo
    return 1;
}
*/
