// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define FOR_PROC for (int p = 0; p < proc_amt; p++)
#define FOR_RES for (int r = 0; r < res_amt; r++)
#define INT_INPUT(msg, var) \
    printf(msg);            \
    scanf("%d", &var)
#define IF_THEN(x, y) \
    if ((x))          \
    {                 \
        y;            \
    }
#define ALLOC(size, type) (type *)malloc(size * sizeof(type))

int res_amt,
    proc_amt, *seq, seqCount = 0;

struct process
{
    bool seq, unsafe;
    struct claim
    {
        int max_amt, current, potential;
    } * CV;
} *PV = NULL;

// PV[0].CV[0].current points to p0's r0 ALLOCation

struct resource
{
    int ramt;
    int aval;
} *RES = NULL;

typedef struct process pv;
typedef struct claim cv;
typedef struct resource re;

void VALUECHECK()
{
    FOR_PROC
    {
        printf("%d: ", p);
        FOR_RES
        {
            printf("%d\t", PV[p].CV[r].max_amt);
        }
        printf("\n");
    }
}

// bankers algo
// check if potential < respective available_res (max_amt - current)\
// for (each process) {
// for each claim (indexed as i) {
// check that process.claim[i].potential < RES[i].aval
//}
//}

void prt()
{
    printf("\n        Units   Available\n");
    printf("------------------------\n");
    FOR_RES
    {
        printf("r%d\t%d\t%d\n", r, RES[r].ramt, RES[r].aval);
    } // end prt res
    // printf("\n");
    printf("\n  \tMax claim");
    for (int i = 0; i < res_amt; i++)
    {
        printf("\t");
    }
    printf("Current");
    for (int i = 0; i < res_amt + 1; i++)
    {
        printf("\t");
    }
    printf("Potential\n  \t");
    // printf("  \t");
    for (int i = 0; i < 3; i++)
    {
        FOR_RES
        {
            printf("r%d\t", r);
        }
        printf("\t");
    }
    printf("\n--------");
    for (int i = 0; i < res_amt; i++)
    {
        for (int b = 0; b < 30; b++)
        {
            printf("-");
        }
    }
    printf("\n");
    FOR_PROC
    {
        printf("p%d\t", p);
        FOR_RES
        {
            printf("%d\t", PV[p].CV[r].max_amt);

        } // end for res
        printf("\t");
        FOR_RES
        {
            printf("%d\t", PV[p].CV[r].current);

        } // end for res
        printf("\t");
        FOR_RES
        {
            printf("%d\t", PV[p].CV[r].potential);

        } // end for res
        printf("\t\n");
        // printf("\n");
    } // end for proc

} // end prt

