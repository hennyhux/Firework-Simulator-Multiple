/*Author: Henry Zhang*/ 

/*Struct for a single firework*/
struct Firework{
	double launchTime;
	unsigned long int code;
	double fuseTime;
	double X;
	double XV;
	double YV;
	double Y;
	struct Simulation *sim;
};

/*Simulation struct*/
struct Simulation{
	void *p2Head;
  	double dt;
	double ET;

};

/*Struct that contains numbers of structs (de)allocated
are we allowed to have more than two structs? I dont see
anything in the lab write-up for it but I hope I am allowed 
to*/
struct MemoryCount{
	int structsAllocated;
	int structsDeallocated;
};

#define ONETHOUSAND 1000
#define ROUNDCONST 0.01
#define SIXITEMSONLY 6
#define TWOSECONDS 2
#define ONE 1

/*-----Function Declaration-----*/

/*Memory and linked-list functions*/
void *allocateMemory(struct Firework *firework, struct MemoryCount *memoryCount);
void deallocateMemory(void *data);


/*High-Level functions*/
void data();
void read(struct Simulation *simPtr, struct MemoryCount *memoryCount, int itemRead);
void enterSim(struct Firework *firework, struct MemoryCount *memoryCount);
void cloneToList(struct Firework *dtptr, struct Simulation *simPtr, struct Firework firework);


/*TEXT functions*/
void textMode(struct Simulation *simPtr, struct Firework *firework, struct MemoryCount *memoryCount);
void printTableHeader(struct Simulation *simPtr, struct Firework *firework);
void printTable(void *data);
void printFireworkExplode(void *data);
void printImpactSafetyMessage(struct Firework *firework);

/*GRAPHICS functions*/
void graphicsMode(struct Simulation *simPtr, struct Firework *firework);
void drawComeUp(void *data);
void drawFireworkExplode(void *data);
void fade(struct Firework *firework);

/*Calcuations, updates, and linked-list functions*/
void checkForDeletion(struct Simulation *simPtr, struct MemoryCount *memoryCount, struct Firework *firework);
void updateSim(struct Firework *firework); 
void updateFirework(void *data);
void getLowestDT(void *data);
void rangeSafety(void *data); 
int altitudeSort(void *data1, void *data2);
int alreadyExploded(void* data); 
int launchOrder(void *data1, void *data2);
int listEmpty(void *data);


