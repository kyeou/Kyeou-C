

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define NUM1 scanf("%d")




int main()
{

int [NUM1];

int **alloc = (int**)malloc((2*3)*sizeof(int));

printf("%d %d\n", sizeof(alloc), sizeof(*alloc));

for (int a = 0; a < 2; a++) {
alloc[a] = (int*)malloc(2*sizeof(int));
}




for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 3; b++) {
        alloc[a][b] = b;
    }
}

for (int a = 0; a < 2; a++) {
    printf("%d\t\t", a);
    for (int b = 0; b < 3; b++) {
        printf("%d\t",alloc[a][b]);
    }
    printf("\n");
}




} // end main

