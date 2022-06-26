// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numOfProcs, aoc;

struct process
{
    int field, parent, *child;
    struct process *next;
} *PCB = NULL;
// the first child is the beginning of the succesive next's
// next is only used if the process itself is a child
// so 0 should not use next at all but it should have child 1, then PCB[1] has next 2 then PCB[2] has next 4
typedef struct process pcb;

void printProcs()
{
    for (int i = 0; i < numOfProcs; i++)
    {
        if (PCB[i].child != NULL)
        {
            printf("PCB[%d] is the parent of: ", i);
            for (int a = 0; a < numOfProcs; a++)
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
} // func ends

void entParms()
{
    printf("Enter maximum number of processes: ");
    scanf("%d", &numOfProcs);
    PCB = (pcb *)malloc(numOfProcs * sizeof(pcb));
    aoc = 0;
    PCB[0].field = 0;
    PCB[0].next = (pcb *)malloc(sizeof(pcb));
    PCB[0].next = NULL;
    PCB[0].child = (int*)malloc(sizeof(int));
    PCB[0].child = NULL;
    for (int m = 1; m < numOfProcs; m++)
    {
        PCB[m].field = m;
        PCB[m].next = (pcb *)malloc(sizeof(pcb));
        PCB[m].next = NULL;
        PCB[m].child = (int*)malloc(sizeof(int));
        PCB[m].child = NULL;
    }
}

void create()
{
    int par, newC, newLink, rPoEn;
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    aoc++;
    newC = aoc;
    if (PCB[par].child == NULL)
    {
        printf("\nIF REACHED\n");
        PCB[par].child = (int *)malloc(sizeof(int));
        *(PCB[par].child) = newC;
        PCB[newC].parent = par;
    }
    else
    {
        printf("\nELSE REACHED\n");
        // PCB[*(PCB[par].child)].next = (pcb *)malloc( sizeof(pcb));
        printf("%zu\n", (PCB[*(PCB[par].child)].next) == NULL); //This results in TRUE
        //so we have to do an else if, take PCB[newC] 
        newLink = PCB[*(PCB[par].child)].next->field; //This is terminating the program
        printf("\n The next field: ");
        printf("%d\n", PCB[*(PCB[par].child)].next->field);
        while (PCB[*(PCB[newLink]).child].next != NULL)
        {
            printf("\nWHILE REACHED\n");
            newLink = PCB[*(PCB[newLink]).child].next->field;
            rPoEn = PCB[*(PCB[newLink]).child].parent;
        }
        PCB[newLink].field = newLink;
        PCB[newLink].parent = par;
        PCB[rPoEn].next = &(PCB[newLink]);
    } // end of else
    printProcs();
} // end of create

void destroy() {}

void destroyer() {}

void quit() {}

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