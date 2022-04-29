// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>

int numProcs;

struct children
{
    int *itself;
    int *next;
};

struct process
{
    int parent;
    int aoc;
    struct children *children;
} *PCB = NULL;

typedef struct process pcb;
typedef struct children sChild;

void printProcs()
{
}

void entParms()
{
    printf("Enter maximum number of processes: ");
    scanf("%d", &numProcs);
    PCB = (pcb *)malloc(numProcs * sizeof(pcb));
    PCB[0].aoc = 0;
    PCB[0].children->itself = NULL;
    PCB[0].children->next = NULL;
    for (int m = 1; m < numProcs; m++)
    {
        PCB[m].parent = -1;
        PCB[m].children->itself = NULL;
        PCB[m].children->next = NULL;
    } // for ends
    return;
}

// for each new child PCB[#] = (int*)malloc(sizeof(int))
void create()
{
    int par;
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    PCB[par].aoc++;
    (PCB[par].children->itself) = bc();
    (PCB[par].children)[PCB[par].aoc] = PCB[bC() + 1];
}

// find biggest child
int bC()
{
    int bigboy = 0;
    for (int i = 0; i < numProcs; i++)
    {
        bigboy = (PCB[i].aoc > bigboy) ? PCB[i].aoc : bigboy;
    }
    return bigboy;
} // end of bC

void destroy(pcb p)
{
    if (p.children == NULL)
    {
        return;
    }
    else
    {
        for (int q = 0; q < p.aoc; q++)
        {
            // p.children[q] = NULL;
            free(&(p.children[q]));
        } // end for
    }     // end else
} // end destroy

void destroyer()
{
    if (PCB != NULL)
    {
        int par;
        printf("Enter the index of the process whose descendants are to be destroyed: ");
        scanf("%d", &par);
        if (PCB[par].children != NULL)
        {
            destroy(PCB[par]);
        } // end of nested if
    }     // end of if
} // end of destroyer

void quit()
{

    if (PCB != NULL)
    {
        for (int i = 0; i < numProcs; i++)
        {
            if (PCB[i].children != NULL)
            {
                destroy(PCB[i]);
            }
        }
        free(PCB);
        // printf("PCB Freed");
    }

    return;
} /* end of procedure */
int main()
{

    int c;
    while (c != 4)
    {
        printf("\nProcess creation and destruction\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Create a new child process\n");
        printf("3) Destroy all descendants of a process\n");
        printf("4) Quit program and free memory\n\n");
        printf("Enter selection: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            create();
            break;
        case 3:
            destroyer();
            break;
        case 4:
            quit();
            break;
        default:
            printf("not a choice");
        } // switch ends
    }     // while ends

    printf("End\n");
    return 1; /* indicates success */
} /* end of procedure */