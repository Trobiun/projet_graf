EXEC=main
MENU=menu
SRC=LIB/graph.c LIB/neighbour.c
OBJ=array.o graph.o neighbour.o
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
	rm -f *.o

veryclean : clean
	rm -f $(EXEC)
	rm -f $(MENU)
