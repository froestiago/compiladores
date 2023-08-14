#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table.h"
#include "ast.h"
#include "utils.h"
#include "table.h"
#include "code.h"

extern Code *complete_code;

Instruction* create_custom_instruction(char *oper, int parameter_1, int parameter_2, int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, oper);
    sprintf(instruction->parameter_1, "r%d", parameter_1);
    sprintf(instruction->parameter_2, "r%d", parameter_2);
    sprintf(instruction->result, "r%d", result);
    printf("%s\t%s, %s => %s\n", instruction->oper, instruction->parameter_1, instruction->parameter_2, instruction->result);
    return instruction;
}

Instruction* add_loadAI(int parameter_1, char *parameter_2, int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, "loadAI");
    sprintf(instruction->parameter_1, "r%d", parameter_1);
    strcpy(instruction->parameter_2, parameter_2);
    sprintf(instruction->result, "%d", result);
    printf("%s\t%s, %s => %s\n", instruction->oper, instruction->parameter_2, instruction->result, instruction->parameter_1);
    return instruction;
}

void add_to_code(Instruction *instruction){

}
