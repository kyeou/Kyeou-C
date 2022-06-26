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
    PCB[0].children->iChild = NULL;
    PCB[0].children->next = NULL;
    for (int m = 1; m < numProcs; m++)
    {
        PCB[m].parent = -1;
        PCB[m].children->iChild = NULL;
        PCB[m].children->next = NULL;
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
    if (PCB[par].children->iChild == NULL)
    {
        *(PCB[par].children->iChild) = newC;
    }
    else
    {
        // if "iChild" is filled, it should be next, if next is filled, PCB[next].children->iChild = newC
        // the recursiveness of this can be done numerically
        newLink = *(PCB[par].children->next);
        while (PCB[newLink].children->next != NULL)
        {
            newLink = *(PCB[newLink].children->next);
        } // end while

        *(PCB[newLink].children->iChild) = newC;
    }

    //    *(PCB[par].children->iChild) = aoc;
    //  PCB[par].children->next = NULL;
} // end of create

//->next should never be called under any circumstances
void destroy(pcb p)
{
    int a = *(p.children->iChild);
   if (p.children->iChild == NULL) {
       return;
   } else {
       destroy(PCB[*(PCB[a].children->iChild)]);
       p.children->iChild = NULL;
       free(p.children->iChild);
       PCB[*(PCB[a].children->iChild)].parent = -1;
   }
} // end destroy

void destroyer()
{
   if (p)
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