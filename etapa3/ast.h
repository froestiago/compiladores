#pragma once
#ifndef _ARVORE_H_
#define _ARVORE_H_

typedef enum tipo {
    CARACTERE_ESPECIAL,
    PALAVRA_RESERVADA,
    OPERADOR_COMPOSTO,
    IDENTIFICADOR,
    LITERAL
} Tipo;

typedef struct valor_lexico {
    int linha;
    Tipo tipo;
    char *valor;
} valorLexico;

typedef struct Node {
  int num_children;
  struct Node** children;
  valorLexico valor_lexico;
} Node;

/* ----------------------------------------------------------------------------------- */

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext);
Node* create_node(valorLexico valor_lexico);
void free_lexical_value(valorLexico valor_lexico);
void free_node(Node* node);
void add_children(Node *parent, Node *child);

static void _print_tree (FILE *foutput, Node *tree, int profundidade);
void print_tree(Node *tree);

static void _print_node (FILE *foutput, Node *tree, int profundidade);
void print_node(Node *tree);

static void _asd_print_graphviz (FILE *foutput, Node *tree);
void asd_print_graphviz(Node *tree);


#endif //_ARVORE_H_