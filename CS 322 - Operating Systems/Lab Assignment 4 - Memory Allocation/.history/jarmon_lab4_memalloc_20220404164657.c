#include "stdio.h"
#include "stdlib.h"

#define int_input(msg, var) \
    printf(msg)             \
        scanf("%d", &var)

struct block {


} *PHY_MEM = NULL;

typedef struct block bl;

void entParms()
{
    printf("Enter size of physical memory: ");
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


void first_fit(struct block *item) {

}

void best_fit(struct block *item){

}

void fit(struct block *item) {

if (fit_bool = 0) {
first_fit(item);
} else {
best_fit(item);
}

}//fit ends


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
        printf("5) Quit program\n\n");
        printf("Enter selection");

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
224
2
3
288
3
2
2
4
128
3
1
2
2
224
2
5
64
4






*/
