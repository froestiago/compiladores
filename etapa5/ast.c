#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "utils.h"
#include "code.h"

#define ARQUIVO_SAIDA "saida.dot" //assim sempre fica no diretorio

valorLexico get_yylval(int num_line, Tipo tipo, Natureza natureza, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
    valor_lexico.natureza = natureza;
    valor_lexico.valor = strdup(yytext);

    return valor_lexico;
}

Node* create_node(valorLexico valor_lexico) {
  Node *new_node;
  new_node = malloc(sizeof(Node));

  new_node->num_children = 0;
  new_node->children = NULL;
  new_node->valor_lexico = valor_lexico;
  
  return new_node;
}

void add_children(Node *node, Node *child)
{
  if (node != NULL && child != NULL){
    node->num_children++;
    node->children = realloc(node->children, node->num_children * sizeof(Node*));
    node->children[node->num_children-1] = child;
  }
}

void free_lexical_value(valorLexico valor_lexico)
{
    if (!valor_lexico.valor) return;

    free(valor_lexico.valor);
    
    valor_lexico.valor = NULL;
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