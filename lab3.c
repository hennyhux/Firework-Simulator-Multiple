/*Author: Henry Zhang*/

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
#include "libfire.h"
#include "debug.h"
#include "linkedlist.h"



/*Main function*/
int main()
{
	/*Get the time at the start of the program*/
	double timeStart = now();

	/*Initalize*/
	if (TEXT || (GRAPHICS && fw_initialize()))
	{
		/*Run Data to began processing*/
		data();	
		if(GRAPHICS)fw_teardown();
		printf("Total runtime is %.9lf seconds\n" , now() - timeStart);
	}

	else printf("Graphics failed to initalize, exiting now\n runTime: %f", now() - timeStart);	

	return 0;
}

/*High level details, owns the sim loop, initialize as many structs as needed*/
void data()
{
	/*Simulation structure for data()*/
	struct Simulation sim = {NULL, 0, 0};
	struct MemoryCount memoryCount= {0, 0}; 
	int itemRead = 0;
	read(&sim, &memoryCount, itemRead);
}


/*Each fireworks read gets copied into list*/
void read(struct Simulation *simPtr, struct MemoryCount *memoryCount, int itemRead)
{

	/*read() owns a bunch of local variables, one of which is a Firework struct + derivatives*/
	struct Firework firework, fireworkCopy, *fireworkPtr = &firework, *fireworkPtrCopy = &fireworkCopy, *dtptr;
	struct MemoryCount *memoryCountPtr = memoryCount; 
		
	/*set the struct Simulation pointer inside of Firework struct to point at simulation struct*/
	fireworkPtr->sim = simPtr; 	
	itemRead = scanf(" %lf %X %lf %lf %lf %lf \n", &fireworkPtr->launchTime, &fireworkPtr->code, &fireworkPtr->fuseTime,
                  &fireworkPtr->X, &fireworkPtr->XV, &fireworkPtr->YV);

	/*Scanf loop to read in values into local Firework struct*/
	while (itemRead != -1 && itemRead  == SIXITEMSONLY)
	{
		/*Dynamically allocate space for firework*/
		dtptr = (struct Firework *)allocateMemory(fireworkPtr, memoryCountPtr);
		
		/*Hands off the address of Firework struct and sim pointer to be added to the linked list*/
		cloneToList(dtptr, simPtr, firework);
		itemRead = scanf(" %lf %X %lf %lf %lf %lf \n", &fireworkPtr->launchTime, &fireworkPtr->code, &fireworkPtr->fuseTime,
                   &fireworkPtr->X, &fireworkPtr->XV, &fireworkPtr->YV);
	}
	
	if (some(simPtr->p2Head, listEmpty))enterSim(dtptr, memoryCount);
	printf("\nDone reading, scanf returned %d \n", itemRead);
}


/*Clone Firework structs and add them into a linked list*/
void cloneToList(struct Firework *dtptr, struct Simulation *simPtr, struct Firework firework)
{
	int insertSucessful = 0;
	*dtptr = firework;	
	if(TEXT)insertSucessful = insert(&simPtr->p2Head, dtptr, launchOrder, 1);
	if(GRAPHICS)insertSucessful = insert(&simPtr->p2Head, dtptr, launchOrder, 0);
	if (!insertSucessful)
	{
		printf("ERROR: lab3.c: cloneToList: Failed to insert firework! Freeing firework now \n");
		free(dtptr);
	}
}


/*Determines how to simulate the fireworks based on debug.h*/
void enterSim(struct Firework *firework, struct MemoryCount *memoryCount)
{
	/*First paramter not needed*/
	if (TEXT)textMode(firework->sim, firework, memoryCount);
		
	if (GRAPHICS)graphicsMode(firework->sim, firework);

}



