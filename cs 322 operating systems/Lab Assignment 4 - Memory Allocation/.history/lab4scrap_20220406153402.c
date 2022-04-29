#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define while_bl           \
    bl *ttp = &PHY_MEM[0]; \
    while (ttp)

int fit_bool, pm_size, amt = 0;

struct block
{
    int *id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;
// create a dynamic array and still have nexts jump around the array

typedef struct block bl;

int getSpace(bl* gs) {

}



int main() {

PHY_MEM = (bl*)malloc(3*sizeof(bl))




}