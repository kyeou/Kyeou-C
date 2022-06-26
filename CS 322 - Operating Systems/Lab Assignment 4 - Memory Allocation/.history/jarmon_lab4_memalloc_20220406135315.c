#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl(var)       \
    bl* var = (bl*)malloc(sizeof(bl))\
    ttp = &PHY_MEM[0]; \
    while (ttp != NULL)

int pm_size; bool fit_bool;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL; 

typedef struct block bl;


//these functions take a new block and its size, and retuns the block it can fit a
bl* first_fit(bl* btf, int size) {

}  

bl* best_fit(bl* btf, int size) {

}  
