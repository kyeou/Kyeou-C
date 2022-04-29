#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl(var)       \
    bl* var = (bl*)malloc(size)\
    ttp = &PHY_MEM[0]; \
    while (ttp != NULL)

int pm_size; bool fit_bool;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL; 

typedef struct block bl;