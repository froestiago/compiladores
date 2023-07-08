#pragma once

#ifndef _ARVORE_H_
#define _ARVORE_H_
#include "valor_lexico.h"

typedef struct Node {
  int num_of_children;
  struct Node **children;
  valorLexico valor_lexico;
} Node;

Node *create_node(valorLexico valor_lexico);

void add_children(Node *parent, Node *child);

#endif //_ARVORE_H_