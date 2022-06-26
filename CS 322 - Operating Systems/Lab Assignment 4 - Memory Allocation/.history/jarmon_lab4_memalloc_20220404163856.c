#include "stdio.h"
#include "stdlib.h"

#define int_input(msg, var) \
    printf(msg)             \
        scanf("%d", &var)

void entParms()
{
    ;
}

void alloc()
{
    ;
}

void delloc()
{
    ;
}

void defrag()
{
    ;
}

void quit()
{
    ;
}

int main()
{

    int c;
    while (c != 5)
    {
        printf("Memory Allocation");
        printf("-----------------");
        printf("1) Enter parameters");
        printf("2) Allocate memory for block");
        printf("3) Deallocate memory for block");
        printf("4) Defragment memory");
        printf("5) Quit program");

        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            alloc();
            break;
        case 3:
            delloc();
            break;
        case 4:
            defrag();
            break;
        case 5:
            quit();
            break;
        }
    }
}

/*
1
1024
1
2
0
128
2
1
320
2
2







*/
