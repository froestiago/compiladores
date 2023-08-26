#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "table.h"
#include "code.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);

Symbol *tabela_global = NULL;
Symbol *tabela_atual = NULL;

List *nodo_inicial = NULL;
List *nodo_atual = NULL;

int current_temp = 1;
int current_label = 0;
int cbr_temp = 0;

int disp_rfp = 4;
int disp_rbss = 4;

AssemblySymbol *ass_table = NULL;

// List *list = NULL;

int list_index = 0;
Tipo tipo_atual = -1;

Code *code = NULL;

int main (int argc, char **argv)
{
  int ret = yyparse(); 
  // exporta (arvore);
  yylex_destroy();
  return ret;
}

