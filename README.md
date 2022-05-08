# Kyeou-C
c++ stuff

Lab 1:
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
control blocks (PCBs), indexed 0 to n-1
• Each PCB is a structure consisting of two fields:
o parent: a PCB index corresponding to the process’ creator
o children: a pointer to a linked list, where each node contains the PCB index of one child
process and a link to the next child in the list
• The necessary functions are simplified as follows:
o create() represents the create function, which prompts for the parent process PCB[p]. The
function creates a new child process PCB[q] of process PCB[p] by performing the following
tasks:
▪ allocate a free PCB[q]
▪ record the parent's index, p, in PCB[q]
▪ initialize the list of children of PCB[q] as empty (NULL)
▪ create a new link containing the child's index q and append the link to the linked list
of PCB[p]
o destroy() represents the destroy function, which prompts for the parent process PCB[p]. The
function recursively destroys all descendent processes (child, grandchild, etc.) of process
PCB[p] by performing the following tasks: for each element q on the linked list of children of
PCB[p]:
▪ destroy(q) /* recursively destroy all descendants */
▪ free PCB[q]
▪ deallocate the element q from the linked list

Lab 2:
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
• Create a table to record the status of different processes based on the following parameters:
o id: the unique identifier of the process
o arrival: the point in time when the process enters the ready list to be executed by the
CPU
o total_cpu: the amount of CPU time the process will consume between arrival and
departure
o total_remaining: the amount of CPU time remaining for a process to complete {used
for SRT scheduling only}
o done: a flag that indicates whether the process has been successfully completed (1) or
not (0)
o start_time: the time when the process has begun being executed by the CPU
o already_started: a flag that indicated whether the process has already begun (1) or
not (0) {used for SRT scheduling only}
o end_time: the time when the process has been completed by the CPU
o turnaround_time: the sum of the total CPU time and the waiting time (alternatively:
the difference between the end time and the arrival time)
• Calculate the values for the start_time, end_time, and turnaround_time for each process
based on the selected scheduling algorithm.
