#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

#define ARQUIVO_SAIDA "saida.dot" //assim sempre fica no diretorio

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
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

void add_children(Node *tree, Node *child)
{
  if (tree != NULL && child != NULL){
    tree->num_children++;
    tree->children = realloc(tree->children, tree->num_children * sizeof(Node*));
    tree->children[tree->num_children-1] = child;
  }
}

static void _print_tree (FILE *foutput, Node *tree, int profundidade)
{
  int i;
  if (tree != NULL)
  {
    if(tree != NULL){
      for (i = 0; i < tree->num_children; i++){
        fprintf(foutput, "%p - %p\n", tree, tree->children[i]);
      }
    }
    for (i = 0; i < tree->num_children; i++){
      _print_tree(foutput, tree->children[i], profundidade+1);
    }

  }
}


static void _print_node (FILE *foutput, Node *tree, int profundidade)
{
  int i;
  if (tree != NULL)
  {
    fprintf(foutput, "%p [label=\"%s\"];\n", tree, tree->valor_lexico.valor);
    
    for (i = 0; i < tree->num_children; i++){
      _print_node(foutput, tree->children[i], profundidade+1);
    }

  }
}


void print_node(Node *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL){
    _print_node(foutput, tree, 0);
  }
}

void print_tree(Node *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL){
    _print_tree(foutput, tree, 0);
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