#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define while_bl()       \
    ttp = &PHY_MEM[0]; \
    while (ttp)

int fit_bool, pm_size, amt = 0;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;
// create a dynamic array and still have nexts jump around the array

typedef struct block bl;
bl *ttp;

// returns the space between 2 blocks (linked by a next)
// this function assumes the blocks exist
// parameter is a block
// if there is no next, should return pm_size - parameter.end_loc
int getSpace(bl *gs)
{
    if (!(gs->next))
    {
        // printf("GET SPACE FUNCTION RETURN -- (%d - %d)\n", pm_size, gs->end_loc);
        return pm_size - gs->end_loc;
    }
    // printf("GET SPACE FUNCTION RETURN -- (%d - %d)\n", gs->next->start_loc,  gs->end_loc);
    return gs->next->start_loc - gs->end_loc;
}

bl *first_fit(int size)
{
    printf("\nFIRST FIT CALLED\n");

    bl *ret = (bl *)malloc(sizeof(bl));
    ret->id = -1;

    int ts = INT_MAX;
    while_bl
    {
        if (getSpace(ttp) > size && getSpace(ttp) < ts)
        {
            ret = ttp;
            return ret;
        } // end if
    }     // end while
}

// need to if the block can fit anyway
//   this can be known, if we are at the end of the list, and that space is still too small, it cant fit
//  THIS FUNCTION HAS TO SET THE SIZES AS WELL
bl *best_fit(int size)
{
    // printf("\nBEST FIT CALLED\n");

    bl *ret = (bl *)malloc(sizeof(bl));
    ret->id = -1;

    int ts = INT_MAX;
    while_bl
    {
        // printf("CURRENT ID -- %d\n", ttp->id);
        if (getSpace(ttp) > size && getSpace(ttp) < ts)
        {
            // printf("IF TRUE\n");
            ret = ttp;
            ts = getSpace(ttp);
            // printf("CURRENT RET __ %d\n", ret->id);
            ttp = ttp->next;
        }
        else
        {
            ttp = ttp->next;
        } // end if-else
    }     // end while

    // printf("RETURN -- %d\n", ret->id);
    return ret;

} // end best fit

// this function is called by best_fit and first_fit
// item is the process/block we are trying to fit
void fit(bl *item, int size)
{

    if (fit_bool)
    {

        bl *temp = best_fit(size);
        if (temp->id != -1)
        {
            // temp is the process that already exists whos next will be the new one, the new.next has to be set to temp.next
            // printf("FIT CHECK -->> %d %d", temp->id, item->start_loc);
            item->next = temp->next;
            temp->next = item;
            item->start_loc = temp->end_loc;
            item->end_loc = size + item->start_loc;
            // printf("FIT CHECK -->> %d %d\n", temp->id, item->id);
        }
        else
        {
            printf("Block can't fit\n\n");
        }
    }
    else
    {
        // this is first_fit
    }

} // fit ends

void prt()
{

    printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    while_bl
    {

        printf("%d\t%d\t%d\n", ttp->id, ttp->start_loc, ttp->end_loc);
        // printf("%d-", (ttp->next == NULL));
        ttp = ttp->next;
        // printf("BREAK CHECK");
    }
}

void entParms()
{
    PHY_MEM = (bl *)malloc(sizeof(bl));
    ttp = (bl *)malloc(sizeof(bl));
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void alloc()
{

    int s;
    amt++;
    PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
    int_input("Enter block id: ", (PHY_MEM[amt - 1]).id);
    // printf("%d --> %d\n", amt-1 ,PHY_MEM[amt - 1].id);
    int_input("Enter block size: ", s);
    // SIZES NEED TO BE SET
    if (amt == 1)
    {
        PHY_MEM[amt - 1].start_loc = 0;
        PHY_MEM[amt - 1].end_loc = s + PHY_MEM[amt - 1].start_loc;
        // PHY_MEM[amt - 1].id = amt-1;
        PHY_MEM[amt - 1].next = NULL;
    }
    else
    {
        // PHY_MEM[amt - 1].id = amt-1;
        fit(&(PHY_MEM[amt - 1]), s);
        // printf("END OF ALLOC\n");
    }
    prt();
}

void delloc()
{
    int i;
    bl *del = (bl *)malloc(sizeof(bl));
    bl *h = (bl *)malloc(sizeof(bl));
    ttp = &PHY_MEM[0];
    int_input("Enter block id: ", i);
    while_bl
    {
        printf("WHILE 1 -- TTP ID %d\n", ttp->id);
        if (ttp->id == i)
        {
            del = ttp;
            printf("DEL ID -- %d", del->id);
            ttp = ttp->next;
            break;
        }
        else
        {
            ttp = ttp->next;

        } // end if-else

    } // end while

    while_bl
    {
        printf("WHILE 2 -- TTP ID %d\n", ttp->id);
        if (ttp->next == del)
        {
            h = ttp;
            printf("H ID -- %d", h->id);
            ttp = ttp->next;
            break;
        }
        else
        {
            ttp = ttp->next;
        } // end if-else

    } // end while

    h->next = del->next;

    prt();

} // end delloc

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
