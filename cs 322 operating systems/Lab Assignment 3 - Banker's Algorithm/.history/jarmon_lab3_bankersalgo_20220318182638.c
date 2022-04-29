// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define for_proc for (int b = 0; b < numProcs; b++)
#define for_each_cond(x, y)            \
    for (int b = 0; b < numProcs; b++) \
    {                                  \
        if (x)                         \
        {                              \
            y;                         \
        }                              \
    }
#define compareVEC(V1, V2, size) for (int i )
#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

struct process
{
    int id;
    bool seq;
    struct claim
    {
        int amt;
        int current;
        

    } *CV = NULL; // end nest struct
} *PV = NULL;     // end struct 1

int main()
{

    int c;
    while (c != 5)
    {
        printf("\nBatch Scheduling\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Run the Banker's algorithm to determine a safe sequence\n");
        printf("3) Quit program and free memory\n\n");
        int_input("Make a selection: ", c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            bankers();
            break;
        case 5:
            quit();
            break;
        default:
            printf("not a choice");
        }
    }

    return 1; /* indicates success */

} // end main

/*
input:
 1
 5
 3
 10 5 7
 7 5 3
 3 2 2
 9 0 2
 2 2 2
 4 3 3
 0 1 0
 2 0 0
 3 0 2
 2 1 1
 0 0 2
 */