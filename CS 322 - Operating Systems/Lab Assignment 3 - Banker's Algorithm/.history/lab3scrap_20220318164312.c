// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 2


#define for_proc for (int b = 0; b < numProcs; b++)
#define for_each_cond(x, y)            \
    for (int b = 0; b < numProcs; b++) \
    {                                  \
        if (x)                         \
        {                              \
            y;                         \
        }                              \
    }
#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

struct process
{
int i;
} **BLOCK = NULL;

typedef struct process pb;


int main()
{

  BLOCK = (int*)malloc(SIZE * sizeof(pb));
  *BLOCK = (int*)malloc(SIZE * sizeof(pb));

for (int a = 0; i < )

} // end main