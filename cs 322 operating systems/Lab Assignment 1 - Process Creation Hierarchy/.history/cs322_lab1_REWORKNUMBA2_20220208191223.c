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

void printProcs() {
    for (in)
}

void entParms() {
     printf("Enter maximum number of processes: ");
    scanf("%d", &numOfProcs);
    PCB = (pcb *)malloc(numOfProcs * sizeof(pcb));
     PCB[0].field = 0;
     PCB[0].next = (pcb *)malloc(sizeof(pcb));
      PCB[0].next = NULL;
     for (int m = 1; i < numOfProcs; m++) {
         PCB[m].field = m;
         PCB[m].next = (pcb *)malloc(sizeof(pcb));
         PCB[m].next = NULL;
     }
}

void create() {

}

void destroy() {}

void destroyer() {}