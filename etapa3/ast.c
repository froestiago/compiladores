#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

node* create_node(char *label) {
  node *new_node = NULL;
  new_node = calloc(1, sizeof(node));
  if (new_node != NULL){
    new_node->label = label;
    new_node->children = NULL;
    new_node->num_of_children = 0;
    return new_node;
  }
}

void add_children(node *parent, node *child) {
  parent->num_of_children++;
  parent->children = realloc(parent->children, parent->num_of_children * sizeof(struct node*));
}

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