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

// print children given a parent
void printChildren(pcb p)
{
    int ttp = *(p.child);
    printf("PCB[%d]\t", ttp);
    while (PCB[ttp].next != NULL)
    {
        ttp = PCB[ttp].next->field;
        printf("PCB[%d]\t", ttp);

    } // while ends
    printf("\n");
} // pC ends

void printProcs()
{
   // printf("\nPRINTING PROCS\n");
    for (int i = 0; i < numOfProcs; i++)
    {
        if (PCB[i].child != NULL)
        {
            printf("PCB[%d] is the parent of: ", i);
            printChildren(PCB[i]);
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
    PCB[0].child = (int *)malloc(sizeof(int));
    PCB[0].child = NULL;
    for (int m = 1; m < numOfProcs; m++)
    {
        PCB[m].field = m;
        PCB[m].next = (pcb *)malloc(sizeof(pcb));
        PCB[m].next = NULL;
        PCB[m].child = (int *)malloc(sizeof(int));
        PCB[m].child = NULL;
    }
}

void create()
{
    int par, newC, newLink, rPoEn;
    // rPoEn = the process that has no next
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    aoc++;
    newC = aoc;
    if (PCB[par].child == NULL)
    {
        // printf("\nIF REACHED\n");
        PCB[par].child = (int *)malloc(sizeof(int));
        *(PCB[par].child) = newC;
        PCB[newC].parent = par;
    }
    else if (PCB[par].child != NULL && (PCB[*(PCB[par].child)].next) == NULL) // set the next of the already existing child to PCB[newC]
    {
        // printf("\nELSE REACHED\n");
        //  PCB[*(PCB[par].child)].next = (pcb *)malloc( sizeof(pcb));
        //  printf("%zu\n", (PCB[*(PCB[par].child)].next) == NULL); // This results in 1 TRUE
        //  so we have to do an else if, the first else sets the intial child
        //  then the next else is what handles the next of the already existing child (the child being a process)
        PCB[*(PCB[par].child)].next = &(PCB[newC]);
        PCB[newC].parent = par;
        // printf("%zu\n", (PCB[*(PCB[par].child)].next) == NULL); // this should result in 0 FALSE
    }
    else
    { // this handles if an already existing child has a next
        // printf("%d\n", PCB[*(PCB[par].child)].next->field);
        // PCB[2].next == NULL, so then PCB[4] (aoc = 4)
        // printf("\nELSE 2 REACHED\n");
        newLink = PCB[*(PCB[par].child)].next->field;
        // printf("\n The next field: ");
        // printf("Current Field (newLink) %d\n", PCB[*(PCB[par].child)].next->field);
        while (PCB[newLink].next != NULL) // pCB[2].next == NULL,
        {
            // this while should find the next-> field that has no next
            /*
             if (PCB[newLink].next == NULL) {
                 *(PCB[newLink].next) = PCB[aoc];
             }
             */
            // printf("\nWHILE REACHED\n");
            newLink = PCB[newLink].next->field;
            // rPoEn = PCB[newLink].field;
        }
        // printf("\nAFTER WHILE\n");
        PCB[newLink].next = &PCB[aoc];
        // printf("\nAFTER POINTER SET\n");
        PCB[newLink].next->parent = par;
        /*  PCB[newLink].field = newLink;
         printf("\nNEWLINK Fielded\n");
         PCB[newLink].parent = par;
         printf("\nNEWLINK NOT ORPHANED\n");
         *PCB[rPoEn].next = PCB[newLink];
         printf("\nNEWLINK NOT ORPHANED\n");
         */
    }
    // end of else
    // printf("\nCREATE ENDED\n");
    printProcs();
} // end of create
  // if i call the parent, just null the child, go to that child, and reset the parent
  // child can only be 0 < x < numofProcs OR NULL
  // parent can only be that shit OR -1

// call parent
// null child (this does not get rid of the process) (must record *child to another int variable)
// go through nexts, which are processes, null all of the processes, meaning null the child and set free
// however, we need to get to the end, the process with no next, and null that process

// the nexts should be provided by destroy() <- destory parameter should be the parent
// only a child should have a next, PCB[1] and PCB[2] has a next, PCB[4] doesnt
// should only be called from destroy
void ridNexts(pcb **next)
{
    //printf("\nRID NEXT CALLED %d\n", (**next).field);
    if (*next == NULL)
    {
        return; // this means there are no more nexts, and the PCB left is the child
    }
    else
    {
       // printf("\nRID ELSE\n");
        if ((**next).child != NULL)
        {
           // printf("\nRID ELSE IF INSIDE ELSE\n");
            int w = (**next).field;
           // printf("\nPCB[%d] has a child\n", w);
            // ridNexts(PCB[w].next);
            destroy(&((**next).child));
        }
       // printf("\nALGO REACHED\n");
        if ((**next).next != NULL) {
        ridNexts(&   ((**next).next)   ); 
        }
        *next = NULL;
       // printf("\nNEXT (therby the PROCESS) NULL\n");
    }
} // end of ridNexts

void destroy(int **child)
{
    if (*child == NULL)
    {
        //printf("\nDESTORY IF\n");
        return;
    }
    else
    {
        //printf("\nDESTROY ELSE\n");
        if (PCB[**child].next != NULL)
        {
           // printf("\nRID NEXT BOUT TO BE CALLED\n");
            ridNexts(&(PCB[**child].next));
        }
        PCB[**child].parent = -1;
       // int btn = *child;
        *child = NULL;
       // printf("\nCHILD NULLED -->> %d is gone\n", btn);
    }
} // destory ends

/*
void destroy(int *child) // take a child, goes to PCB[child] takes out all train of nexts
{

    // next ends up being null has the next points to the address of another process
    // so just get rid of the process and the pre-next has no next
    //.next has to be ridden of its link to its pre-next and parent
    //  so .next
    // PCB[0]
    if (PCB[*child].child != NULL) {
        //destroy(PCB[*child].child);
        PCB[*child].child = NULL;
        //*(PCB[*child].child) = 3
        PCB[*(PCB[*child].child) ].parent = -1;
    }
    if (PCB[*child].next == NULL)
    {
       // printf("\nIF REACHED\n ");
        //printCandN(PCB[*child]);
        return;
    }
    else
    {

        //printCandN(PCB[*child]);
        //printf("\nELSE REACHED\n ");


// printCandN(PCB[*child]);//this should print twice, with the error
destroy(PCB[PCB[*child].field].next->child); // this is broken
// rid of process
// no parent and child = PCB[that index] = NULL?????
// the process has two pointers: child and next, amke sure those are null, then null the process
// printf("\nALGO REACHED --->> %d\n", *child); //this should print 1

PCB[*child].child = NULL;
PCB[*child].next = NULL;
// printf("\nN and C NULLED\n");
free(PCB[*child].next);
free(PCB[*child].child);
// printf("\nN and C FREED\n");
}
// get rid of child in the end
// need to get rid of children of the next as well
// printf("\nELSE DONE\n");
PCB[*child].parent = -1;
child = NULL;
free(child);
} // end of destory
*/

void destroyer()
{
    if (PCB != NULL)
    {
        int par;
        printf("Enter the index of the process whose descendants are to be destroyed: ");
        scanf("%d", &par);
        if (PCB[par].child != NULL)
        {
            destroy(&(PCB[par].child));
        }
//PCB[*(PCB[par].child)].parent = -1;
    } // end if

    printProcs();
}

void printCandN2()
{
    int test;
    printf("Enter the process to get info: ");
    scanf("%d", &test);
    printf("\nC N CHECK FOR FIELD %d CHILD? %zu NEXT? %zu\n", test, (PCB[test].child != NULL), (PCB[test].next != NULL));
}

void quit()
{
    if (PCB != NULL)
    {
        if (PCB[0].child != NULL)
        {
            destroy(&(PCB[0].child));
        } // end if
    }     // end of first if
  realloc(PCB, 0); 
    printProcs();
} // end of quit

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
    printf("%zu\n", realloc(PCB, 0));
   // printf("End\n");
    return 1; /* indicates success */
} /* end of procedure */
