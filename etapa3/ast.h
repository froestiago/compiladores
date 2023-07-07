#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef struct Node {
  int num_of_children;
  struct Node **children;
  valorLexico valor_lexico;
} Node;

/*
 * Função asd_new, cria um nó sem filhos com o label informado.
 */
Node *create_node(valorLexico valor_lexico);

/*
 * Função asd_add_child, adiciona child como filho de tree.
 */

void add_children(Node *parent, Node *child);

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