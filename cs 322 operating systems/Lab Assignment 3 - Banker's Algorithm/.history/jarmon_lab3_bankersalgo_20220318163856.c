// written by christian jarmon

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

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
    int mac
    printf(msg);            \
    scanf("%d", &var)




struct process {

} **BLOCK = NULL;





int main() {

 int c;
    while (c != 5)
    {
        printf("\nBatch Scheduling\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Run the Banker's algorithm to determine a safe sequence\n");
        printf("3) Quit program and free memory\n\n");
        printf("Enter selection: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            bankers();
            break;
        case 5:
            quit();
            break;
        default:
            printf("not a choice");
        }
    }

    return 1; /* indicates success */



}//end main