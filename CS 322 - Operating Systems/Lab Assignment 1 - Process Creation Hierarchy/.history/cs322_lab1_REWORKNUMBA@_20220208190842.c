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
    scanf("%d", &numProcs);
    PCB = (pcb *)malloc(numProcs * sizeof(pcb));
}

void create() {}

void destroy() {}

void destroyer() {}