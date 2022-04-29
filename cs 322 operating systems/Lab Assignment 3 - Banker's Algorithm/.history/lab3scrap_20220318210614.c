// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 15


#define for_proc(arg)                 \
    for (int n = 0; n < ROW; n++)     \
    {                                 \
        for (int m = 0; m < ROW; m++) \
        {                             \
            arg;                      \
        }                             \
    }
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

    BLOCK = (pb **)malloc(ROW * sizeof(pb));

    for (int i = 0; i < ROW; i++)
    {
        BLOCK[i] = (pb *)malloc(ROW * sizeof(pb));
    }

    printf("%d\n", sizeof(BLOCK));
    printf("%d\n", sizeof(BLOCK[0]));

    for_proc((BLOCK[n][m]).i = m);
    for (int m = 0; m < ROW; m++)
    {
        printf("%d  ", (BLOCK[0][m]).i);
         printf("%d  ", (BLOCK[1][m]).i);
    }


printf("--------------------------");
int i, size;
int *v;
printf("enter size: ");
scanf("%d", &size);
printf("\n");
v = malloc(size * sizeof(int));
printf("enter nums for v: ")
for(i=0; i < size; i++)
    scanf("%d", &v[i]);




} // end main