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

vod