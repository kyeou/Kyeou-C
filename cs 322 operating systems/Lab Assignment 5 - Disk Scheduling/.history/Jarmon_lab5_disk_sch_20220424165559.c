// written by christian jarmon

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define abs_val(x) (((x) < 0) ? ((x)*-1) : (x))













void fifo() {}

void stf() {}

void scan() {}

void c_scan() {} //

void quit() {}

int main()
{
    printf("%d - %d\n", -1, abs_val(-1)); 
/*
    int c = -1;
    while (c != 6)
    {
        printf("\nMemory Allocation\n");
        printf("-----------------\n");
        printf("1) Enter parameters\n");
        printf("2) Calculate distance to traverse tracks using FIFO\n");
        printf("3) Calculate distance to traverse tracks using SSTF\n");
        printf("4) Calculate distance to traverse tracks using Scanv\n");
        printf("5) Calculate distance to traverse tracks using C-Scan\n");
        printf("6) Quit program and free memory\n\n");
        int_input("Enter selection: ", c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            fifo();
            break;
        case 3:
            stf();
            break;
        case 4:
            scan();
            break;
        case 5:
            c_scan();
            break;
            case 6:
            quit();
            break;
        default:
            printf("Not a selection.");
            break;
        }
    }
    */
}