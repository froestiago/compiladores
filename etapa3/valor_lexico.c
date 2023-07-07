#include <stdio.h>
#include <stdlib.h>
#include "valor_lexico.h"

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext) {
    
    valorLexico valor_lexico;
    valor_lexico.linha = num_line;
    valor_lexico.tipo = tipo;
    valor_lexico.valor = strdup(yytext);

    return valor_lexico;
}