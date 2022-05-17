// written by christian jarmon

#include "stdio.h"
#include "stdlib.h"
#include "limits.h"
#include "stdbool.h"

#define INT_INPUT(msg, var) \
    printf(msg);            \
    scanf("%d", &(var))

#define ABS_VAL(x) (((x) < 0) ? ((x) * -1) : (x))
#define FOR_CYL for (int i = 1; i < size; i++)

#define IF_THEN(x, y) \
    if ((x))          \
    {                 \
        y;            \
    }
#define ALLOC(size, type) (type *)malloc(size * sizeof(type))

int *seq, *traversal, size, *seq_low, *seq_high, lc = 0, hc = 0, *seq_low_copy;
bool *seq_bool, direction;

bool all_seq()
{
    FOR_CYL
    {
        IF_THEN(seq_bool[i] == false, return false)
    }
    return true;
}

void sort()
{
    for (int i = 0; i < hc; ++i)
    {
        for (int j = i + 1; j < hc; ++j)
        {
            if (seq_high[i] > seq_high[j])
            {
                int a = seq_high[i];
                seq_high[i] = seq_high[j];
                seq_high[j] = a;
            }
        }
    }

    for (int i = 0; i < hc; ++i)
    {
        for (int j = i + 1; j < lc; ++j)
        {
            if (seq_low[i] < seq_low[j])
            {
                int a = seq_low[i];
                seq_low[i] = seq_low[j];
                seq_low[j] = a;
            }
        }
    }

    for (int i = 0; i < lc; ++i)
    {
        for (int j = i + 1; j < lc; ++j)
        {
            if (seq_low_copy[i] > seq_low_copy[j])
            {
                int a = seq_low_copy[i];
                seq_low_copy[i] = seq_low_copy[j];
                seq_low_copy[j] = a;
            }
        }
    }
}

void entParms()
{

    seq_low = ALLOC(1, int);
    seq_high = ALLOC(1, int);
    INT_INPUT("Enter size of sequence: ", size);
    seq = ALLOC(size, int);
    traversal = ALLOC(size, int);
    seq_bool = ALLOC(size, bool);
    INT_INPUT("Enter starting track: ", seq[0]);

    printf("Enter sequence of tracks to seek: ");
    FOR_CYL
    {
        scanf("%d", &(seq[i]));
    } // end for

    FOR_CYL
    {
        if (seq[i] > seq[0])
        {
            hc++;
            // PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
            seq_high = (int *)realloc(seq_high, hc * sizeof(int));
            seq_high[hc - 1] = seq[i];
            // printf(" \t%d\t\n ", seq_high[hc-1]);
        }
        else
        {
            lc++;
            // PHY_MEM = (bl *)realloc(PHY_MEM, amt * sizeof(bl));
            seq_low = (int *)realloc(seq_low, lc * sizeof(int));
            seq_low[lc - 1] = seq[i];
            // printf(" \t%d\t\n ", seq_low[hc-1]);
        }

    } // end for

   

    seq_low_copy = (int *)malloc(lc * sizeof(int));
    for (int i = 0; i < lc; i++)
    {
        seq_low_copy[i] = seq_low[i];
    }

    sort();

}

void print_trav()
{
    printf(" %d", traversal[0]);
    FOR_CYL
    {
        printf(" %d", traversal[i]);
    }
    printf("\n");
}

void fifo()
{
    int distance = 0;
    FOR_CYL
    {
        seq_bool[i] = false;
    }
    seq_bool[0] = true;
    traversal[0] = seq[0];
    while (!(all_seq()))
    {
        FOR_CYL
        {
            if (seq_bool[i] == false)
            {
                distance += ABS_VAL(seq[i] - seq[i - 1]);
                traversal[i] = seq[i];
                seq_bool[i] = true;

            } // end if
        }     // end_for
    }         // end_while
    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);
} // the disk movement is the ABS_VAL(terminal - initial)

int findShortestIndex(int seq_count)
{
    int shortest = INT_MAX;
    seq_bool[0] = true;
    int ret_index;
    FOR_CYL
    {
        // if ((ABS_VAL(traversal[seq_count-1] - seq[i]) < shortest && seq_bool[i] == false)) {printf("TRUE CASE %d\n", i);}
        ret_index = (ABS_VAL(traversal[seq_count - 1] - seq[i]) < shortest && seq_bool[i] == false) ? i : ret_index;
        shortest = (seq[i] < shortest && seq_bool[i] == false) ? ABS_VAL(traversal[seq_count - 1] - seq[i]) : shortest;
    }

    seq_bool[ret_index] = true;

    // printf("\t\t%d\n", ret_index);
    return ret_index;
}

