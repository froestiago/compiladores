#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "table.h"
#include "ast.h"
#include "utils.h"
#include "table.h"
#include "code.h"

extern Code *code;

Instruction* add_custom_instruction(char *oper, int parameter_1, int parameter_2, int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, oper);
    sprintf(instruction->parameter_1, "r%d", parameter_1);
    sprintf(instruction->parameter_2, "r%d", parameter_2);
    sprintf(instruction->result, "r%d", result);
    printf("%s\t%s, %s => %s\n", instruction->oper, instruction->parameter_1, instruction->parameter_2, instruction->result);
    return instruction;
}

Instruction* add_loadAI(int parameter_1, char *disp_base,int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, "loadAI");
    sprintf(instruction->parameter_1, "r%d", parameter_1);
    strcpy(instruction->parameter_2, disp_base);
    sprintf(instruction->result, "%d", result);
    printf("%s\t%s, %s => %s\n", instruction->oper, instruction->parameter_2, instruction->result, instruction->parameter_1);
    return instruction;
}

Instruction* add_storeAI (int parameter_1, char *disp_base, int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, "storeAI");
    sprintf(instruction->parameter_1, "r%d", parameter_1);
    strcpy(instruction->parameter_2, disp_base);
    sprintf(instruction->result, "%d", result);
    printf("%s\t%s => %s, %s\n", instruction->oper, instruction->parameter_1, instruction->parameter_2, instruction->result);
    return instruction;
}

Instruction* add_loadI (char *parameter_1, int parameter_2)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->oper, "loadI");
    strcpy(instruction->parameter_1, parameter_1);
    sprintf(instruction->parameter_2, "r%d", parameter_2);
    strcpy(instruction->result, "");
    printf("%s\t%s => %s\n", instruction->oper, instruction->parameter_1, instruction->parameter_2);
    return instruction;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 

void printCodeList() {
    Code *current = code;

    while (current != NULL) {
        printf("%s \t %s \t %s \t %s \n", current->instruction->oper,
                                   current->instruction->parameter_1,
                                   current->instruction->parameter_2,
                                   current->instruction->result);
        
        current = current->next_instruction;
    }
}



void printListFromNode(Code *startNode) {
    Code *current = startNode;

    while (current != NULL) {
        printf("%s \t %s \t %s \t %s \n", current->instruction->oper,
                                   current->instruction->parameter_1,
                                   current->instruction->parameter_2,
                                   current->instruction->result);
        current = current->next_instruction;
    }
}

// Instruction *addInstruction(Instruction *newInstruction) {
//     Code *newCodeNode = (Code *)malloc(sizeof(Code));
//     if (newCodeNode == NULL) {
//         fprintf(stderr, "Memory allocation failed.\n");
//         exit(EXIT_FAILURE);
//     }

//     newCodeNode->instruction = newInstruction;
//     newCodeNode->next_instruction = NULL;

//     if (code == NULL) {
//         code = newCodeNode;
//     } else {
//         Code *current = code;
//         while (current->next_instruction != NULL) {
//             current = current->next_instruction;
//         }
//         current->next_instruction = newCodeNode;
//     }

//     return newInstruction; // Return the added instruction
// }

Code *addInstruction(Instruction *newInstruction) {
    Code *newCodeNode = (Code *)malloc(sizeof(Code));
    if (newCodeNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newCodeNode->instruction = newInstruction;
    newCodeNode->next_instruction = NULL;

    if (code == NULL) {
        code = newCodeNode;
    } else {
        Code *current = code;
        while (current->next_instruction != NULL) {
            current = current->next_instruction;
        }
        current->next_instruction = newCodeNode;
    }

    return newCodeNode;
}