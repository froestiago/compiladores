#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack_hash.h"
#include "ast.h"
#include "utils.h"

extern Tipo tipo_atual;

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
    printf("%d", tipo_atual);
}

void displayTable(struct Symbol* table) {
    struct Symbol* current = table;
    while (current != NULL) {
        // printf("%d -> ", current->tipo); // Print the relevant data of the symbol
        printf("chave: %s - tipo: %d - natureza: %d\n", current-> chave, current->tipo, current->natureza);
        current = current->next;
    }
    // printf("NULL\n");
}

void isInTable(struct Symbol* table, Node *node) {
    struct Symbol* current = table;
    while (current != NULL) {
        printf("\tchave: %s - valor: %s\n", current->chave, node->valor_lexico.valor);
        if (strcmp(current->chave, node->valor_lexico.valor) == 0){
            fprintf(stderr, "Error: Duplicate entry found.\n");
            exit(EXIT_FAILURE);
        }
        current = current->next;
    }
    printf("tudo joia\n");
}

void notInTable(struct Symbol* table, Node *node) {
    int flag = 0;
    struct Symbol* current = table;
    while (current != NULL) {
        printf("\tchave: %s - valor: %s\n", current->chave, node->valor_lexico.valor);
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

void abre_escopo(List **lista, Symbol *tabela){
    if(tabela!=NULL){
        // push to list
    }
    
    List* novo = (List*)malloc(sizeof(List));
    novo->current = tabela;
    novo->next = NULL;

    if(*lista == NULL){
        novo->prev = NULL;
        *lista = novo;
    }else{
        List* atual = *lista;
        while (atual->next != NULL)
            atual = atual->next;
        atual->next = novo;
        novo->prev = atual;
    }

}