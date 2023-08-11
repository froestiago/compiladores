typedef struct Instruction
{
    char parameter_1[16];
    char parameter_2[16];
    char parameter_3[16];
    char oper[16];      //nao sei pq nao aceita o nome operand
} Instruction;

typedef struct Code
{
    Instruction *instruction;
    Code *next_instruction;
} Code;


