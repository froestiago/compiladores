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
    
    snprintf(instruction->parameter_1, sizeof(instruction->parameter_1), "r%d", parameter_1);
    snprintf(instruction->parameter_2, sizeof(instruction->parameter_2), "r%d", parameter_2);
    snprintf(instruction->result, sizeof(instruction->result), "r%d", result);
    snprintf(instruction->oper, sizeof(instruction->oper), "%s", oper);
    
    return instruction;
}

Instruction* add_loadAI(int parameter_1, char *disp_base,int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));

    snprintf(instruction->parameter_1, sizeof(instruction->parameter_1), "r%d", parameter_1);
    snprintf(instruction->parameter_2, sizeof(instruction->parameter_2), "%s", disp_base);
    snprintf(instruction->result, sizeof(instruction->result), "%d", result);
    snprintf(instruction->oper, sizeof(instruction->oper), "loadAI");
    
    
    return instruction;
}

Instruction* add_storeAI(int parameter_1, char *disp_base, int result)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));

    snprintf(instruction->parameter_1, sizeof(instruction->parameter_1), "r%d", parameter_1);
    snprintf(instruction->parameter_2, sizeof(instruction->parameter_2), "%s", disp_base);
    snprintf(instruction->result, sizeof(instruction->result), "%d", result);
    snprintf(instruction->oper, sizeof(instruction->oper), "storeAI");
    
    return instruction;
}

Instruction* add_loadI(char *parameter_1, int parameter_2)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
   
    snprintf(instruction->parameter_1, sizeof(instruction->parameter_1), "%s", parameter_1);
    snprintf(instruction->parameter_2, sizeof(instruction->parameter_2), "r%d", parameter_2);
    strcpy(instruction->result, "");
    snprintf(instruction->oper, sizeof(instruction->oper), "loadI");


    return instruction;
}

// set as type:Instruction for readability
Instruction* add_cbr(int temp, int label_1, int label_2)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    snprintf(instruction->oper, sizeof(instruction->oper), "cbr");
    snprintf(instruction->result, sizeof(instruction->result), "r%d", temp);
    snprintf(instruction->parameter_1, sizeof(instruction->parameter_1), "L%d", label_1);
    snprintf(instruction->parameter_2, sizeof(instruction->parameter_2), "L%d", label_2);
    
    Code *newCodeNode = (Code *)malloc(sizeof(Code));
    if (newCodeNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newCodeNode->instruction = instruction;
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

}

// set as type:Instruction for readability
Instruction* add_jumpI(int label)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->parameter_1, "");
    strcpy(instruction->parameter_2, "");
    snprintf(instruction->oper, sizeof(instruction->oper), "jumpI");
    snprintf(instruction->result, sizeof(instruction->result), "L%d", label);

    Code *newCodeNode = (Code *)malloc(sizeof(Code));
    if (newCodeNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newCodeNode->instruction = instruction;
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
}

// set as type:Instruction for readability
Instruction* add_label(int label)
{
    Instruction* instruction = (Instruction*)malloc(sizeof(Instruction));
    strcpy(instruction->parameter_1, "");
    strcpy(instruction->parameter_2, "");
    snprintf(instruction->result, sizeof(instruction->result), "L%d:", label);
    snprintf(instruction->oper, sizeof(instruction->oper), "label");

    Code *newCodeNode = (Code *)malloc(sizeof(Code));
    if (newCodeNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newCodeNode->instruction = instruction;
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

}

void printCodeList() {
    // code is the global variabel
    Code *current = code;

    while (current != NULL) {
        char *oper = current->instruction->oper;
        if (strcmp(oper, "loadAI") == 0){
            printf("%s %s, %s => %s\n", oper, current->instruction->parameter_2, current->instruction->result, current->instruction->parameter_1);
        } else if (strcmp(oper, "storeAI") == 0){
            printf("%s %s => %s, %s\n", oper, current->instruction->parameter_1, current->instruction->parameter_2, current->instruction->result);
        } else if (strcmp(oper, "loadI") == 0){
            printf("%s %s => %s\n", current->instruction->oper, current->instruction->parameter_1, current->instruction->parameter_2);
        } else if (strcmp(oper, "div") == 0 ||
                  strcmp(oper, "mult") == 0 ||
                  strcmp(oper, "sub") == 0 ||
                  strcmp(oper, "add") == 0 ||
                  strcmp(oper, "cmp_GE") == 0 ||
                  strcmp(oper, "cmp_LE") == 0 ||
                  strcmp(oper, "cmp_GT") == 0 ||
                  strcmp(oper, "cmp_LT") == 0 ||
                  strcmp(oper, "cmp_NE") == 0 ||
                  strcmp(oper, "cmp_EQ") == 0 ||
                  strcmp(oper, "and") == 0 ||
                  strcmp(oper, "or") == 0 )
            {
            printf("%s %s, %s => %s\n", oper, current->instruction->parameter_1, current->instruction->parameter_2, current->instruction->result);
        } else if (strcmp(oper, "label") == 0){
            printf("%s\n", current->instruction->result);
        } else if (strcmp(oper, "cbr") == 0){
            printf("%s %s => %s, %s\n", oper, current->instruction->result, current->instruction->parameter_1, current->instruction->parameter_2);
        } else if (strcmp(oper, "jumpI") == 0){
            printf("%s => %s\n", oper, current->instruction->result);
        }
        current = current->next_instruction;
    }
}

void printListFromNode(Code *startNode) {;
    Code *current = startNode;

    while (current != NULL) {
        printf("%s \t %s \t %s \t %s \n",
                current->instruction->oper,
                current->instruction->parameter_1,
                current->instruction->parameter_2,
                current->instruction->result);
                current = current->next_instruction;
    }
}

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