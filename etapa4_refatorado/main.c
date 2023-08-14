#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "table.h"

extern int yyparse(void);
extern int yylex_destroy(void);
void *arvore = NULL;
void exporta (void *arvore);

Symbol *tabela_global = NULL;
Symbol *tabela_atual = NULL;
List *list = NULL;
Tipo tipo_atual = -1;

int main (int argc, char **argv)
{
  int ret = yyparse(); 
  exporta (arvore);
  yylex_destroy();
  return ret;
}

