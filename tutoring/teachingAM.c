#include <stdio.h>
#include <stdlib.h> 

int *child;

void editChild(int **c) {
    **c = 2;
}

int main() {
    printf("%d\n", child);
    editChild(&child);
    printf("%d", child);
}