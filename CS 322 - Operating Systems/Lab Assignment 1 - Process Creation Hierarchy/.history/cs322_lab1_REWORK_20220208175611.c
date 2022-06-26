// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>

int numProcs;
int aoc;

struct children
{
    int *iChild;
    int *next;
};

struct process
{
    int parent;
    struct children children;
} *PCB = NULL;

typedef struct process pcb;
typedef struct children sChild;

void printProcs()
{
    for (int i = 0; i < numProcs; i++)
    {
        if (PCB[i].children.iChild != NULL)
        {
            printf("PCB[%d] is the parent of: ", i);
            for (int a = 0; a < numProcs; a++)
            {
                if (PCB[a].parent == i)
                {
                    if (a != i)
                    {
                        // printf("\tCHILD FOUND\t");
                        printf("PCB[%d]\t", a);
                    }
                }
            }
            printf("\n");
        }
    }
    printf("\n");
} // end of print

void entParms()
{
    printf("Enter maximum number of processes: ");
    scanf("%d", &numProcs);
    PCB = (pcb *)malloc(numProcs * sizeof(pcb));
    aoc = 0;
    PCB[0].children.iChild = NULL;
    PCB[0].children.next = NULL;
    for (int m = 1; m < numProcs; m++)
    {
        // printf("\n%d\n", m);
        PCB[m].parent = -1;
        PCB[m].children.iChild = NULL;
        PCB[m].children.next = NULL;
    } // for ends
    return;
}

// for each new child PCB[#] = (int*)malloc(sizeof(int))
void create()
{
    int par, newC, newLink = 0;
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    aoc++;
    newC = aoc;
    PCB[newC].parent = par;
    if (PCB[par].children.iChild == NULL)
    {
        // printf("\nIF REACHED\n");
        PCB[par].children.iChild = (int *)malloc(sizeof(int));
        *(PCB[par].children.iChild) = newC;
        // printf("NEW CHILD %d\n", *(PCB[par].children.iChild));
    }
    else if (PCB[par].children.next == NULL)
    {
        // printf("\n2ND IF REACHED\n");
        PCB[par].children.next = (int *)malloc(sizeof(int));
        *(PCB[par].children.next) = newC;
    }
    else
    {
        // if "iChild" is filled, it should be next, if next is filled, PCB[next].children.iChild = newC
        // the recursiveness of this can be done numerically

        // printf("\nELSE REACHED\n");
        newLink = *(PCB[par].children.next);
        // printf("\nNEWLINK IN ACTION\n");
        int whileC = 0;
        while (PCB[newLink].children.iChild != NULL)
        {
            whileC++;
            // printf("\nWHILE REACHED -- Current %d\n", whileC);
            if (PCB[newLink].children.next == NULL)
            {
                PCB[newLink].children.next = (int *)malloc(sizeof(int));
                break;
            }
            newLink = *(PCB[newLink].children.next);
        } // end while
        PCB[newLink].children.iChild = (int *)malloc(sizeof(int));
        *(PCB[newLink].children.iChild) = newC;
        // printf("\nnewC SET\n");
    }

    //    *(PCB[par].children.iChild) = aoc;
    //  PCB[par].children.next = NULL;
    printProcs();
} // end of create

//.next should never be called under any circumstances
int recCalls = 0; // num of recc calls plus 1
/*
void destroy(pcb p)
{
    recCalls++;
    printf("\nCALLS %d Child of Curr Par %d \n", recCalls, *(p.children.iChild));
    int a =  (p.children.iChild != NULL) ?  *(p.children.iChild) : a;
    if (p.children.iChild == NULL)
    {
        return;
    }
    else
    {
        printf("\nELSE REACHED dest\n");
        if (PCB[*(p.children.iChild)].children.iChild != NULL) {
            destroy(PCB[*(PCB[*(p.children.iChild)].children.iChild)]);
        }
        destroy(PCB[*(p.children.next)]);
        p.children.iChild = NULL;
        printf("CHILD NULLED -- ");
        free(p.children.iChild);
        printf("CHILD FREED -- NOW RELEASING PROCESS: %d -- ", PCB[a].parent);
        PCB[a].parent = -1;
        printf("PARENT FREED -- \n");
    }
} // end destroy    */

void destroy(pcb p)
{
    int a = (p.children.iChild != NULL) ? *(p.children.iChild) : a; // this is the index of child process
    if (p.children.iChild == NULL)
    { // if process has no children, the process should be freed in destroyer()
    printf("\nRETURN IF REACHED\n");
        return;
    }
    else if (p.children.next != NULL)
    { 
         printf("\nRETURN ELSE REACHED\n");
        if (PCB[a].children.iChild != NULL)
        {
            printf("\nNEST RECC CALLED\n");
            destroy(PCB[a]);
        } // end of if
        PCB[*(p.children.iChild)].parent = -1;
    p.children.iChild = NULL;
        free(p.children.iChild)

    } // end of else
} // end of destroy

void destroyer()
{
    if (PCB != NULL)
    {
        int par;
        printf("Enter the index of the process whose descendants are to be destroyed: ");
        scanf("%d", &par);
        if (PCB[par].children.iChild != NULL)
        {
            printf("\nDESTROY CALLED\n");
            destroy(PCB[0]);
        } // end if
    }
    return;
    printProcs();
} // end of destroyer

void quit()
{

    if (PCB != NULL)
    {
        for (int i = 0; i < numProcs; i++)
        {
            if (PCB[i].children.iChild != NULL)
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
        case 5:
            printProcs();
            break;
        default:
            printf("not a choice");
        } // switch ends
    }     // while ends

    printf("End\n");
    return 1; /* indicates success */
} /* end of procedure */