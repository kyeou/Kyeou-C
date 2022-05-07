// written by christian jarmon

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define while_bl     \
    ttp = getHead(); \
    while (ttp != 0)

// make beginning of traversal a head

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define if_then(x, y) \
    if ((x))          \
    {                 \
        y;            \
    }
#define alloc(size, type) (type*)malloc(size*sizeof(type))

int pm_size, amt = 0;
bool fit_bool;

struct block
{
    int id, start_loc, end_loc, size;
    struct block *next;
} *PHY_MEM = 0;

typedef struct block bl;

// bl *head;
bl *ttp;

bl *getHead()
{
    bl *q = alloc(1,bl);
    int a = INT_MAX;
    for (int i = 0; i < amt; i++)
    {
        
        if (PHY_MEM[i].start_loc < a)
        {
            a = PHY_MEM[i].start_loc;
            q = &PHY_MEM[i];
        }
        // printf("GET HEAD CALL %d %d %d\n", a, q->id, q->end_loc);
    }
    return q;
    // PHY_MEM[i]
}

bool checkID(int i)
{
    while_bl
    {
        if_then (i == ttp->id, return true)
        ttp = ttp->next;
    }
    return false;
}
// these functions take a new block and its size, and retuns the block it can fit after
bl *first_fit(bl *btf, int size)
{
    bl *ret = alloc(1, bl);
     //ret->id = INT_MAX;
    int ts = INT_MAX;

    /*printf("IDs (Last number should be 1)-->> ");
    while_bl
    {
        printf(" %d-", ttp->id);
        printf(" %zu ", ttp->next == 0);
        ttp = ttp->next;
    }
    printf("\n");
*/
    bool q = false,  w = false;
    while_bl
    {

        if (q || w)
        {
            return ret;
        }
        if (ttp->next == 0)
        {
            q = (pm_size - ttp->end_loc >= size && pm_size - ttp->end_loc <= ts);
            ts = (q) ? pm_size - ttp->end_loc : ts;
            ret = (q) ? ttp : ret;
            break;
        }
        else
        {
            // printf("WAS QW->NEXT NULL %zu\n", ttp->next == 0);
            w = (ttp->next->start_loc - ttp->end_loc >= size && ttp->next->start_loc - ttp->end_loc <= ts);
            ts = (w) ? ttp->next->start_loc - ttp->end_loc : ts;
            ret = (w) ? ttp : ret;
            ttp = ttp->next;
        }
    } // end while
}

bl *best_fit(bl *btf, int size)
{
    bl *ret = ((bl *)malloc(sizeof(bl)));
    // printf("HEAD CHECK BF 1 (Should be 0) --> %d\n", head->id);
    // ret->id = -1;
    // printf("HEAD CHECK BF 2 (Should be 0) --> %d\n", head->id);
    int ts = INT_MAX;
    // head = &(PHY_MEM[0]);
    /*
        printf("BEST FIT-->> IDs (Last number should be 1)-->> ");
        while_bl
        {
            printf(" %d-", ttp->id);
            printf("%zu ", ttp->next == 0);
            ttp = ttp->next;
        }
        printf("\n");
    */
    // printf("HEAD CHECK BF (Should be 0) --> %d\n", head->id);
   // printf("HC JESUS CHRIST --> %d %d %d\n", getHead()->id, getHead()->start_loc, getHead()->end_loc);
    while_bl
    {
        //printf("STILL IN BEST FIT WHILE --> %d %d %d\n", ttp->id, ttp->start_loc, ttp->end_loc);
        // printf("HEAD CHECK (Should be 0) --> %d\n", head->id);
        //  printf("IS QW->NEXT NULL (1=Yes, 0=No) %zu\n", ttp->next == 0);
        if (ttp->next == 0)
        {
            // printf("TAIL CHECK -- %d\n", pm_size - ttp->end_loc);
            bool e = (pm_size - ttp->end_loc >= size && pm_size - ttp->end_loc <= ts);
            ts = (e) ? pm_size : ts;
            ret = (e) ? ttp : ret;
            ttp = ttp->next;
            // break;
        }
        else
        {
            bool r = (ttp->next->start_loc - ttp->end_loc >= size && ttp->next->start_loc - ttp->end_loc <= ts);
            ts = (r) ? ttp->next->start_loc - ttp->end_loc : ts;
            ret = (r) ? ttp : ret;
            ttp = ttp->next;
        }
    } // end while
    // printf("RET ID -->> %d\n", ret->id);
    return ret;
} // end func