void entParms()
{
    INT_INPUT("Enter selection: ", proc_amt);
    INT_INPUT("Enter number of resources: ", res_amt);
    PV = ALLOC(proc_amt, pv);
    seq = ALLOC(proc_amt, int);
    FOR_PROC
    {
        PV[p].CV = (cv *)malloc(res_amt * sizeof(cv));
    }
    RES = ALLOC(res_amt, re);
    printf("Enter number of units for resources (r0 to r%d):", res_amt - 1);

    // INT_INPUT1(("Enter number of units for resources (r0 to r%d):", res_amt), RES[0].ramt, RES[1].ramt, RES[2].ramt);
    for (int i = 0; i < res_amt; i++)
    { // 1 0 2
        scanf("%d", &(RES[i].ramt));
    } // end for

    FOR_RES
    {
        RES[r].aval = RES[r].ramt;
    }
    FOR_PROC
    {
        printf("Enter maximum number of units process p%d will request from each resource (r0 to r%d): ", p, res_amt - 1);
        // INT_INPUT3("", PV[p].CV[0].max_amt, PV[p].CV[1].max_amt, PV[p].CV[2].max_amt);
        for (int i = 0; i < res_amt; i++)
        {
            scanf("%d", &(PV[p].CV[i].max_amt));
        } // end for
    }

    FOR_PROC
    {

        printf("Enter number of units of each resource (r0 to r%d) ALLOCated to process p%d: ", res_amt - 1, p);
        // INT_INPUT3("", PV[p].CV[0].current, PV[p].CV[1].current, PV[p].CV[2].current);
        for (int i = 0; i < res_amt; i++)
        {
            scanf("%d", &(PV[p].CV[i].current));
        } // end for
        FOR_RES
        {

            RES[r].aval -= PV[p].CV[r].current;
            PV[p].CV[r].potential = PV[p].CV[r].max_amt - PV[p].CV[r].current;
        } // end for res

    } // end for
    // printf("CALL FOR PRINT\n\n");

    // VALUECHECK();
    prt();
}
// add a 2nd boolean to check "unsafe"
// if all not seq but unsafe, deadlock
bool checkSeq()
{

    // bool deadlock = 0;
    int un = 0, se = 0;
    FOR_PROC
    {
        IF_THEN(PV[p].seq == 0 && PV[p].unsafe == 1, un++)
        IF_THEN(PV[p].seq, se++)
    }
    // printf("DEADLOACK VALUES: un-%d se-%d: \n", un, se);
    if (un + se == proc_amt && un >= 1)
    {
        printf("Deadlock reached!\n");
        return false;
    }
    else if (un + se == proc_amt && un == 0)
    {
        printf("\nSafe sequence: ");
        FOR_PROC
        {
            printf("P%d ", seq[p]);
        }
        printf("\n");
        return false;
    }
    else
    {
        return true;
    }

    /* FOR_PROC
     {
         if (!(PV[p].seq))
         {
             return true;
         }
     } // end proc */
    // return true;
} // end func

bool csa(cv *C)
{
    FOR_RES
    {
        IF_THEN(C[r].potential > RES[r].aval, return false)
    } // end for
    return true;
} // end func

void printCheck(int pi)
{
    printf("Checking: <");
    FOR_RES
    {
        printf(" %d ", PV[pi].CV[r].potential);
    }
    printf("> <= <");
    FOR_RES
    {
        printf(" %d ", RES[r].aval);
    }
    printf("> :");
}

void bankers()
{

    FOR_PROC
    {
        PV[p].seq = 0;
        PV[p].unsafe = 0;
    }

    while (checkSeq())
    {
        FOR_PROC
        {
            if (!(PV[p].seq))
            {
                printCheck(p);
                if (csa(PV[p].CV))
                {
                    seq[seqCount] = p;
                    seqCount++;
                    printf("p%d safely sequenced\n", p);
                    FOR_RES
                    {
                        RES[r].aval += PV[p].CV[r].current;
                        PV[p].CV[r].current = 0;
                        PV[p].CV[r].max_amt = 0;
                        PV[p].CV[r].potential = 0;
                    }
                    PV[p].seq = 1;

                    FOR_PROC
                    {
                        PV[p].unsafe = 0;
                    }
                }
                else
                {
                    printf("p%d could not be sequenced\n", p);
                    PV[p].unsafe = 1;
                }
            }
        } // end for

    } // end while

    //   printf("Deadlock reached!\n");
    // prt();
} // end bankers

void quit()
{

    FOR_PROC
    {
        PV[p].CV = NULL;
        free(PV[p].CV);
    }

    PV = NULL;
    free(PV);
    printf("Quitting program...\n");
}

int main()
{

    int c;
    while (c != 3)
    {
        printf("\nBatch Scheduling\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Run the Banker's algorithm to determine a safe sequence\n");
        printf("3) Quit program and free memory\n\n");
        INT_INPUT("Make a selection: ", c);
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
2
3

 */

/*





*/

/*
input:
1
10
3
10 5 7
7 5 3
3 2 2
9 0 2
2 2 2
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
4 3 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
2
3

 */
