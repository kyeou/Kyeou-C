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
//the first child is the beginning of the succesive next's
//next is only used if the process itself is a child
//so 0 should not use next at all but it should have child 1, then PCB[1] has next 2 then PCB[2] has next 4
typedef struct process pcb;

void printProcs()
{
    for (int i = 0; i < numOfProcs; i++)
    {
        if (PCB[i].next != NULL)
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
}//func ends

void entParms()
{
    printf("Enter maximum number of processes: ");
    scanf("%d", &numOfProcs);
    PCB = (pcb *)malloc(numOfProcs * sizeof(pcb));
    aoc = 0;
    PCB[0].field = 0;
    PCB[0].next = (pcb *)malloc(sizeof(pcb));
    PCB[0].next = NULL;
    for (int m = 1; m < numOfProcs; m++)
    {
        PCB[m].field = m;
        PCB[m].next = (pcb *)malloc(sizeof(pcb));
        PCB[m].next = NULL;
    }
}

void create()
{
     int par, newCl;
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    aoc++;
    newC = aoc;
    if (PCB[par].child == NULL) {
         PCB[par].children.iChild = (int *)malloc(sizeof(int));
        *(PCB[par].children.iChild) = newC;
    }
}

void destroy() {}

void destroyer() {}