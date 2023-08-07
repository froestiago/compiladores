#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table.h"
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
