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

Node *create_node(valorLexico valor_lexico) {
  Node *new_node = NULL;
  new_node = calloc(1, sizeof(Node));
  if (new_node != NULL){
    new_node->num_of_children = 0;
    new_node->children = NULL;
    new_node->valor_lexico = valor_lexico;
  }
  return new_node;
}

void free_lexical_value(valorLexico valor_lexico)
{
    if (!valor_lexico.valor) return;

    free(valor_lexico.valor);
    
    valor_lexico.valor = NULL;
}

void add_children(Node *parent, Node *child) {
  parent->num_of_children++;
  parent->children = realloc(parent->children, parent->num_of_children * sizeof(struct Node*));
}


void free_node(Node* node)
{
    if (!node) return;
    
    free_lexical_value(node->valor_lexico);

    Node* child = node->children;
    free_node(child);

    free(node);
}