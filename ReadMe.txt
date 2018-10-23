How to compile the project :
 - just run "make" command in root directory of the project

How to launch the program :
 - just run "make run" command in root directory of the project

To use the program faster, this is possible to send multiple (corrects) inputs in the same time.
It simply consists to separate wanted options by a character (for example space).
First, the program needs to be running and waiting an input, then you can type "1 11 n" and press enter, the graph will be created ("1") with 11 nodes maximum and it will not be directed ("n"). There is a file to create "automatically" the graph as example in the subject, you can just copy/paste the line, the graph is created.


Directories :
 - BIN		: the directory where the program will be compiled to
 - INCLUDE	: the directory which contains headers files
 - LIB		: the directory for libraries where libgraph and liblist will be compiled to
 - OBJ		: the directory for temporary object files
 - SRC		: the directory which contains the source files
 
Files :
 - Makefile				: the makefile to manage (compile, clean, run) the project
 - example.txt			: contains the sequence of inputs to create the example graph in the subject

 - INCLUDE/neighbour.h	: header file for neighbour (linked list) structure, with declarations of functions
 - INCLUDE/graph.h		: header file for graph structure with declarations of functions
 - INCLUDE/menu.h		: header file for menu structures with declarations of functions and some constants

 - SRC/neighbour.c		: source file for neighbour (linked list) structure, provides basic operations (create, add neighbour, delete...)
 - SRC/graph.c			: source file for graph structure, provides basic operations (create, add node, add edge...)
 - SRC/menu.c			: source file for menu structures, provides basic operations (create, destroy, show)
 - SRC/main.c			: source file for main program that call functions to manage menus and the graph structure
