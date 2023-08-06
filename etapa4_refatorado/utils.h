#pragma once
#include "ast.h"
#include "stack_hash.h"

static void _print_tree (FILE *foutput, Node *tree, int profundidade);
void print_tree(Node *tree);

static void _print_node (FILE *foutput, Node *tree, int profundidade);
void print_node(Node *tree);

static void _asd_print_graphviz (FILE *foutput, Node *tree);
void asd_print_graphviz(Node *tree);

void exporta(void *arvore);