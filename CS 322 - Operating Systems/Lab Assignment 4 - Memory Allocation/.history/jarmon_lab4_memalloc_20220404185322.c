#include "stdio.h"
#include "stdlib.h"
#include "limits.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &var)

#define while_bl bl* ttp = &PHY_MEM[0]; while (ttp->next != NULL)



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
    while_bl {
        printf("%d\t%d\t%d\n", ttp->id, ttp->)
    }
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
  fit(&PHY_MEM[amt - 1], s);

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

//these functions return the process whos next can be set to the new process
bl* first_fit(int size)
{

}

bl* best_fit( int size)
{
//a and b represent block indices, PHY_MEM[a].next = b;
int a, b, ts = INT_MAX;


while_bl {
    if (ttp->next->start_loc - ttp->end_loc > size && ttp->next->start_loc - ttp->end_loc < ts) {
        ts = ttp->next->start_loc - ttp->end_loc;
        ttp = ttp->next;
    }
}


}//end best fit

//i is the block we are tying to insert, m is the block to start moving from 
//this function is called by best_fit and first_fit


void fit(bl* item, int size)
{

    if (fit_bool)
    {
       bl * temp = best_fit(size);
       item->next = temp->next;
       temp->next = item;
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
