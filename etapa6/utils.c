#include "utils.h"

#define ARQUIVO_SAIDA "saida.dot" //assim sempre fica no diretorio

static void _print_node (FILE *foutput, Node *node, int depth)
{
  int i;
  if (node != NULL)
  {
    fprintf(foutput, "%p [label=\"%u\"];\n", node, node->valor_lexico.tipo);
    
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

void exporta(void *arvore)
{
    Node *nodo_arvore;
    nodo_arvore = (Node*) arvore;
    print_tree(arvore);
    print_node(arvore);
    asd_print_graphviz(arvore);
    printf("aqui");
    return;
}