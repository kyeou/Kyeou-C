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


typedef struct process pcb;


void printChildren(pcb p)
{
    int ttp = *(p.child);
    printf("PCB[%d]\t", ttp);
    while (PCB[ttp].next != NULL)
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
        if (PCB[i].child != NULL)
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
    printf("Enter the parent process index: ");
    scanf("%d", &par);
    aoc++;
    newC = aoc;
    if (PCB[par].child == NULL)
    {
        
        PCB[par].child = (int *)malloc(sizeof(int));
        *(PCB[par].child) = newC;
        PCB[newC].parent = par;
    }
    else if (PCB[par].child != NULL && (PCB[*(PCB[par].child)].next) == NULL)
        {
     
        PCB[*(PCB[par].child)].next = &(PCB[newC]);
        PCB[newC].parent = par;
        
    }
    else
    { 
        newLink = PCB[*(PCB[par].child)].next->field;
       
        while (PCB[newLink].next != NULL) 
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
   
    if (*next == NULL)
    {
        return; 
    }
    else
    {
      
        if ((**next).child != NULL)
        {
           
            int w = (**next).field;
          
            destroy(&((**next).child));
        }
      
        if ((**next).next != NULL) {
        ridNexts(&   ((**next).next)   ); 
        }
        *next = NULL;
      
    }
} 

void destroy(int **child)
{
    if (*child == NULL)
    {
        
        return;
    }
    else
    {
        
        if (PCB[**child].next != NULL)
        {
          
            ridNexts(&(PCB[**child].next));
        }
        PCB[**child].parent = -1;
       
        *child = NULL;
       
    }
} 


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

    } 

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
        } 
    }     
  realloc(PCB, 0); 

  PCB = NULL;
  
  free(PCB);
 
   
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
