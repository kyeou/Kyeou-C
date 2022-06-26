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
    printf(msg);            \
    scanf("%d", &var)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int numProcs, cycles = 0;

struct process
{
    int *id, avl, total_cpu, tot_rem, start_t, end_t, ta_time;
    bool done, start_b;
} *PB = NULL;

// note: if start_t is NULL, its not scheduled, use boolean start_b if need be

typedef struct process pb;

void prt()
{
    printf("ID      Arrival Total   Start   End     Turnaround\n");
    printf("--------------------------------------------------\n");
    for_proc
    {
        if (PB[b].id != NULL)
        {
            printf("%d\t", *(PB[b].id));
            printf("%d\t", PB[b].avl);
            printf("%d\t", PB[b].total_cpu);
            //printf("%d\t %d\t %d\t", *(PB[b].id), PB[b].avl, PB[b].total_cpu);
            if (PB[b].done != 0)
            {
                printf("%d\t", PB[b].start_t);
                printf("%d\t", PB[b].end_t);
                printf("%d\t", PB[b].ta_time);
            } // nest if ends
            printf("\n");
        }
    }
} // end print

void entParms()
{
    // printf("Enter total number of processes: ");
    // scanf("%d", &numProcs);
    int_input("Enter total number of processes: ", numProcs);
    PB = (pb *)malloc(numProcs * sizeof(pb));
    // printf("%d\n", sizeof(PB));
    for (int b = 0; b < numProcs; b++)
    {
        int z;
        printf("Enter process id: ");
        scanf("%d", &z);
        // int_input( int z; "Enter process id: ", z)
        PB[b].id = (int *)malloc(sizeof(int));
        *(PB[b].id) = z;
        // printf("curr id %d\n", *(PB[b].id));
        printf("Enter arrival cycle for process P[%d]: ", *(PB[b].id));
        scanf("%d", &(PB[b].avl));
        // printf("curr avl %d\n" , PB[z].avl);
        printf("Enter total cycles for process P[%d]: ", *(PB[b].id));
        scanf("%d", &(PB[b].total_cpu));
        PB[b].done = 0;
        // printf("curr tot cpu %d\n" , PB[z].total_cpu);
    }

    printf("\n");

    prt();

} // end of entparms

// return a boolean false if everything is scheduled, returns true if something is not scheduled
bool checkSchedule()
{
    int c = 0;
    while (true)
    {
        if (c == numProcs)
        {
            return false;
        }
        if (PB[c].done == 0)
        {
            return true;
        }
        c++;
    } // end while
} // end func

//------------------------------------------------------------------

// returns the earliest process not already done
pb *currNS()
{

    pb *earliest;
    earliest = (pb *)malloc(sizeof(pb));
    earliest->avl = INT_MAX;
/
    for_proc
    {
        if (PB[b].avl < earliest->avl && PB[b].done == 0)
        {
            earliest = &PB[b];
        }
    } // end for
    return earliest;
} // end of process

void fifo()
{
    // point of start for any process is the current cycle time
    // take the process with earliest arrival time that has not been done
    //     take the total cycle time of that process, ---> arrival time + cycle time of process = end time\
    //set done flag of current process to 1
    // cycle time += end time
    // if not at PB[numProcs], PB[next process].start = current time
    cycles = 0;

    for_proc
    {
        PB[b].done = 0;
    }

    while (checkSchedule())
    {
        currNS()->start_t = cycles;
        currNS()->end_t = currNS()->start_t + currNS()->total_cpu;
        currNS()->ta_time = currNS()->end_t - currNS()->avl;
        cycles += currNS()->total_cpu;
        currNS()->done = 1;
    }
    prt();
} // end fifo

//-------------------------------------------------------------------

pb *currSJ()
{
    pb *shortest;
    shortest = (pb *)malloc(sizeof(pb));
    shortest->total_cpu = INT_MAX;

   
    for_proc
    {
        if (PB[b].total_cpu < shortest->total_cpu && PB[b].avl <= cycles && PB[b].done == 0)
        {
            shortest = &PB[b];
        }
    } // end for
    return shortest;
} // end of process

void sjf()
{
    // orders from smallest to largest turnaround
    cycles = 0;
    // int curr_star = cycles;

    for_proc
    {
        PB[b].done = 0;
    }

    while (checkSchedule())
    {
        pb *curr = currSJ();
        curr->start_t = cycles;
        curr->end_t = curr->start_t + curr->total_cpu;
        curr->ta_time = curr->end_t - curr->avl;
        cycles += curr->total_cpu;
        curr->done = 1;
    }
    prt();
}

pb *currSRT()
{
    pb *shortest;
    shortest = (pb *)malloc(sizeof(pb));
    shortest->tot_rem = INT_MAX;

    for_proc
    {
        if (PB[b].tot_rem < shortest->tot_rem && PB[b].avl <= cycles && PB[b].done == 0)
        {
            shortest = &PB[b];
        }
    } // end for
    return shortest;
} // end currSRT

void srt()
{

    cycles = 0;
    for_proc
    {
        PB[b].done = PB[b].start_b = 0;
        PB[b].tot_rem = PB[b].total_cpu;
    } // end for

    while (checkSchedule())
    {
        pb *cSRT = currSRT();
        if (cSRT->start_b == 0)
        {
            cSRT->start_t = cycles;
            cSRT->start_b = 1;
        } // end if

        cSRT->tot_rem--;
        cycles++;

        if (cSRT->tot_rem == 0)
        {
            cSRT->end_t = cycles;
            cSRT->ta_time = cSRT->end_t - cSRT->avl;
            cSRT->done = 1;
        }
        // printf("\nID            -->> %d -- %d %d %d\n" ,*(cSRT->id) ,*(PB[0].id), *(PB[1].id), *(PB[2].id));
        // printf("START_T CHECK -->> %d %d %d\n", PB[0].start_t, PB[1].start_t, PB[2].start_t);
        // printf("TOT REM CHECK -->> %d %d %d\n", PB[0].tot_rem, PB[1].tot_rem, PB[2].tot_rem);
    } // while ends
    prt();
} // end srt

void quit()
{
    for_proc
    {
        PB[b].id = NULL;
        free(PB[b].id);
    }
    free(PB);
}

int main()
{
    int c;
    while (c != 5)
    {
        printf("\nBatch Scheduling\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Schedule processes with FIFO algorithm\n");
        printf("3) Schedule processes with SJF algorithm\n");
        printf("4) Schedule processes with SRT algorithm\n");
        printf("5) Quit and free memory\n\n");
        printf("Enter selection: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            entParms();
            break;
        case 2:
            fifo();
            break;
        case 3:
            sjf();
            break;
        case 4:
            srt();
            break;
        case 5:
            quit();
            break;
        default:
            printf("not a choice");
        }
    }

    return 1; /* indicates success */
}
