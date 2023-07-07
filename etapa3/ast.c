#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"
#include "valor_lexico.h"

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

void add_children(Node *parent, Node *child) {
  parent->num_of_children++;
  parent->children = realloc(parent->children, parent->num_of_children * sizeof(struct Node*));
}

//usar este main para testar funcionalidades da arvore

// int main() {
//   struct node* pai = create_node("0");
//   struct node* filho = create_node("1");
//   struct node* filha = create_node("2");
//   struct node* filho_2 = create_node("3");

//   add_children(pai, filho);
//   add_children(pai, filha);
//   add_children(pai, filho_2);

//   printf("numero de filho do root: %d", pai->num_of_children);

// }