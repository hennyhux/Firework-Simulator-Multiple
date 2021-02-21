#Author: Henry Zhang

#Default target 
all: lab3

#Lets clean this mess up! Remove all object and zip files
clean:
	rm -rf *.o mkprog *.zip lab3 p1 p2 p3 p4 

#Entry to create the lab executable
lab3: lab3.o memory.o draw.o physics.o bit.o
	gcc -g -o $@ $^ -lncurses -L. -lfire -llinkedlist

#Entry to zip all the required files
lab3.zip: makefile *.c *.h *.a LAB3_README
	zip $@ makefile *.c *.h *.a LAB3_README
	rm -rf install 
	mkdir install
	unzip lab3.zip -d install
	make -C install lab3

#This entry compiles .c files into .o files required for the executable 
%.o: %.c *.h 
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@ -llinkedlist -lncurses -L. -lfire


#Prototype functions below

p1: p1.o
	gcc -g -o $@ $^ -lncurses -L. -lfire -llinkedlist

p2: p2.o
	gcc -g -o $@ $^ -lncurses -L. -lfire -llinkedlist

p3: p3.o
	gcc -g -o $@ $^ -lncurses -L. -lfire -llinkedlist

p4: p4.o
	gcc -g -o $@ $^ -lncurses -L. -lfire -llinkedlist
