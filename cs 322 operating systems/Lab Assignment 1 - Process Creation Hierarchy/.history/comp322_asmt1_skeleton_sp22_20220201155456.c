#include <stdio.h>
#include <stdlib.h>

/* Define structures and global variables*/

/***************************************************************/
void "PROCEDURE TO PRINT HIERARCHY OF PROCESSES"() {
	/* declare local vars */

	/* for each PCB index i from 0 up to (but not including) maximum number*/	
		/* check if PCB[i] has a parent and children */
			/* print message about children of the current PCB[i] */
			/* intilize variable to head of list of children */
					
			/* while the end of the linked list of children is not reached */ 				
				/* print message about current child process index */
				/* move to next node in linked list */
			} /* while */
			/* print newline */
		}/* if */
	} /* for */
} /* end of procedure */

/***************************************************************/
void "PROCEDURE FOR OPTION #1"() {
	/* declare local vars */
	/* prompt for maximum number of processes */
	/* allocate memory for dynamic array of PCBs */
	/* Define PCB[0] */
	/* for-loop to intitialize all other indices' parent to -1 */
	return;
} /* end of procedure */

	
/***************************************************************/
void "PROCDURE FOR OPTION #2"() {
	/* define local vars */
	/* prompt for parent process index p */
	/* search for first available index q without a parent in a while loop */
	/* allocate memory for new child process, initilize fields */
	/* record the parent's index p in PCB[q] */
	/* initialize the list of children of PCB[q] as empty */
	/* create a new link containing the child's index q and append the link to the end of the linked list of PCB[p] */
	/* call procedure to print current hierachy of processes */
	return;
} /* end of procedure */


/***************************************************************/
void "RECURSIVE PROCEDURE TO DESTROY CHILDREN PROCESSES"(parameter) {
	/* declare local vars */
	/* check if end of linked list--if so return */
	/* else call self on next node in linked list */
		/* set variable q to current node's process index field */
		/* call self on children of PCB[q] */ 	
		/* free memory of paramter */		
		/* reset parent of PCB[q] to -1 */
		/* set paramter to NULL */
	} /* end of else */
	return;
} /* end of procedure */


/***************************************************************/
void "PROCEDURE FOR OPTION #3"() {
	/* declare local vars */
	/* prompt for process index p */
	/* call recursive procedure to destroy children of PCB[p] */
	/* reset children of PCB[p] to NULL */
	/* call procedure to print current hierarchy of processes */
	return;
} /* end of procedure */


/***************************************************************/
void "PROCEDURE FOR OPTION #4"() {
	/* check if PCB is non null)
		/* check if children of PCB[0] is not null */
			/* call recursive procedure to destroy children of PCB[0] */
		} /* if */
	/* free memory of PCB */
	} /* if */
	return;
} /* end of procedure */


/***************************************************************/
int main() {
	/* declare local vars */
	/* while user has not chosen to quit */
		/* print menu of options */
		/* prompt for menu selection */
		/* call appropriate procedure based on choice--use switch statement or series of if, else if, else statements */	
	} /* while loop */
	 return 1; /* indicates success */
} /* end of procedure */