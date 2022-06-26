// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ROW 2
#define COLUMN 2


#define for_proc for (int n = 0; n < ROW; n++) { \
                 for ((int m = 0; m < ROW; m++)) {\

    }\
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

  BLOCK = (pb*)malloc(ROW * sizeof(pb));
  
  for (int i = 0; i < 2; i++) {
      BLOCK[i] = (pb*)malloc(COLUMN * sizeof(pb));
  }

printf("%d\n",sizeof(BLOCK));
printf("%d\n",sizeof(BLOCK[0]));




} // end main