void prt()
{
    printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    while_bl
    {
        printf("%d\t%d\t%d\n", ttp->id, ttp->start_loc, ttp->end_loc);
        ttp = ttp->next;
    } // while ends
} // prt ends

void entParms()
{
    PHY_MEM = alloc(1, bl);
    bl *ttp = alloc(1, bl);
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void allocate()
{

    amt++;
    PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
    int_input("Enter block id: ", (PHY_MEM[amt - 1]).id);
    int_input("Enter block size: ", (PHY_MEM[amt - 1]).size);
    if (amt == 1)
    {
      //  printf(" SIZE CHECK-->> %d\n", (PHY_MEM[amt - 1]).size);
        // head = &(PHY_MEM[amt - 1]);
        PHY_MEM[amt - 1].start_loc = 0;
        PHY_MEM[amt - 1].end_loc = PHY_MEM[amt - 1].size + PHY_MEM[amt - 1].start_loc;
      //  printf("FIRST BLOCK SIZE -->> %d == %d\n", (PHY_MEM[amt - 1]).size + PHY_MEM[amt - 1].start_loc, PHY_MEM[amt - 1].end_loc);
        PHY_MEM[amt - 1].next = 0;
        // head = &(PHY_MEM[amt - 1]);
        // pm_size -= s;

        /*
        printf("FIRST BLOCK -->> IDs -->> ");
        while_bl
        {
            printf(" %d-", ttp->id);
            printf("%zu ", ttp->next == 0);
            ttp = ttp->next;
        }
        printf("\n");
        */
    }
    else
    {
        // printf("HEAD CHECK (Should be 0) --> %d\n", head->id);
        bl *temp = (fit_bool == 1) ? best_fit(&(PHY_MEM[amt - 1]), (PHY_MEM[amt - 1]).size) : first_fit(&(PHY_MEM[amt - 1]), (PHY_MEM[amt - 1]).size);

        if (checkID(temp->id))
        {
            // printf("GO CHECK\n");

            PHY_MEM[amt - 1].next = temp->next;

            // printf("BREAK CHECK\n");
            temp->next = &(PHY_MEM[amt - 1]);
            PHY_MEM[amt - 1].start_loc = temp->end_loc;
            PHY_MEM[amt - 1].end_loc = PHY_MEM[amt - 1].start_loc + (PHY_MEM[amt - 1]).size;
            /*
                        printf("IDs -->> ");
                        while_bl
                        {
                            printf(" %d-", ttp->id);
                            printf(" %zu ", ttp->next == 0);
                            ttp = ttp->next;
                        }
                        printf("\n");
                        */
        }
        else if_then (!(checkID(temp->id)), printf("Block does not fit\n"))
    } // end else

    prt();
}

void delloc()
{
    int i;
    bl *d = alloc(1, bl), *h = alloc(1, bl);

    int_input("Enter block id: ", i);

    while_bl
    {
        if_then (ttp->id == i, d = ttp; break)
        ttp = ttp->next;
    }

    while_bl
    {
        if_then (ttp->next == d, h = ttp; break)
        ttp = ttp->next;
    }

    /*
        if (d == getHead())
        {
            head = d->next;
        }
    */
    h->next = d->next;
    d->start_loc = -1;
    d->end_loc = -1;
    d->next = NULL;

    prt();

} // end delloc

void defrag()
{
    // Given a process, if ttp->next->start_loc != ttp->end_loc
    // then, ttp->next->start_loc = ttp->end_loc
    while_bl
    {
        // printf("CURR ID --> %d\n", ttp->id);
        if_then (!(ttp->next), break)
        int nextSize = ttp->next->size;

        if (ttp->next->start_loc != ttp->end_loc)
        {
            ttp->next->start_loc = ttp->end_loc;
            ttp->next->end_loc = ttp->next->size + ttp->next->start_loc;
        }
        else
        {
            ttp = ttp->next;
        }
    }

    prt();
}

void quit()
{
    for (int i = 0; i < amt; i++)
    {
        PHY_MEM[i].next = NULL;
        free(PHY_MEM[i].next);
    }
    PHY_MEM = NULL;
    free(PHY_MEM);
}

int main()
{

    int c = -1;
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
            allocate();
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
5
*/
