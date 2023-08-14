#include "table.h"
int TOP = -1;

Stack *global_stack_hash = NULL;

void initialize_table_entry(TableItem *entry) {
    entry->key = NULL;
    entry->item_atr.tipo = -1;
    entry->item_atr.nature = -1;
    entry->item_atr.line = -1;
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

ValidationResult validateDeclaration(const char* chave) {
    Stack* currentScope = global_stack_hash; // Inicializa a partir do escopo atual

    ValidationResult result;
    result.foundSameScope = false;
    result.foundPreviousScope = false;

    while (currentScope != NULL) { //Percorre a pilha de tabelas do escopo atual até o escopo global
        TableItem* table = currentScope->top;

        for (int i = 0; i < currentScope->n_table_nodes; i++) { //Verifica se a chave está no mesmo escopo
            if (table[i].key != NULL && strcmp(table[i].key, chave) == 0) {
                result.foundSameScope = true; //Chave encontrada na tabela atual
                if (currentScope != global_stack_hash) {
                    result.foundPreviousScope = true; //Chave encontrada em escopo anterior
                }
                return result; // Chave encontrada, retorna o resultado
            }
        }
        currentScope = currentScope->the_rest; //Desce para o escopo anterior
    }
    return result; // Chave não encontrada em nenhum escopo
}

void printTopOfStack(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    TableItem* topItem = stack->top;
    if (topItem == NULL) {
        printf("Top of stack is empty.\n");
    } else {
        printf("Top of stack: Key: %s, Line: %d\n", topItem->key, topItem->item_atr.line);
        // Print other attributes as needed
    }
}

void printLastInsertedItem(Stack* stack) {
    if (stack == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    if (stack->n_table_nodes == 0) {
        printf("Table is empty.\n");
    } else {
        printf("Last inserted item in the table: ");
        TableItem* lastItem = &(stack->top[stack->n_table_nodes - 1]);
<<<<<<< HEAD
        printf("Key: %s, Line: %d, TotalItems: %d\n", lastItem->key, lastItem->item_atr.line, stack->n_table_nodes);
        printf("Nature: %s, Type: %d\n", lastItem->item_atr.nature, lastItem->item_atr.tipo);
=======
        printf("Key: %s, Line: %d\n", lastItem->key, lastItem->item_atr.line);
        printf("\tnumber o stuff in table = %d\t", stack->n_table_nodes);
>>>>>>> etapa5_pre_disp
        // Print other attributes as needed
    }
}

void insertSymbolInTable(Node * node, Nature nature) { //Insere símbolo na tabela se ele não tiver sido encontrado no mesmo escopo ou em escopo anterior     
        TableItem* newEntry = malloc(sizeof(TableItem));
        newEntry->key = node->valor_lexico.valor;
        newEntry->item_atr.tipo = node->valor_lexico.tipo_inf; //tipo;
        newEntry->item_atr.nature = nature;
        newEntry->item_atr.line = node->valor_lexico.linha;

        // Adicione a nova entrada à tabela no topo da pilha
        Stack* currentScope = global_stack_hash;
        int positionInsert = currentScope->n_table_nodes;
        currentScope->top[positionInsert] = *newEntry;
        currentScope->n_table_nodes++;

        printTopOfStack(currentScope);
        printLastInsertedItem(currentScope);
    // } else {
        // printf("O símbolo '%s' já foi declarado anteriormente ou já existe no mesmo escopo.\n", chave);
    // }
}

void insertSymbolIfNotDeclared(Node* node, Nature nature) {//insere símbolo na tabela caso não tenha sido declarado previamente
    const char* chave = node->valor_lexico.valor;

    ValidationResult result = validateDeclaration(chave);

    if (!result.foundSameScope && !result.foundPreviousScope) {//caso não tenha sido declarado previamente
        insertSymbolInTable(node, nature);
    } else {
        // The symbol is already declared in the same or previous scope
        printf("The symbol '%s' is already declared in the same or a previous scope.\n", chave);
    }
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
