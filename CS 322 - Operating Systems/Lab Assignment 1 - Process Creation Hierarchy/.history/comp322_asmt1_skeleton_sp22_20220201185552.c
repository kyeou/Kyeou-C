#include <stdio.h>
#include <stdlib.h>

/* Define structures and global variables*/


int numOfProcs;
struct node {
	int parent;
	int child;

} *PCB = NULL;

//Case sensitive...........
typedef struct node pcb;
//From now on, PCB is the variable, pcb is the type.

/***************************************************************/
/*PROCEDURE TO PRINT HIERARCHY OF PROCESSES*/
void  printProcs() {
	/* declare local vars */
/*
	/* for each PCB index i from 0 up to (but not including) maximum number*/	
	for (int i = 0; i < numOfProcs; i++) {
		printf("%d", i);
		if (PCB[i].parent != -1) {
			printf("\t%d", PCB[i].parent);
		} else { 
		printf("\t");
		}
		if (PCB[i].child != -1) {
			printf("\t%d", PCB[i].child);
		} else {
			printf("\t")
		} printf("\n")
	}
		/* check if PCB[i] has a parent and children */
			/* print message about children of the current PCB[i] */
			/* intilize variable to head of list of children */
					
			/* while the end of the linked list of children is not reached */ 				
				/* print message about current child process index */
				/* move to next node in linked list */
			/* while */
			/* print newline */
		/* if */
	 /* for */

} /* end of procedure */

/***************************************************************/
/*PROCEDURE FOR OPTION #1*/ 
void option1() {
	/* declare local vars */
	/* prompt for maximum number of processes */
	/* allocate memory for dynamic array of PCBs */
	/* Define PCB[0] */
	/* for-loop to intitialize all other indices' parent to -1 */
printf("Enter maximum number of processes: ");
scanf("%d", &numOfProcs);
PCB = (pcb*)malloc(numOfProcs*sizeof(pcb));
PCB[0].parent = 0;
PCB[0].child = -1;
for (int a = 0; a < numOfProcs; a++) {
	p[a].parent = -1;
	p[a].child = -1;
}


	return;
} /* end of procedure */

	
/***************************************************************/
//"PROCDURE FOR OPTION #2"
void create() {
	/* define local vars */
	/* prompt for parent process index p */
	/* search for first available index q without a parent in a while loop */
	/* allocate memory for new child process, initilize fields */
	/* record the parent's index p in PCB[q] */
	/* initialize the list of children of PCB[q] as empty */
	/* create a new link containing the child's index q and append the link to the end of the linked list of PCB[p] */
	/* call procedure to print current hierachy of processes */
	

	int par, newC = 1, newLink, numC = 0;
printf("Enter the parent process index: ");
scanf("%d", par);

	
	
	//newC is to be incremented if PCB[newC]'s has a parent, finding an empty index
	while (PCB[newC].parent != -1) {
		newC++;
	}
	 //record parent
	 PCB[newC].parent = par;
	 PCB[newC].child = -1;
	if (PCB[par].child == -1) {
		PCB[par].child = newC;
		//Should set equal to 1 as no other case is possible if this if-stat is true
		numC = 1;
	} else {
		//if else is reached, numC should be 2
		numC = 2;
		//newLink, the index of the next child, should be with the child of par
		newLink = PCB[par].child;
		while (PCB[newLink].child != -1) {
			newLink = PCB[newLink].child;
			//Increment numC from this point
			numC++;
		}
		PCB[newLink].child = newC;
		PCB[newC].child = newLink;
	}
printProcs();
	return;
} /* end of procedure */


/***************************************************************/
void destroy(int q) {
	/* declare local vars */
	/* check if end of linked list--if so return */
	/* else call self on next node in linked list */
		/* set variable q to current node's process index field */
		/* call self on children of PCB[q] */ 	
		/* free memory of paramter */		
		/* reset parent of PCB[q] to -1 */
		/* set paramter to NULL */
	 /* end of else */
		if (q == -1) {
		return;

	} else {
		destroy(PCB[q].child);
		printf("PCB[%d]\t\n", q);
		PCB[q].parent = -1;
		PCB[q].child = -1;
	}
	return;
} /* end of procedure */


/***************************************************************/

//should be recursive
//option 3
void destroyer() {
	/* declare local vars */
	/* prompt for process index p */
	/* call recursive procedure to destroy children of PCB[p] */
	/* reset children of PCB[p] to NULL */
	/* call procedure to print current hierarchy of processes */
int par;
printf("Enter the index of the process whose descendants are to be destroyed: ");
    scanf("%d", &par);
destroy(PCB[par].child);
PCB[par].child = NULL;

printProcs();

} /* end of procedure */


/***************************************************************/
//"PROCEDURE FOR OPTION #4"
void quit() {
	/* check if PCB is non null
		/* check if children of PCB[0] is not null */
			/* call recursive procedure to destroy children of PCB[0] */
		 /* if */
	/* free memory of PCB */
	/* if */


if (PCB != NULL) {
	free(PCB);
}


	return;
} /* end of procedure */


/***************************************************************/
int main() {
	/* declare local vars */
	/* while user has not chosen to quit */
		/* print menu of options */
		/* prompt for menu selection */
		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */	
	 /* while loop */

  int choice;
    while (choice != 4)
    {
        printf("Process creation and destruction\n");
        printf("--------------------------------\n");
        printf("1) Enter parameters\n");
        printf("2) Create a new child process\n");
        printf("3) Destroy all descendants of a process\n");
        printf("4) Quit program and free memory\n\n");
        printf("Enter selection: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            option1();
        }
        else if (choice == 2)
        {
            create();
            printr();
        }
        else if (choice == 3)
        {
            destroyer();
            printC();
        }
        else if (choice == 4)
        {
            quit();
        }
    }


	 return 1; /* indicates success */
} /* end of procedure */