/*Author: Henry Zhang*/

#include <stdio.h>
#include <stdlib.h>
#include "lab3.h"
#include "libfire.h"
#include "debug.h"
#include "linkedlist.h"


/*Lets allocate some dynamic memory, returns address of memory location*/
void *allocateMemory(struct Firework *firework, struct MemoryCount *memoryCount)
{
	struct MemoryCount *memoryCountPtr = memoryCount;
	struct Firework *copyFireworkPtr;
	if(TEXT)printf("DIAGNOSTIC: Allocating space for code %X. ", firework->code);
	copyFireworkPtr = (struct Firework *)malloc(sizeof(struct Firework));
	if (copyFireworkPtr != NULL)
	{
		(memoryCountPtr->structsAllocated)++;
		if(TEXT)printf("%d Allocated\n" , memoryCountPtr->structsAllocated);

	}
	if (copyFireworkPtr == NULL)printf("ERROR: memory.c: allocateMemory: Something done goofed! malloc() returned null!");
	return copyFireworkPtr;

}

/*Deallocate memory, hopefully it doesnt blow up*/
void deallocateMemory(void *data)
{
	struct Firework *firework = data;
	if(TEXT)printf("DIAGNOSTIC: Freeing firework code %X. ", firework->code);
	free(firework);

}









