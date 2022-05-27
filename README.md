# Kyeou-C
C lab simluations for Operating Systems

# Lab 1:
Objective:
To simulate process creation and destruction when implemented with linked lists.
Specification:
The program creates/destroys child processes based on choosing from a menu of choices, where each
choice calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Create a new child process
3) Destroy all descendants of a process
4) Quit program and free memory
Assignment:
• Create a process creation hierarchy as a dynamic array of length n which references the process
control blocks (PCBs), indexed 0 to n-1\
• Each PCB is a structure consisting of two fields:\
o parent: a PCB index corresponding to the process’ creator\
o children: a pointer to a linked list, where each node contains the PCB index of one child
process and a link to the next child in the list\
• The necessary functions are simplified as follows:\
o create() represents the create function, which prompts for the parent process PCB[p]. The
function creates a new child process PCB[q] of process PCB[p] by performing the following
tasks:\
▪ allocate a free PCB[q]\
▪ record the parent's index, p, in PCB[q]\
▪ initialize the list of children of PCB[q] as empty (NULL)\
▪ create a new link containing the child's index q and append the link to the linked list
of PCB[p]\
o destroy() represents the destroy function, which prompts for the parent process PCB[p]. The
function recursively destroys all descendent processes (child, grandchild, etc.) of process
PCB[p] by performing the following tasks: for each element q on the linked list of children of
PCB[p]:\
▪ destroy(q) /* recursively destroy all descendants */\
▪ free PCB[q]\
▪ deallocate the element q from the linked list

# Lab 2:
Objective:
To calculate the timing parameters of batch processes based on different scheduling algorithms.
Specification:
The program mimics the execution of different processes under different scheduling algorithms.
The simulation maintains a table that reflects the current state of the system, based on choosing
from a menu of choices, where each choice calls the appropriate procedure, where the choices
are:
1) Enter parameters
2) Schedule processes with FIFO algorithm
3) Schedule processes with SJF algorithm
4) Schedule processes with SRT algorithm
5) Quit program and free memory
Assignment:
• Create a table to record the status of different processes based on the following parameters:\
o id: the unique identifier of the process\
o arrival: the point in time when the process enters the ready list to be executed by the
CPU\
o total_cpu: the amount of CPU time the process will consume between arrival and
departure\
o total_remaining: the amount of CPU time remaining for a process to complete {used
for SRT scheduling only}\
o done: a flag that indicates whether the process has been successfully completed (1) or
not (0)\
o start_time: the time when the process has begun being executed by the CPU\
o already_started: a flag that indicated whether the process has already begun (1) or
not (0) {used for SRT scheduling only}\
o end_time: the time when the process has been completed by the CPU\
o turnaround_time: the sum of the total CPU time and the waiting time (alternatively:
the difference between the end time and the arrival time)\
• Calculate the values for the start_time, end_time, and turnaround_time for each process
based on the selected scheduling algorithm.

# Lab 3:
Objective:
To implement resource allocation and demonstrate deadlock avoidance using the Banker's
algorithm.
Specification:
The program simulates resource allocation to requesting processes and demonstrates deadlock
avoidance with the Banker's algorithm. A menu controls the operations, and each choice calls
the appropriate procedure, where the choices are:
1) Enter parameters
2) Run the Banker's algorithm to determine a safe sequence
3) Quit program and free memory
Assignment:
 The program uses a claim graph consisting of processes, multi-unit resources, request edges,
allocation edges, and claim edges to represent the state of allocated resources to processes.
 The graph can be represented by a set of arrays/vectors:
o Resource vector: an m-element vector, where m is the number of resources and each
entry resource[j] records the total number of units of resource j.\
o Available vector: an m-element vector, where m is the number of resources and each
entry available[j] records the number of units of resource j that are available.\
o Max claims array: an nxm-element array, where m is the number of resources and n is
the number of processes, and each entry maxclaim[i][j] contains an integer that
records the maximum number of units of resource j that process i may ever request.\
o Allocation array: an nxm-element array, where m is the number of resources and n is
the number of processes, and each entry allocation[i][j] contains an integer that
records the number of units of resource j that process i has actually been allocated.\
o Need array: an nxm array, where m is the number of resources and n is the number of
processes, and each entry need[i][j] contains an integer that records the number of
units of resource j that process i may need in the future.

# Lab 4:
Objective:
To simulate memory allocation with hole-fitting algorithms (First-fit, Best-fit) and
implement deallocation and defragmentation of memory blocks.
Specification:
The program simulates memory allocation with a chosen hole-fitting algorithm (First-fit,
Best-fit) and implements deallocation and defragmentation. A menu controls the
operations, and each choice calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Allocate memory for a block
3) Deallocate memory for a block
4) Defragment memory
5) Quit program and free memory
Assignment:
• The size of physical memory is represented by an integer pm_size.\
• The allocated blocks are contained within a linked list, where each allocated block is
a structure containing: (1) the id, (2) the starting address of the block, (3) the ending
address of the block, and (4) a link to the next allocated block.\
• Each allocation request prompts for: (1) the id and (2) the size of the new block. If the
id is a duplicate and/or the remaining physical memory is not enough to fit the
request, the request is rejected, and an appropriate message is displayed.\
• Each deallocation request prompts for the id. If the id is invalid, the request is
rejected.\
• Defragmentation compacts the blocks to be contiguous, and coalesces the holes into
one hole at the far--right end (highest memory addresses) of physical memory.

# Lab 5:
Objective:
• To compare the performance of disk scheduling algorithms:
First-in-first-out (FIFO), Shortest-seek-time-first (SSTF), Scan, and C-Scan.
Specification:\
• The program compares the disk scheduling algorithms: First-in-first-out (FIFO), Shortest-
seek-time-first (SSTF), Scan, and C-Scan in terms of traversing a set of tracks input by
the user, and calculates the total distance of the tracks traversed.\
• A menu controls the operations, and each choice calls the appropriate procedure, where
the choices are:
1) Enter parameters
2) Calculate distance to traverse tracks using FIFO
3) Calculate distance to traverse tracks using SSTF
4) Calculate distance to traverse tracks using Scan
5) Calculate distance to traverse tracks using C-Scan
6) Quit program and free memory
Assignment:
• For a sequence of size m, a disk scheduling algorithm accepts a starting track followed by
a sequence of m-1 integers, where each index value t is a request to seek track t.\
• Each scheduling algorithm generates an ordering according to which the m-1 requests are
serviced from the starting track and calculates the distance of the tracks traversed.
