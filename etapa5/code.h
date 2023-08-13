#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

typedef struct Instruction
{
    char parameter_1[16];
    char parameter_2[16];
    char result[16];        //padronizar que todo o resultado de operação fique nesse campo
    char oper[16];          //nao sei pq nao aceita o nome operand
} Instruction;

typedef struct Code
{
    Instruction *instruction;
    struct Code *next_instruction;
} Code;

Instruction* add_custom_instruction(char *oper, int parameter_1, int parameter_2, int result);
Instruction* add_loadAI(int parameter_1, char *parameter_2, int result);

