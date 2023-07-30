#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

#define ARQUIVO_SAIDA "saida.dot" //assim sempre fica no diretorio

valorLexico get_yylval(int num_line, Tipo tipo, TipoInf tipo_inf, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
    valor_lexico.tipo_inf = tipo_inf;
    valor_lexico.valor = strdup(yytext);

    switch(valor_lexico.tipo_inf){
      case INF_INT:
        valor_lexico.valor_int=atoi(yytext);
        // printf("\t\t%d", valor_lexico.valor_int);
        break;
      case INF_FLOAT:
        valor_lexico.valor_float=atof(yytext);
        // printf("\t\t%f", valor_lexico.valor_float);
        break;
      case INF_BOOL:
        if(strcmp (yytext,"true") == 0){valor_lexico.valor_bool = true;}else{valor_lexico.valor_bool = false;}
        // printf("\t\t%d", valor_lexico.valor_bool);
        break;
    }

    return valor_lexico;
}

Node* create_node(valorLexico valor_lexico) {
  Node *new_node;
  new_node = malloc(sizeof(Node));

  new_node->num_children = 0;
  new_node->children = NULL;
  new_node->valor_lexico = valor_lexico;
  new_node->tipo_inf = valor_lexico.tipo_inf;
  
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

static void _print_tree (FILE *foutput, Node *node, int profundidade)
{
  int i;
  if (node != NULL)
  {
    if(node != NULL){
      for (i = 0; i < node->num_children; i++){
        fprintf(foutput, "%p - %p\n", node, node->children[i]);
      }
    }
    for (i = 0; i < node->num_children; i++){
      _print_tree(foutput, node->children[i], profundidade+1);
    }

  }
}


static void _print_node (FILE *foutput, Node *node, int depth)
{
  int i;
  if (node != NULL)
  {
    fprintf(foutput, "%p [label=\"%u\"];\n", node, node->tipo_inf);
    
    for (i = 0; i < node->num_children; i++){
      _print_node(foutput, node->children[i], depth+1);
    }

  }
}


void print_node(Node *node)
{
  FILE *foutput = stderr;
  if (node != NULL){
    _print_node(foutput, node, 0);
  }
}

void print_tree(Node *node)
{
  FILE *foutput = stderr;
  if (node != NULL){
    _print_tree(foutput, node, 0);
  }
}




static void _asd_print_graphviz (FILE *foutput, Node *tree)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->valor_lexico.valor);
    for (i = 0; i < tree->num_children; i++){
      fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->children[i]);
      _asd_print_graphviz(foutput, tree->children[i]);
    }
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print_graphviz(Node *tree)
{
  FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
  if(foutput == NULL){
    printf("Erro: %s não pude abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
  }
  if (tree != NULL){
    fprintf(foutput, "digraph grafo {\n");
    _asd_print_graphviz(foutput, tree);
    fprintf(foutput, "}\n");
    fclose(foutput);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
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

void exporta(void *arvore)
{
    Node *nodo_arvore;
    nodo_arvore = (Node*) arvore;
    print_tree(arvore);
    print_node(arvore);
    asd_print_graphviz(arvore);
    return;
}