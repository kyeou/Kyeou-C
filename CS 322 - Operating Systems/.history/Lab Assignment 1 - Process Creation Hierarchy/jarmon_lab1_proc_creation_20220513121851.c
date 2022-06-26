// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define IF_THEN(x, y) \
    if ((x))          \
    {                 \
        y;            \
    }
#define ALLOC(size, type) (type *)malloc(size * sizeof(type))

int numOfProcs, aoc;

struct process
{
    int field, parent, *child;
    struct process *next;
} *PCB = NULL;

typedef struct process pcb;

void printChildren(pcb p)
{
    int ttp = *(p.child);
    printf("PCB[%d]\t", ttp);
    while (PCB[ttp].next)
    {
        ttp = PCB[ttp].next->field;
        printf("PCB[%d]\t", ttp);
    }
    printf("\n");
}

void printProcs()
{
    for (int i = 0; i < numOfProcs; i++)
    {
        if (PCB[i].child)
        {
            printf("PCB[%d] is the parent of: ", i);
            printChildren(PCB[i]);
        }
    }
    printf("\n");
}

void entParms()
{
    printf("Enter maximum number of processes: ");
    scanf("%d", &numOfProcs);
    PCB = ALLOC(numOfProcs, pcb);
    aoc = 0;
    for (int m = 0; m < numOfProcs; m++)
    {
        PCB[m].field = m;
        PCB[m].next = NULL;
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
    if (!(PCB[par].child))
    {
        PCB[par].child = (int *)malloc(sizeof(int));
        *(PCB[par].child) = newC;
        PCB[newC].parent = par;
    }
    else if (PCB[par].child && (!(PCB[*(PCB[par].child)].next)))
    {
        PCB[*(PCB[par].child)].next = &(PCB[newC]);
        PCB[newC].parent = par;
    }
    else
    {
        newLink = PCB[*(PCB[par].child)].next->field;
        while (PCB[newLink].next)
        {
            newLink = PCB[newLink].next->field;
        }
        PCB[newLink].next = &PCB[aoc];
        PCB[newLink].next->parent = par;
    }
    printProcs();
}

void ridNexts(pcb **next)
{
    IF_THEN(!(*next), return )
    else
    {
        IF_THEN((**next).child, destroy(&((**next).child)))
        IF_THEN((**next).next, ridNexts(&((**next).next)))
        *next = NULL;
    }
}

void destroy(int **child)
{
    IF_THEN(!(*child), return )
    else
    {
        IF_THEN(PCB[**child].next, ridNexts(&(PCB[**child].next)))
        PCB[**child]
    .parent = -1;
        *child = NULL;
    }
}

void destroyer()
{
    if (PCB)
    {
        int par;
        printf("Enter the index of the process whose descendants are to be destroyed: ");
        scanf("%d", &par);
        IF_THEN(PCB[par].child, destroy(&(PCB[par].child)))
    }
    printProcs();
}

void printCandN2()
{
    int test;
    printf("Enter the process to get info: ");
    scanf("%d", &test);
    printf("\nC N CHECK FOR FIELD %d CHILD? %zu NEXT? %zu\n", test,
           (PCB[test].child != NULL), (PCB[test].next != NULL));
}

void quit()
{
    IF_THEN(PCB, IF_THEN(PCB[0].child, destroy(&(PCB[0].child))))

    PCB = NULL;
    free(PCB);
    printf("Quitting program...");
}

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
        }
    }

    return 1; /* indicates success */
}

/*

1
5
2
0
2
0
2
2
2
0
3
0
4



*/