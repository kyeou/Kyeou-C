// written by christian jarmon

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define int_input(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define abs_val(x) (((x) < 0) ? ((x) * -1) : (x))
#define for_cyl for (int i = 1; i < size; i++)

int *seq, *traversal, size, big_val = 0;
bool *seq_bool, direction;

bool all_seq()
{
    for_cyl
    {
        if (seq_bool[i] == false)
        {
            return false;
        }
    }
    return true;
}

void entParms()
{

    int_input("Enter size of sequence: ", size);
    seq = (int *)malloc(size * sizeof(int));
    traversal = (int *)malloc(size * sizeof(int));
    seq_bool = (bool *)malloc(size * sizeof(bool));
    int_input("Enter starting track: ", seq[0]);

    printf("Enter sequence of tracks to seek: ");
    for_cyl
    {
        scanf("%d", &(seq[i]));

    } // end for
    big_val = (seq[0] > big_val) ? seq[0] : big_val;
    for_cyl
    {
        big_val = (seq[i] > big_val) ? seq[i] : big_val;

    } // end for
}

void print_trav()
{
    printf(" %d", traversal[0]);
    for_cyl
    {
        printf(" %d", traversal[i]);
    }
    printf("\n");
}

void fifo()
{
    int distance = 0;
    seq_bool[0] == true;
    traversal[0] = seq[0];
    while (!(all_seq()))
    {
        for_cyl
        {
            if (seq_bool[i] == false)
            {
                distance += abs_val(seq[i] - seq[i - 1]);
                traversal[i] = seq[i];
                seq_bool[i] = true;

            } // end if
        }     // end_for
    }         // end_while
    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);
} // the disk movement is the abs_val(terminal - initial)

int findShortestIndex(int seq_count)
{
    int shortest = INT_MAX;
    seq_bool[0] = true;
    int ret_index;
    for_cyl
    {
      //if ((abs_val(traversal[seq_count-1] - seq[i]) < shortest && seq_bool[i] == false)) {printf("TRUE CASE %d\n", i);}
        ret_index = (abs_val(traversal[seq_count-1] - seq[i]) < shortest && seq_bool[i] == false) ? i : ret_index;
        shortest = (seq[i] < shortest && seq_bool[i] == false) ? abs_val(traversal[seq_count-1] - seq[i])  : shortest;
    }

    seq_bool[ret_index] = true;

   // printf("\t\t%d\n", ret_index);
    return ret_index;
}

void stf()
{
    int distance = 0;
    int seq_count = 1;
    for_cyl
    {
        seq_bool[i] = false;
    }
    traversal[0] = seq[0];
    seq_bool[0] = true;
    while (!(all_seq()))
    {

        traversal[seq_count] = seq[findShortestIndex(seq_count)];
        distance += abs_val(traversal[seq_count] - traversal[seq_count - 1]);
        seq_count++;
        //print_trav();

    } // end while

    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);
}

void scan() {
    
} // start a point, go to the 0 direction or bigger dierction and if a service is required their service it, then go the other way

void c_scan() {} // start at a point, go towards the end of the disk, when end reached, return to 0 to get cyliders before starting point

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

/*


1
5
5
12 3 7 4
2
3


*/