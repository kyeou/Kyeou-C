#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define while_bl           \
    bl *ttp = &PHY_MEM[0]; \
    while (ttp != NULL)

int fit_bool, pm_size, amt = 0;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} *PHY_MEM = NULL;
// create a dynamic array and still have nexts jump around the array

typedef struct block bl;





void prt()
{
    printf("\nID\tStart\tEnd\n");
    printf("-------------------\n");
    while_bl
    {
        printf("%d\t%d\t%d\n", ttp->id, ttp->start_loc, ttp->end_loc);
        ttp = ttp->next;
    }
}

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
    PHY_MEM = (bl *)realloc(PHY_MEM, amt);
    int_input("Enter block id: ", PHY_MEM[amt - 1].id);
    int_input("Enter block size: ", s);
    // SIZES NEED TO BE SET
    if (amt == 1)
    {
        PHY_MEM[amt - 1].start_loc = 0;
        PHY_MEM[amt - 1].end_loc = s - PHY_MEM[amt - 1].start_loc;
    }
    else
    {
        fit(&PHY_MEM[amt - 1], s);
    }
    prt();
}

void delloc()
{
}

void defrag()
{
    ;
}

void quit()
{
    ;
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
