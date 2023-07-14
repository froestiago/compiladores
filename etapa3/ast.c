#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ast.h"

#define ARQUIVO_SAIDA "/mnt/c/Users/guibg/OneDrive/Área de Trabalho/compiladores/NOVO/compiladores/etapa3/saida.dot"
//"/Users/tiagofroes/Desktop/compiladores/etapa3/saida.dot"

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
    valor_lexico.valor = strdup(yytext);

    return valor_lexico;
}

Node* create_node(valorLexico valor_lexico) {
  Node *new_node;
  new_node = malloc(sizeof(Node));

  new_node->num_children = 0;
  new_node->children = NULL;
  new_node->valor_lexico = valor_lexico;
  
  return new_node;
}

// void add_children(Node *parent, Node *child) {
//     if(child!= NULL && parent!=NULL){
//         if(parent->children==NULL){
//             parent->children = child;
//         }
//     }
// }

void add_children(Node *tree, Node *child)
{
  if (tree != NULL && child != NULL){
    tree->num_children++;
    tree->children = realloc(tree->children, tree->num_children * sizeof(Node*));
    tree->children[tree->num_children-1] = child;
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p / %p.\n", __FUNCTION__, tree, child);
  }
}

static void _asd_print (FILE *foutput, Node *tree, int profundidade)
{
  int i;
  if (tree != NULL){
    fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade*2, "", tree->valor_lexico.valor, tree->num_children);
    for (i = 0; i < tree->num_children; i++){
      _asd_print(foutput, tree->children[i], profundidade+1);
    }
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
  }
}

void asd_print(Node *tree)
{
  FILE *foutput = stderr;
  if (tree != NULL){
    _asd_print(foutput, tree, 0);
  }else{
    printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
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

void free_lexical_value(valorLexico valor_lexico)
{
    if (!valor_lexico.valor) return;

    free(valor_lexico.valor);
    
    valor_lexico.valor = NULL;
}

void print_tree(Node* root, int level) {
    if (root == NULL)
        printf("blau blau");
        return;

    printf("%*s%s\n", level * 4, "valor_lexico.valor: \t\t", root->valor_lexico.valor);

    for (int i = 0; i < root->num_children; i++) {
        print_tree(root->children[i], level + 1);
    }
}

void print_node(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%p [label=\"", root);
    printf("%s", root->valor_lexico.valor);
    printf("\"];\n");
    printf("%p [num_child=\"", root);
    printf("%d", root->num_children);
    printf("\"];\n");


    Node *child;
    child = root->children;
    while(child!=NULL)
    {
        print_node(child);
        child = child->children;
    }
    
    return;

}


void free_node(Node* node)
{
    if (!node) return;
    
    free_lexical_value(node->valor_lexico);

    for (int i = 0; i < node->num_children; i++) {
        free_node(node->children[i]);
    }

    free(node->children);
    free(node);
}

void exporta(void *arvore)
{
    Node *nodo_arvore;
    nodo_arvore = (Node*) arvore;
    print_tree(nodo_arvore, 1);
    return;
}