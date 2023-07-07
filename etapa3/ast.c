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

// void imprime_arvore(Node *nodo, int profundidade)
// {
//     int i = 0;

//     if (nodo == NULL)
//         return;
    
//     for(i = 0; i<profundidade-1; i++) 
//     {
//         printf("    ");
//     }

//     if (profundidade == 0)
//         printf("%s", nodo->valor_lexico);
//     else 
//     {
//         printf("+---");
//         printf("%s", nodo->valor_lexico);
//     }
//     printf("\n");

//     Node *nodo_f = nodo->children;
//     // while(nodo_f!=NULL)
//     // {
//     //     imprime_arvore(nodo_f, profundidade+1);
//     //     nodo_f = nodo_f->;
//     // }
    
//     return;
// }