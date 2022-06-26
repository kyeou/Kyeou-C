// written by christian jarmon

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define abs_val(x) (((x) < 0) ? ((x)*-1) : (x))
#define for_cyl for (int i = 0; i < size; i++)

int* seq, size; bool* seq_bool;









void entParms() {
     
      int_input("Enter size of sequence: ", size);
      seq = (int *)malloc(size* sizeof(int));
      bool= (int *)malloc(size* sizeof(bool));
      int_input("Enter starting track: ", seq[0]);
      
      printf("Enter sequence of tracks to seek: ");
        for_cyl
        {
            i++;
            scanf("%d", &(seq[i]));

        } // end for
}

void fifo() {

} //the disk movement is the abs_val(terminal - initial)

void stf() {}

void scan() {} //start a point, go to the 0 direction and if a service is required their service it, then go the other way

void c_scan() {}//start at a point, go towards the end of the disk, when end reached, return to 0 to get cyliders before starting point

void quit() {}

int main()
{
 
    int c = -1;
    while (c != 6)
    {
        printf("\nDisk scheduling\n");
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
    
}