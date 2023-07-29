#include "table.h"

Stack *global_stack_hash = NULL;

void initialize_table_entry(TableItem *entry) {
    entry->key = NULL;
    entry->item_atr.tipo = -1;
    entry->item_atr.nature = -1;
    entry->item_atr.line = -1;
    entry->item_atr.size = -1;
    // entry->item_atr.argumentos = NULL;
}

void create_scope()
{
    Stack *pilha_aux;
    pilha_aux = malloc(sizeof(Stack));

    pilha_aux->n_table_nodes = 0;
    pilha_aux->table_size = INIT_TABLE_SIZE;

    TableItem *table = _malloc_table(); //criei tabela sem preencher
    pilha_aux->top = table;
    pilha_aux->the_rest = global_stack_hash;

    global_stack_hash = pilha_aux;
     printf("empilhou!\n");
}

void end_scope()
{
    if (global_stack_hash == NULL) {
        printf("Error: Stack underflow\n");
        return;
    }

    Stack *old_top = global_stack_hash; //current scope

    global_stack_hash = global_stack_hash->the_rest; //remove top pile

    free(old_top->top);
    free(old_top);

    printf("desempilhou!\n");
}

TableItem *_malloc_table() {

    TableItem *table = malloc(sizeof(TableItem) * INIT_TABLE_SIZE);

    for (int i = 0; i < INIT_TABLE_SIZE; i++) {
        TableItem* entry = &table[i];
        initialize_table_entry(entry);
    }
    return table;
}

ValidationResult verificarDeclaracao(const char* chave) {
    Stack* currentScope = global_stack_hash; // Inicializa a partir do escopo atual

    ValidationResult result;
    result.foundSameScope = false;
    result.foundPreviousScope = false;

    // Percorre a pilha de tabelas de símbolos do escopo atual até o escopo global
    while (currentScope != NULL) {
        TableItem* table = currentScope->top;

        // Verifica se a chave está presente na tabela atual
        for (int i = 0; i < currentScope->n_table_nodes; i++) {
            if (table[i].key != NULL && strcmp(table[i].key, chave) == 0) {
                // Chave encontrada na tabela
                result.foundSameScope = true;
                if (currentScope != global_stack_hash) {
                    result.foundPreviousScope = true;
                }
                return result; // Chave encontrada, retorna o resultado
            }
        }
        // Desce para o escopo anterior
        currentScope = currentScope->the_rest;
    }
    return result; // Chave não encontrada em nenhum escopo
}

/*
//declara_literal_em_escopo
TableItem *push_to_hash(Nature nature, valorLexico valor_lexico)
{
    Pile *pile = global_pilha_hash;

    char *chave = get_chave(valor_lexico);

    Content content = get_content(valor_lexico, nature);
    
    // return _insere_topo_pilha(chave, pilha, content)

}

char *get_chave(valorLexico valor_lexico)
{
    return strdup(valor_lexico.valor);
}

Content get_content(valorLexico valor_lexico, Nature nature)
{
    Content content;

    content.line = valor_lexico.linha;
    content.size = 8;
    content.tipo = valor_lexico.tipo;
    content.nature = nature;
    printf("dentro do get_content");
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
