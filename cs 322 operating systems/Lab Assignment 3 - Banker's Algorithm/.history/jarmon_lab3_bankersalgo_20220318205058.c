// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define for_proc for (int p = 0; p < proc_amt; p++)
#define for_res for (int r = 0; r < res_amt; r++)
#define for_each_cond(x, y)            \
    for (int b = 0; b < numProcs; b++) \
    {                                  \
        if (x)                         \
        {                              \
            y;                         \
        }                              \
    }

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define int_input3(msg, v0, v1, v2) \
    printf(msg);                    \
    scanf("%d %d %d", &v0, &v1, &v2)

int res_amt,
    proc_amt;

struct claim
{
    int max_amt, current, potential;

}; // end nest struct

struct process
{
    int id;
    bool seq;
    struct claim *CV;
} *PV = NULL; // end struct 1

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
//        check if potential < respective available_res (max_amt - current)\
//for (each process) {
// for each claim (indexed as i) {
// check that process.claim[i].potential < RES[i].aval
//}
//}

void prt()
{
    printf("        Units   Available\n");
    printf("------------------------\n");
    for_res
    {
        printf("r%d\t%d\t%d\n", r, RES[r].ramt, RES[r].aval);
    } // end prt res
    printf("\n");
    printf("  \tMax claim\t\t\tCurrent\t\t\tPotential\n");
    for (int i = 0; i < 3; i++) {
        for_res {
        printf("r%d", r);
        }
    }
    printf("------------------------------------------------------------------------------------------\n");
    for_proc
    {
for_res{
/*
        printf("p%d  \t%d\t%d\t%d\t\t", p, PV[p].CV[r].max_amt, PV[p].CV[r].max_amt, PV[p].CV[2].max_amt);
        printf("%d\t%d\t%d\t\t", PV[p].CV[0].current, PV[p].CV[1].current, PV[p].CV[2].current);
        printf("%d\t%d\t%d\n", PV[p].CV[0].potential, PV[p].CV[1].potential, PV[p].CV[2].potential);
        */
}//end for res
    } // end for proc

} // end prt

void entParms()
{
    int_input("Enter selection: ", proc_amt);
    int_input("Enter number of resources: ", res_amt);
    PV = (pv *)malloc(proc_amt * sizeof(pv));
    for_proc
    {
        PV[p].CV = (cv *)malloc(res_amt * sizeof(cv));
    }

    RES = (re *)malloc(res_amt * sizeof(re));
    int_input3(("Enter number of units for resources (r0 to r%d):", res_amt), RES[0].ramt, RES[1].ramt, RES[2].ramt);
    for_res
    {
        RES[r].aval = RES[r].ramt;
    }
    for_proc
    {
        printf("Enter maximum number of units process p%d will request from each resource (r0 to r2): ", p);
        int_input3("", PV[p].CV[0].max_amt, PV[p].CV[1].max_amt, PV[p].CV[2].max_amt);

    } // end for

    for_proc
    {
        printf("Enter number of units of each resource (r0 to r2) allocated to process p%d: ", p);
        int_input3("", PV[p].CV[0].current, PV[p].CV[1].current, PV[p].CV[2].current);
        for_res
        {
            RES[r].aval -= PV[p].CV[r].current;
PV[p].CV[r].potential = PV[p].CV[r].max_amt - PV[p].CV[r].current;
        } // end for res
        
    } // end for
    prt();
}

void bankers()
{
    
    for_proc {
        PV[p].seq = 0;
    }
}

void quit()
{
    for_proc
    {
        PV[p].CV = NULL;
        free(PV[p].CV);
    }
    for_proc
    {
        PV = NULL;
        free(PV);
    }
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
        int_input("Make a selection: ", c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            bankers();
            break;
        case 3:
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