// written by christian jarmon

#include <stdio.h>
#include <stdlib.h>

int numOfProcs;
struct node
{
	int parent;
	int *child;

} *PCB = NULL;

// Case sensitive...........
typedef struct node pcb;
// From now on, PCB is the variable, pcb is the type.

/***************************************************************/
/*PROCEDURE TO PRINT HIERARCHY OF PROCESSES*/
void printProcs()
{

	/* Should print like so
PCB[0] is the parent of: PCB[1]  PCB[2]
PCB[2] is the parent of: PCB[3]
//for i
//while
//see if parent has child, if it does, get the index of the child, and see if that has a child
//and so on


	*/
	 printf("PRINTING SHIT\n");
	for (int i = 0; i < numOfProcs - 1; i++)
	{
		if (PCB[i].child != NULL)
		{
			// printf("\tPCB[%d]", *(PCB[i].child));
			printf("PCB[%d] is the parent of: ", i);
			for (int a = 0; a < numOfProcs; a++)
			{
				if (PCB[a].parent == i)
				{
					if (a != i)
					{
						//printf("\tCHILD FOUND\t");
						printf("PCB[%d]\t", a);
					}
				}
			}

			printf("\n");
		} // if ends
	}	  // end for
	printf("\n");
} /* end of procedure */

/***************************************************************/
/*PROCEDURE FOR OPTION #1*/
void entParms()
{

	printf("Enter maximum number of processes: ");
	scanf("%d", &numOfProcs);
	// printf("\nNUMS OF PROCS SCANNED %d\n", numOfProcs);
	PCB = (pcb *)malloc(numOfProcs * sizeof(pcb));
	PCB[0].parent = 0;
	PCB[0].child = NULL;
	printf("\nFOR REACHED\n");
	for (int m = 1; m < numOfProcs; m++)
	{
		// printf("\nSETTING ALL CHILDREN ---> %d\n", m);
		PCB[m].parent = -1;
		PCB[m].child = NULL;
		//printf("\n%d done\n", m);
	}
	printf("\nPARMS ENT DONE\n");
	return;
} /* end of procedure */

/***************************************************************/
//"PROCDURE FOR OPTION #2"
void create()
{

	int par, newC = 1, newLink;
	printf("Enter the parent process index: ");
	scanf("%d", &par);

	// newC is to be incremented if PCB[newC] has a parent, finding an empty index
	while (PCB[newC].parent != -1)
	{
		//printf("\nIN THE WHILE LOOP\n");
		newC++;
		//printf("newC has been ++");
	}
	// record parent
	PCB[newC].parent = par;
	PCB[newC].child = NULL;
	/* create a new link containing the child's index q and append the
link to the end of the linked list of PCB[par] */
//run through the parents children, find the child with the biggest index, set the child of that one
//to the newLink
	// loop through the possible children of par, if one of the children, doesnt have a child, newC becomes that child
	//printf("\nPARENT RECORDED\n");
	if (PCB[par].child == NULL)
	{
		//printf("\nIF REACHED\n");
		(PCB[par].child) = (int*)malloc(sizeof(int));
		*(PCB[par].child) = newC;
		//printf("PCB[%d] now has a child\n", par);
	}
	else
	{
		/printf("\nELSE REACHED\n");

		// newLink, the index of the next child, should be with the child of par
		newLink = *(PCB[par].child);
		while (PCB[newLink].child != NULL)
		{
			//printf("\nWHILE REACHED ---- %d\n", newLink);
			newLink = *(PCB[newLink].child);
		} 
	}

	printProcs();
	return;
} /* end of procedure */

/***************************************************************/
// this gets rid of the children
void destroy(int *child)
{
	int a;
	if (PCB[*child].child == )
	{
		return;
	}
	else
	{
		destroy(PCB[*child].child);
		free(child);
		PCB[*child].parent = -1;
		child = NULL;
		/*
		a = PCB[(q.parent)].child;
		destroy(PCB[a]);
		q = 0;
		q.parent = -1;
		q = NULL;
		*/
	}
	return;
} /* end of procedure */

/***************************************************************/
// find the index in PCB given a child
/*
int findParm(int child) {
	//int a = *(q.child);
	int b = PCB[child].parent;
	for (int i = 0; i < numOfProcs; i++) {
		if (PCB[i].parent == b) {
			return i;
		}
	}
	return -1;
}
*/

// should be recursive
// option 3
void destroyer()
{
	if (PCB != NULL)
	{
		int par;
		printf("Enter the index of the process whose descendants are to be destroyed: ");
		scanf("%d", &par);
		if (PCB[par].child != NULL)
		{
			destroy(PCB[par].child);
		}
		PCB[par].child = NULL;
	}
	return;
	printProcs();

} /* end of procedure */

/***************************************************************/
//"PROCEDURE FOR OPTION #4"
void quit()
{

	if (PCB != NULL)
	{
		if (PCB[0].child != NULL)
		{
			destroy(PCB[0].child);
		}
		free(PCB);
		printf("PCB Freed");
	}

	return;
} /* end of procedure */

/***************************************************************/
int main()
{

	int c;
	while (c != 4)
	{
		printf("\nProcess creation and destruction\n");
		printf("--------------------------------\n");
		printf("1) Enter parameters\n");
		printf("2) Create a new child process\n");
		printf("3) Destroy all descendants of a process\n");
		printf("4) Quit program and free memory\n\n");
		printf("Enter selection: ");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			entParms();

			break;
		case 2:
			create();

			break;
		case 3:
			destroyer();
			break;

		case 4:
			quit();
			break;
		default:
			printf("not a choice");
		} // switch ends
	}	  // while ends

	printf("End\n");
	return 1; /* indicates success */
} /* end of procedure */