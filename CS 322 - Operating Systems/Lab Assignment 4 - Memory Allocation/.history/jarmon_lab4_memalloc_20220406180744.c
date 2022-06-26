#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl(var)                   \
    bl *var = (bl *)malloc(sizeof(bl)); \
    var = &PHY_MEM[0];                  \
    while (var != NULL)

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define bl_alloc (bl *)malloc(sizeof(bl))

int pm_size, amt = 0;
bool fit_bool;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;

typedef struct block bl;

// these functions take a new block and its size, and retuns the block it can fit after
bl *first_fit(bl *btf, int size)
{
}

bl *best_fit(bl *btf, int size)
{
    bl *ret = bl_alloc;
    ret->id = -1;
    int ts = INT_MAX;

    while_bl(qw)
    {
        printf("STILL IN BEST FIT WHILE\n");
       if (qw->next == NULL) {
           ts = (pm_size - qw->end_loc >= size && pm_size - qw->end_loc <= ts) ? pm_size - qw->end_loc : ts;
           ret = (pm_size - qw->end_loc >= size && pm_size - qw->end_loc <= ts) ? qw : ret;
           break;
       } else {
           ts = (qw->next->start_loc - qw->end_loc >= size && qw->next->start_loc - qw->end_loc <= ts) ? pm_size - qw->end_loc : ts;
           ret = (qw->next->start_loc - qw->end_loc >= size && qw->next->start_loc - qw->end_loc <= ts) ? qw : ret;
           qw = qw->next;
       }
    } // end while
    printf("RET ID -->> %d\n", ret->id);
    return ret;
} // end func

bl *fit(int a, bl *btf, int size)
{
    printf("FIT CALLED\n");
    return (a == 1) ? best_fit(btf, size) : first_fit(btf, size);
}

void prt()
{
    printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    while_bl(e)
    {
       printf("%d\t%d\t%d\n", e->id, e->start_loc, e->end_loc);
       e=e->next;
    } // while ends
} // prt ends

void entParms()
{
    PHY_MEM = (bl *)malloc(sizeof(bl));
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void alloc()
{
    // printf("FUCKIN PM_SIZE -------------> %d\n", pm_size);
    int s;
    amt++;
    // printf("NEW AMT -->> %d, most recent index %d\n", amt, amt - 1);
    PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
    int_input("Enter block id: ", (PHY_MEM[amt - 1]).id);
    int_input("Enter block size: ", s);
    if (amt == 1)
    {
        PHY_MEM[amt - 1].start_loc = 0;
        PHY_MEM[amt - 1].end_loc = s + PHY_MEM[amt - 1].start_loc;
        PHY_MEM[amt - 1].next = NULL;
        pm_size -= s;
    }
    else
    {
        bl *temp = fit(fit_bool, &(PHY_MEM[amt - 1]), s);
        if (temp->id != -1)
        {
            PHY_MEM[amt - 1].next = temp->next;
            temp->next = &(PHY_MEM[amt - 1]);
            PHY_MEM[amt - 1].start_loc = temp->end_loc;
            PHY_MEM[amt - 1].end_loc = PHY_MEM[amt - 1].start_loc + s;
            printf("IDs -->> ");
            while_bl(qe) {
                printf(" %d ", qe->id);
            } prin
        }
        else
        {
            printf("Block does not fit\n");
        }
    } // end else

    prt();
}

void delloc()
{
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
