#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)


#define while_bl(var)                  \
    bl *var = (bl *)malloc(sizeof(bl)); \
        var = &PHY_MEM[0];             \
    while (var != NULL)

int fit_bool, pm_size, amt = 0;

struct block
{
    int *id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;
// create a dynamic array and still have nexts jump around the array

typedef struct block bl;

int getSpace(bl* gs) {
return gs->next->
}



int main() {

PHY_MEM = (bl*)malloc(3*sizeof(bl));

PHY_MEM[0].id = 0; 
PHY_MEM[0].start_loc = 0;
PHY_MEM[0].end_loc = 10;
PHY_MEM[0].next = &(PHY_MEM[1]);

PHY_MEM[1].id = 1;
PHY_MEM[1].start_loc = 15;
PHY_MEM[1].end_loc = 25;
PHY_MEM[1].next = &(PHY_MEM[2]);


PHY_MEM[2].id = 2;
PHY_MEM[2].start_loc = 30;
PHY_MEM[2].end_loc = 40;
PHY_MEM[2].next = NULL


while_bl(q) {
    printf("%d\n", getSpace(q))
}

}