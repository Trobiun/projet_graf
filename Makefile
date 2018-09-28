EXEC=main
SRC=LIB/list.c LIB/graph.c LIB/array.c LIB/neighbour.c
OBJ=list.o graph.o array.o neighbour.o
CC=gcc
CLFAGS=-Wall
LDFLAGS=-lm

$(EXEC) : SRC/main.c $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $?

%.o : %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean :
	rm *.o

veryclean : clean
	rm $(EXEC)
