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
#define int_input1(msg, var) \
    printf(msg);             \
    scanf("%d", &var)

#define int_input(msg, var) \
    int var;
printf(msg);
scanf("%d", &var)

    int res_amt,
    proc_amt;

struct process
{
    int id;
    bool seq;
    struct claim
    {
        int max_amt, current, potential;

    } *CV = NULL; // end nest struct
} *PV = NULL;     // end struct 1

// PV[0].CV[0].current points to p0's r0 allocation

struct resource
{
    int ramt;
    int aval;
} *RES = NULL;

typedef struct process pv;
typedef struct claim cv;
typedef struct resource re;

// bankers algo
//  check if potential < respective available_res (max_amt - current)\
//for (each process) {
// for each claim (indexed as i) {
// check that process.claim[i].potential < RES[i].aval
//}
//}

void entParms()
{
    int_input()
}
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
        int_input1("Make a selection: ", c);
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