EXEC=main
MENU=menu
SRC=LIB/list.c LIB/graph.c LIB/array.c LIB/neighbour.c
OBJ=list.o graph.o array.o neighbour.o
CC=gcc
CLFAGS=-Wall
LDFLAGS=-lm

$(EXEC) : main.c $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $?

$(MENU) : SRC/menu.c

	$(CC) $(CFLAGS) $(LDFLAGS) -o $(MENU) $?
%.o : %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm *.o

veryclean : clean
	rm $(EXEC)
	rm $(MENU)
