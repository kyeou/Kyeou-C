#include "stdio.h"
#include "stdlib.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define forbl while (ttp.next != NULL)

int fit_bool, pm_size;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
} ;

typedef struct block bl;

void prt() {
    printf("ID\tStart\tEnd\n");
    printf("-------------------");
    forbl {

    }
}

void entParms()
{
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void alloc()
{
    
  
    int_input("Enter block id: ", (new.id));
    printf("Enter block size: ");

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

void first_fit(ind , int size)
{
}

void best_fit(bl *item, int size)
{
}

void fit(bl *item, int size)
{

    if (fit_bool = 0)
    {
        first_fit(&item, size);
    }
    else
    {
        best_fit(&item, size);
    }

} // fit ends

int main()
{

    int c;
    while (c != 5)
    {
        printf("Memory Allocation");
        printf("-----------------");
        printf("1) Enter parameters");
        printf("2) Allocate memory for block");
        printf("3) Deallocate memory for block");
        printf("4) Defragment memory");
        printf("5) Quit program\n\n");
        printf("Enter selection");

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
