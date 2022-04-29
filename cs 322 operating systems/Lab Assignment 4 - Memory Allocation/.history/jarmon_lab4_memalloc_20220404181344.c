#include "stdio.h"
#include "stdlib.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define while_bl while (ttp.next != NULL)

int fit_bool, pm_size, amt = 0;

struct block
{
    int id, start_loc, end_loc;
    struct block *next;
}*PHY_MEM = NULL;
//create a dynamic array and still have nexts jump around the array


typedef struct block bl;

void prt() {
    printf("ID\tStart\tEnd\n");
    printf("-------------------");
    
}

void entParms()
{
    PHY_MEM = (bl*)malloc(sizeof(bl)); amt++;
    int_input("Enter size of physical memory: ", pm_size);
    int_input("Enter hole-fitting algorithm (0=first fit, 1=best_fit): ", fit_bool);
}

void alloc()
{
    
 int s;
  PHY_MEM = (bl*)realloc(PHY_MEM, amt);
  amt++;
  int_input("Enter block id: ", PHY_MEM[amt -1 ].id);
  int_input("Enter block size:", s);
  fit(PHY_MEM[amt - 1], s);

}

void delloc()
{
}

void defrag()
{
    ;
}

void quit()
{
    ;
}

//these functions determine the start_locs and end_locs

//so when we find the smallest possible gap, record the process whos next is gonna be set, call the move function at the next, next should be ready, set that to &item
void first_fit(bl item, int size)
{

}

void best_fit(bl item, int size)
{

}//end best fit

void move(bl* m) {
bl * end;

bl* temp = &m; 
long int *adds;
int a = 0;
while (temp->next != NULL) {
    temp = temp->next;
    a++;
}
end = &temp;
//this means end->next is empty and will be set to end in the end
adds = (long int*)malloc(sizeof(long int));

bl* temp = &m; int coun
while (temp->next != NULL) {
    adds
    temp = temp->next;
}

end->next = (bl*)malloc(sizeof(bl));



void fit(bl item, int size)
{

    if (fit_bool)
    {
        best_fit(item, size);
    }
    else
    {
        first_fit(item, size);
    }

} // fit ends

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
