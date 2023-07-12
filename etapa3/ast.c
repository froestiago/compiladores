#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
    valor_lexico.valor = strdup(yytext);

    return valor_lexico;
}

Node* create_node(valorLexico valor_lexico) {
  Node *new_node = NULL;
  new_node = malloc(sizeof(Node));
  new_node->num_children = 0;
  new_node->children = NULL;
  new_node->valor_lexico = valor_lexico;
  
  return new_node;
}

void free_lexical_value(valorLexico valor_lexico)
{
    if (!valor_lexico.valor) return;

    free(valor_lexico.valor);
    
    valor_lexico.valor = NULL;
}

void add_children(Node *parent, Node *child) {
    if(child!= NULL && parent!=NULL){
        if(parent->children==NULL){
            parent->children = child;
        }
    }
}

void print_tree(Node* root, int level) {
    if (root == NULL)
        printf("\nblau blau");
        return;

    printf("%*s%s\n", level * 4, "valor_lexico.valor: \t\t", root->num_children);

    for (int i = 0; i < root->num_children; i++) {
        print_tree(root->children[i], level + 1);
    }
}


void free_node(Node* node)
{
    if (!node) return;
    
    free_lexical_value(node->valor_lexico);

    for (int i = 0; i < node->num_children; i++) {
        free_node(node->children[i]);
    }

    free(node->children);
    free(node);
}

void exporta(void *arvore)
{
    Node *nodo_arvore;
    nodo_arvore = (Node*) arvore;
    print_tree(nodo_arvore, 1);
    return;
}