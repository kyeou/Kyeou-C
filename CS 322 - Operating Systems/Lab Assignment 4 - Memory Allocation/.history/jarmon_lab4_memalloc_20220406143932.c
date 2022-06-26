#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl(var)                  \
    bl *var = (bl *)malloc(sizeof(bl)); \
        var = &PHY_MEM[0];             \
    while (var != NULL)

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define bl_alloc (bl*)malloc(sizeof(bl))

int pm_size, amt = 0;
bool fit_bool;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;

typedef struct block bl; 


int getSpace(bl *gs)
{
    
    // if gs->next = 0, that means no next, this if should be true if gs has no next
    if (gs->next == NULL)
    {
        return (pm_size - gs->end_loc);
    }
    else
    {
        return gs->next->start_loc - gs->end_loc;
    } // end else
} // end func




// these functions take a new block and its size, and retuns the block it can fit after
bl *first_fit(bl *btf, int size)
{
     bl *ret = bl_alloc;
    ret->id = -1;

    int ts = INT_MAX;
    while_bl(q)
    {
        if (getSpace(q) > size && getSpace(q) < ts)
        {
            ret = q;
            return ret;
        } // end if
        q = q->next;
    }     // end while
}

bl *best_fit(bl *btf, int size)
{
    int ts = INT_MAX;
    bl* ret = bl_alloc;
    ret->id = -1;

while_bl(w) {
    if (getSpace(w) > size && getSpace(w) < ts) {
        printf("BEST FIT IF TRUE FOR ID -> %d\n", w->id);
        ts = getSpace(w);
        ret = w;
        w = w->next;
    }
}//end while

return ret;


}//end func

bl *fit(int a, bl *btf, int size)
{
    return (a == 1) ? best_fit(btf, size) : first_fit(btf, size);
}


void prt() {
     printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    while_bl(e) {
          printf("%d\t%d\t%d\n", e->id, e->start_loc, e->end_loc);
          e = e->next;
    }//while ends
}//prt ends


void entParms()
{
    PHY_MEM = (bl *)malloc(sizeof(bl));
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void alloc()
{
    int s;
    amt++;
    PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
    int_input("Enter block id: ", (PHY_MEM[amt - 1]).id);
    int_input("Enter block size: ", s);
    if (amt == 1)
    {
        PHY_MEM[amt - 1].start_loc = 0;
        PHY_MEM[amt - 1].end_loc = s + PHY_MEM[amt - 1].start_loc;
        PHY_MEM[amt - 1].next = 0;
    }
    else
    {
        if (fit(fit_bool, &(PHY_MEM[amt - 1]), s)->id != -1) {
        bl *temp = fit(fit_bool, &(PHY_MEM[amt - 1]), s);
        PHY_MEM[amt - 1].next = temp->next;temp->next = &(PHY_MEM[amt - 1]);
        printf("SHOULD BE EQUAL %zu %zu\n", PHY_MEM[amt - 1].next == NULL, temp->next == NULL);
         PHY_MEM[amt - 1].start_loc = temp->end_loc;
         PHY_MEM[amt -1].end_loc = PHY_MEM[amt -1].start_loc + s;
        
        
        } else {
            printf("Block does not fit\n");
        }
    } // end else

    prt();
}

void delloc() {

}

void defrag()
{
}

void quit()
{
}

int main()
{

    int c;
    while (c != 5)
    {
        printf("\nMemory Allocation\n");
        printf("-----------------\n");
        printf("1) Enter parameters\n");
        printf("2) Allocate memory for block\n");
        printf("3) Deallocate memory for block\n");
        printf("4) Defragment memory\n");
        printf("5) Quit program\n\n");

        int_input("Enter selection: ", c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            alloc();
            break;
        case 3:
            delloc();
            break;
        case 4:
            defrag();
            break;
        case 5:
            quit();
            break;
        default:
            printf("Not a selection.");
            break;
        }
    }
}

/*
1
1024
1
2
0
128
2
1
320
2
2
224

2
3
288
3
2

2
4
128
3
1
2
2
224
2
5
64
4






*/
