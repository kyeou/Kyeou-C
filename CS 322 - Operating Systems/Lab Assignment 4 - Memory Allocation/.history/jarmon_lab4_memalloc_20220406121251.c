#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define while_bl2                           \
    (var)                                   \
        bl *var = (bl *)malloc(sizeof(bl)); \
    var = &PHY_MEM[0];                      \
    while (var)

#define while_bl       \
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
    printf("GET SPACE CALL FOR ID -> %d\n", gs->id);
    // if gs->next = 0, that means no next, this if should be true if gs has no next
    if (!(gs->next))
    {
        // printf("GET SPACE FUNCTION RETURN -- (%d - %d)\n", pm_size, gs->end_loc);
        printf("SPACE AFTER --> block #%d? (%d - %d) = %d\n", gs->id, pm_size, gs->end_loc, pm_size - gs->end_loc);
        return (pm_size - gs->end_loc);
    }
    else
    {
        printf("GET SPACE FUNCTION RETURN -- (Start of %d - End of %d)\n", (*gs->next).id, gs->id);
        return gs->next->start_loc - gs->end_loc;
    } // end else
} // end func

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
/*
bl *best_fitDEAD(int size)
{
    // printf("\nBEST FIT CALLED\n");
    bl *ret = NULL;
    ret = (bl *)malloc(sizeof(bl));
    ret->id = -1;

    int ts = INT_MAX;
    while_bl
    {
        printf("CURRENT ID -- %d\n", ttp->id);
        int testSpace = getSpace(ttp);
        if (testSpace > size && testSpace < ts)
        {
            printf("BEST Fit --> IF TRUE\n");
            ts = testSpace;
            printf("CURRENT RET -- %d AND SPACE %d\n", ttp->id, ts);
            ret = ttp;
            printf("TTP id #%d HAS NEXT, 1=NO NEXT 0=KEEPS ON -> %d\n", ttp->id, !(ttp->next));
            ttp = ttp->next;
        }
        else
        {
            printf("TTP id #%d HAS NEXT, 1=NO NEXT-> %d\n", ttp->id, !(ttp->next));
            ttp = ttp->next;
        } // end if-else
    }     // end while

    // printf("RETURN -- %d\n", ret->id);
    return ret;

} // end best fit
*/

bl* best_fit(int size) {
    
    int ts = INT_MAX; 
    bl* ret = NULL; 
    bl* ret2 = (bl*)malloc(sizeof(bl));
    ret2->id = -1;
    for (int a = 0; a < amt; a++) {

        if (&PHY_MEM[a] == NULL) {
            a++;
        }

        //if at end of list and pm_size - last_

        if (PHY_MEM[a].end_loc - PHY_MEM[a].next->start_loc < ts && PHY_MEM[a].end_loc - PHY_MEM[a].next->start_loc > size) {
            ts = PHY_MEM[a].end_loc - PHY_MEM[a].next->start_loc;
            ret = &PHY_MEM[a];
        }//end if
    }//end for

    return ret;
}




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
            printf("TEMP END LOC --> id#%d %d\n", temp->id, temp->end_loc);
            item->end_loc = size + item->start_loc;
            printf("FIT CHECK -->> %d SHOULD MATCH->(%d %d), TEMP NEXT NEXT (1)? (%d)\n", temp->id, item->id, temp->next->id, !(temp->next->next));
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
     
  
    }//end while

       
      printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    for (int a = 0; a < amt; a++)
    {

        printf("%d\t%d\t%d\n", PHY_MEM[a].id, PHY_MEM[a].start_loc, PHY_MEM[a].end_loc);
        // printf("%d-", (ttp->next == NULL));
        //ttp = ttp->next;
        // printf("BREAK CHECK");
    }   // printf("BREAK CHECK");
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
    //h is block beofre teh one that is getting dealloced
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
    del->next = NULL;


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
