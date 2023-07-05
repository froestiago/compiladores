#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct node {
  char *label;
  int num_of_children;
  struct node **children;
} node;

/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
node* create_node(char *label);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */
void add_children(node *parent, node *child);

// /*
//  * Função asd_tree, libera recursivamente o nó e seus filhos.
//  */
// void asd_free(asd_tree_t *tree);

// /*
//  * Função asd_print, imprime recursivamente a árvore.
//  */
// void asd_print(asd_tree_t *tree);

// /*
//  * Função asd_print_graphviz, idem, em formato DOT
//  */
// void asd_print_graphviz (asd_tree_t *tree);
#endif //_ARVORE_H_