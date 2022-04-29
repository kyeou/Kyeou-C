#include <stdio.h>
#include <stdlib.h>

#define forL(q, x, y, z) for (int q = x; q < y; q z)


int num_procs;
struct node
{
    int par;
    int *child;
} *pcb = NULL;

typedef struct node sPCB;

//print function
void printAll() {

}

//opt 1
void createParent() {
printf("enter max procs: ")
scanf("%d", &num_procs);
pcb = (sPCB*)malloc(num_procs * sizeof(sPCB));
pcb[0].parent = 0;
pcb[0].child = NULL;

forL (i, 1, num_procs - 1, ++) {
    pcb[i].parent = -1;
    pcb[i].child = NULL;
}//end of for

return;

} //end of opt 1

//opt 2
void create() {
int nParent, nChild = 1, nLink;
//the first new child should be 1 at the very beginning
printf("enter the parent: ");
scanf("%d", nParent);

while () //condition = while the index of nChild in pcb has no parent, increment nChild
{} //end while

//set position of in pcb of nChild's parent to nParent
//then set its child to NULL

if () //condition = if the nParent has no child -> allocation some space using technique similar to line 25 -> set nChild to child of nParent
{} //end of if
else {
    //what to do
    //this is what happens if nParent does indeed already have a linked child

    //nLink = the child of nChild
    while () //condition = child of nLink doesnt exist
    {} //set the child of nLink to pcb[nLink].child :)


printAll();
}//end of else


}//end of opt 2


//opt 3 
void destroyer() {
//lets make the destory function first

if () //if the list of parents is empty  -> hint: look at the end of the struct declaration
{
int a;
printf("which parent do we want to destroy: ");
scanf(); //scan the int a 

if () //condition -> parent of a in pcb is not empty
{} //call destory function for the child of a



}//end of big if

return;
printAll();



}//end of destroyer

//function for destroyer()

void destroy(int * c) { //parameter -> a child, in this case, i set it as a int* (like in the struct)

int r;

if () //condition = pcb[*c].child doesnt exist
{} //just return :)
else {
    //it must be recursive
    destroy(); //for the parameter -> call the the child of c
    free(c); //this is a freebie
    //set the the parent of pcb[*c] to -1
    //reset c -> hint: 4 letter word that starts with N :)
}

return;
}//end of destory

//opt 4
void quit() {

//check if pcb == NULL or not
//then check if the child of the first pcb is null not, this should only happen if the first cond is satisfied/not satisfied, ill leave that to you
//if condition is true that a child does exist
//call destory on that child

return;
printAll();


}

int main()
{
    int c;
    while (c != 4)
    {
        printf("\nproc cre and dest\n");
        printf("----------------------\n");
        printf("ent parms\n");
        printf("create proc\n");
        printf("create child\n");
        printf("dest all desc\n");
        printf("quit\n");
        printf("ent select: ");
        scanf("%d", &c);
        //using a switch might be better here
        switch (c) {
            //case #: call respective function
            //break;

            default: printf("not a choice\n"); 
        }//end of switch
    
    }//end of while
}


//VOILA :))))))))))))))))))))))))))))))))))))))))))))))))))))))))