#pragma once
#ifndef _ARVORE_H_
#define _ARVORE_H_

#include "code.h"

typedef enum tipo {
    INT,	// 0
	FLOAT,	// 1
	BOOL,	// 2
	ND		// 3
} Tipo;

typedef enum Natureza {
	TIPO,		// 0
	CONTROLE,	// 1
	LITERAL,	// 2
	VARIAVEL,	// 3
	ATRIBUICAO,	// 4
	EXPRESSAO,	// 5
	SINTAXE,	// 6
	DEF_FUNCAO,	// 7
} Natureza;

typedef struct valorLexico {
    int linha;
    Tipo tipo;
	Natureza natureza;
    char *valor;

	Code code;
	int temp;
	int disp;
    char *base;
} valorLexico;

typedef struct Node {
  	int num_children;
  	struct Node** children;
  	valorLexico valor_lexico;
} Node;


/* ----------------------------------------------------------------------------------- */

valorLexico get_yylval(int num_line, Tipo tipo, Natureza natureza, char* yytext);
Node* create_node(valorLexico valor_lexico);
void free_lexical_value(valorLexico valor_lexico);
void free_node(Node* node);
void add_children(Node *parent, Node *child);

#endif //_ARVORE_H_

