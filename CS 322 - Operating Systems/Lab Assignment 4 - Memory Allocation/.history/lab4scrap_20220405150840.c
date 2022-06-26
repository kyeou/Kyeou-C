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

int main() {
    PHY_MEM = (bl*)malloc(2*sizeof(bl));

PHY_MEM[0].id = (int*)malloc(sizeof(int));
*(PHY_MEM[0].id) = 0;
PHY_MEM[1].id = (int*)malloc(sizeof(int));
*(PHY_MEM[1].id) = 1;
PHY_MEM[0].next = &(PHY_MEM[1]);
PHY_MEM[1].next = 0;
    while_bl {
       
        printf("%d\n", *(ttp->id));
        //printf("SET CHECK\n");
        
        printf("N CHECK -- %d\n", (ttp));
        ttp = ttp->next;
    }
printf("N CHECK -- %d\n", (ttp));
printf("BREAK CHECK\n");



}