void stf()
{
    int distance = 0;
    int seq_count = 1;
    FOR_CYL
    {
        seq_bool[i] = false;
    }
    traversal[0] = seq[0];
    seq_bool[0] = true;
    while (!(all_seq()))
    {

        traversal[seq_count] = seq[findShortestIndex(seq_count)];
        distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
        seq_count++;
        // print_trav();

    } // end while

    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);
}
/*
int closestIndex(bool direction) {
      int dist = INT_MAX;
    seq_bool[0] = true;
    int ret_index;

    if (direction == false) {
         FOR_CYL
    {
      //if ((ABS_VAL(traversal[seq_count-1] - seq[i]) < shortest && seq_bool[i] == false)) {printf("TRUE CASE %d\n", i);}
        ret_index = (seq[i] < seq[0] && ABS_VAL(seq[0] - seq[i]) < dist  &&  seq_bool[i] == false) ? i : ret_index;
        dist = (seq[i] < seq[0] && ABS_VAL(seq[0] - seq[i]) < dist  &&  seq_bool[i] == false) ? ABS_VAL(seq[0] - seq[i])  : dist;
    }//end for
    }//end if

if (direction == true) {
         FOR_CYL
    {
      //if ((ABS_VAL(traversal[seq_count-1] - seq[i]) < shortest && seq_bool[i] == false)) {printf("TRUE CASE %d\n", i);}
        ret_index = (seq[i] > seq[0] && ABS_VAL(seq[i] - seq[0]) < dist  &&  seq_bool[i] == false) ? i : ret_index;
        dist = (seq[i] > seq[0] && ABS_VAL(seq[i] - seq[0]) < dist  &&  seq_bool[i] == false) ? ABS_VAL(seq[i] - seq[0])  : dist;
    }//end for
    }//end if




    seq_bool[ret_index] = true;

   // printf("\t\t%d\n", ret_index);
    return ret_index;

}*/

void scan()
{
    // increase
    // check if number is a cylinder
    // if it is, put in traversal[seq_count]
    // seq_count++
    // seq_bool[]

    INT_INPUT("Enter initial direction: (0=decreasing, 1=increasing): ", direction);

    int distance = 0;
    int seq_count = 1;
    FOR_CYL
    {
        seq_bool[i] = false;
    }
    FOR_CYL
    {
        traversal[i] = -1;
    }
    traversal[0] = seq[0];
    seq_bool[0] = true;

    if (direction == 0)
    {
        for (int i = lc - 1; i > -1; i--)
        {
            traversal[seq_count] = seq_low_copy[i];
            distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
            seq_count++;
        }

        for (int i = 0; i < hc; i++)
        {
            traversal[seq_count] = seq_high[i];
            distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
            seq_count++;
        }
    }
    else if (direction == 1)
    {
        for (int i = 0; i < hc; i++)
        {
            traversal[seq_count] = seq_high[i];
            distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
            seq_count++;
        }
        for (int i = lc - 1; i > -1; i--)
        {
            traversal[seq_count] = seq_low_copy[i];
            distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
            seq_count++;
        }
    }

    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);
} // start a point, go to the 0 direction or bigger dierction and if a service is required their service it, then go the other way

void c_scan()
{

    int distance = 0;
    int seq_count = 1;
    FOR_CYL
    {
        seq_bool[i] = false;
    }
    FOR_CYL
    {
        traversal[i] = -1;
    }
    traversal[0] = seq[0];
    seq_bool[0] = true;

    for (int i = 0; i < hc; i++)
    {
        traversal[seq_count] = seq_high[i];
        distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
        seq_count++;
    }
    for (int i = 0; i < lc; i++)
    {
        traversal[seq_count] = seq_low_copy[i];
        distance += ABS_VAL(traversal[seq_count] - traversal[seq_count - 1]);
        seq_count++;
    }

    printf("Traversed sequence:");
    print_trav();
    printf("The distance of the traversed tracks is: %d\n", distance);

} // start at a point, go towards the end of the disk, when end reached, return to 0 to get cyliders before starting point

void quit()
{
    /*

int *seq, *traversal, size, big_val = 0;
bool *seq_bool, direction;
int *seq_low, *seq_high, lc = 0, hc = 0, *seq_low_copy;

    */
    seq = NULL;
    traversal = NULL;
    seq_bool = NULL;
    seq_low = NULL;
    seq_low_copy = NULL;
    seq_high = NULL;
    free(seq);
    free(traversal);
    free(seq_bool);
    free(seq_low);
    free(seq_high);
    free(seq_low_copy);

    printf("Quitting program...\n");
}

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
        printf("4) Calculate distance to traverse tracks using Scan\n");
        printf("5) Calculate distance to traverse tracks using C-Scan\n");
        printf("6) Quit program and free memory\n\n");
        INT_INPUT("Enter selection: ", c);
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
6
8
3 6 4 7 10
2
3
4
1
4
0
5
6

1
10
123
154 200 89 111 54 342 1 999 32
2
3
4
1
4
0
5
6





*/