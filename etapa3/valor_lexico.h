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

valorLexico get_yylval(int num_line, Tipo tipo, char* yytext);