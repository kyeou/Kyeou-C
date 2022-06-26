#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"


int *seq;

int main() {
seq = (int*)malloc(3*sizeof(int));

scanf("%d %d %d", seq);
printf("%d %d %d", seq[0], seq[1], seq[2])
}