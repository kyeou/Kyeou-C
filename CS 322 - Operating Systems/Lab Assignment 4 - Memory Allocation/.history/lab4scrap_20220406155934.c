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

int fit_bool, pm_size = 50, amt = 0;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;
// create a dynamic array and still have nexts jump around the array

typedef struct block bl;

int getSpace(bl *gs)
{
    
    // if gs->next = 0, that means no next, this if should be true if gs has no next
   // printf("GS ID IN getSPACE FUNCTION ------------> %d\n", gs->id);
    if (gs->next == NULL)
    {
        //printf("GET SPACE FUNCTION RETURN 1 -- (%d)\n",pm_size);
        return (pm_size - gs->end_loc);
    }
    else
    {
         //printf("GET SPACE FUNCTION RETURN 2 -- (ID%d.start - %d.end)\n", gs->next->id, gs->id);
        return gs->next->start_loc - gs->end_loc;
    } // end else
} // end func



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
PHY_MEM[2].next = NULL;


while_bl(q) {
    printf("%d\n", getSpace(q));
    q = q->next;
}

bl* temp = PHY_MEM[0].next;
printf("TEMP ID--%d S--%d E--%d\n", temp->id, temp->start_loc, temp->end_loc);

PHY_MEM[0]

}