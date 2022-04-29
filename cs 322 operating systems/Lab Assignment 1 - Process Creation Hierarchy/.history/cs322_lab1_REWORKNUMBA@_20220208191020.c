// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numOfProcs; 

struct process{
    int field, parent;
    struct process *next;
} *PCB = NULL;

typedef struct process pcb;

void printProcs() {}

void entParms() {
     printf("Enter maximum number of processes: ");
    scanf("%d", &numOfProcs);
    PCB = (pcb *)malloc(numOfProcs * sizeof(pcb));
     PCB[0].field = 0;
     PCB[0].next = (pcb *)malloc(sizeof(pcb));
     for (int m = 1; i < numProcs; m++)
}

void create() {}

void destroy() {}

void destroyer() {}