#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table.h"
#include "ast.h"
#include "utils.h"
#include "code.h"

extern Tipo tipo_atual;
extern int list_index;
// extern List *list;

extern List *nodo_inicial;
extern List *nodo_atual;

void addVarSymbol(Symbol **table, Node *node) {
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    if (newSymbol == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // printf(" - %s\n", node->valor_lexico.valor);
    newSymbol->chave = node->valor_lexico.valor;
    newSymbol->linha =  node->valor_lexico.linha;
    newSymbol->tipo = tipo_atual;
    newSymbol->natureza = node->valor_lexico.natureza;

    newSymbol->next = *table;

    *table = newSymbol;
}

void addDefFuncSymbol(Symbol **table, Node *node) {
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    if (newSymbol == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    // printf(" - %s\n", node->valor_lexico.valor);
    newSymbol->chave = node->valor_lexico.valor;
    newSymbol->linha =  node->valor_lexico.linha;
    newSymbol->tipo = tipo_atual;
    newSymbol->natureza = 7;

    newSymbol->next = *table;

    *table = newSymbol;
}

void set_tipo_atual(valorLexico valor_lexico)
{
    tipo_atual = valor_lexico.tipo;
}

void displayTable(struct Symbol* table) {
    struct Symbol* current = table;
    while (current != NULL) {
        printf("chave: %s - tipo: %d - natureza: %d\n", current-> chave, current->tipo, current->natureza);
        current = current->next;
    }
    // printf("\tTable index - %d | current - %p", list->index, list->current);
}

void isInTable(struct Symbol* table, Node *node) {
    struct Symbol* current = table;
    while (current != NULL) {
        if (strcmp(current->chave, node->valor_lexico.valor) == 0) {
            printf("ERRO na linha %d: Identificador declarado previamente: '%s'\n", node->valor_lexico.linha, node->valor_lexico.valor);
            exit(ERR_DECLARED);
        }
        current = current->next;
    }
}

void notInTable(struct Symbol* table, Node *node) {
    int flag = 0;
    struct Symbol* current = table;
    while (current != NULL) {
        // printf("\tchave: %s - valor: %s\n", current->chave, node->valor_lexico.valor);
        if (strcmp(current->chave, node->valor_lexico.valor) == 0){
            flag = 1;
        }
        current = current->next;
    }
    if(flag == 0){
        fprintf(stderr, "Error: funcao nao foi definida!.\n");
        exit(EXIT_FAILURE);
    }
}

void verifyCorrectUsage(Symbol *table, Node *node, Natureza expected_natureza) {
    struct Symbol *current = table;
    int found = 0;

    while (current != NULL) { 
        if (strcmp(node->valor_lexico.valor, current->chave) == 0) {
            found = 1; //Símbolo encontrado na tabela
            if (current->natureza != expected_natureza) { //ERR_FUNCTION 
                if (current->natureza == DEF_FUNCAO) {
                    printf("ERRO na linha %d: Identificador '%s' declarado como função sendo usada como variável\n", node->valor_lexico.linha, node->valor_lexico.valor);
                    exit(ERR_FUNCTION);
                } else if (current->natureza == VARIAVEL) { //ERR_VARIABLE
                    printf("ERRO na linha %d: Identificador '%s' declarado como variável sendo usado como função\n", node->valor_lexico.linha, node->valor_lexico.valor);
                    exit(ERR_VARIABLE);
                }
            }
        }
        current = current->next;
    }

    if (found == 0) { //Símbolo não encontrado na tabela
        printf("ERRO na linha %d: Identificador '%s' não declarado\n", node->valor_lexico.linha, node->valor_lexico.valor);
        exit(ERR_UNDECLARED);
    }
}

void clearTable(Symbol **table) {
    Symbol *current = *table;
    Symbol *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *table = NULL;
}
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void inicializarLista() {
    nodo_inicial = (List *)malloc(sizeof(List));
    nodo_inicial->next = NULL;
    nodo_inicial->prev = NULL;
    nodo_inicial->current = NULL;
    nodo_inicial->index = 0;
    nodo_inicial->n_symbols = 0;
    nodo_atual = nodo_inicial;
}

void adicionarNodo() {
    List *novo_nodo = (List *)malloc(sizeof(List));
    novo_nodo->next = NULL;
    novo_nodo->prev = NULL;  // Não é mais necessário apontar para o nodo_atual
    novo_nodo->current = NULL;
    novo_nodo->index = nodo_atual->index + 1;   // O índice será atualizado quando adicionado à lista

    // Encontrar o último nodo
    List *ultimo_nodo = nodo_inicial;
    while (ultimo_nodo->next != NULL) {
        ultimo_nodo = ultimo_nodo->next;
        novo_nodo->index = ultimo_nodo->index + 1;
    }

    // Adicionar o novo nodo após o último nodo
    ultimo_nodo->next = novo_nodo;
    novo_nodo->prev = ultimo_nodo;

    nodo_atual = novo_nodo;  // Atualizar nodo_atual para apontar para o novo nodo
}

void adicionarSymbol(List *lista, Node *node) {
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    newSymbol->chave = node->valor_lexico.valor;
    newSymbol->linha =  node->valor_lexico.linha;
    newSymbol->tipo = tipo_atual;
    newSymbol->natureza = node->valor_lexico.natureza;
    newSymbol->local_disp = lista->n_symbols * 4;
    newSymbol->scope_disp = lista->index * 4;
    newSymbol->total_disp = newSymbol->local_disp + newSymbol->scope_disp;
    lista->n_symbols++;
    ////////


    if (lista != NULL && newSymbol != NULL) {
        if (lista->current == NULL) {
            lista->current = newSymbol;
        } else {
            Symbol *atual = lista->current;
            while (atual->next != NULL) {
                atual = atual->next;
            }
            atual->next = newSymbol;
        }
    }
}


void adicionarSymbol_DefFunc(List *lista, Node *node) {
    Symbol *newSymbol = (Symbol *)malloc(sizeof(Symbol));
    newSymbol->chave = node->valor_lexico.valor;
    newSymbol->linha =  node->valor_lexico.linha;
    newSymbol->tipo = tipo_atual;
    newSymbol->natureza = 7;
    newSymbol->local_disp = lista->n_symbols * 4;
    if (lista != NULL && newSymbol != NULL) {
        if (lista->current == NULL) {
            lista->current = newSymbol;
        } else {
            Symbol *atual = lista->current;
            while (atual->next != NULL) {
                atual = atual->next;
            }
            atual->next = newSymbol;
        }
    }
}

void imprime_nodo(List *nodo) {
    if (nodo != NULL) {
        printf("Nodo Index: %d\n", nodo->index);
        Symbol *symbol = nodo->current;
        while (symbol != NULL) {
            printf("Chave: %s, Linha: %d\n\tlocal_disp = %d, scope_disp = %d, total_disp = %d\n", symbol->chave, symbol->linha, symbol->local_disp, symbol->scope_disp, symbol->total_disp);
            symbol = symbol->next;
        }
        printf("----------------\n");
    } else {
        printf("Nodo is NULL\n");
    }
}

void imprime_lista() {
    List *atual = nodo_inicial;
    while (atual != NULL) {
        imprime_nodo(atual);
        atual = atual->next;
    }
}

void retrocederNodo() {
    if (nodo_atual != NULL && nodo_atual->prev != NULL) {
        nodo_atual = nodo_atual->prev;
    }
}