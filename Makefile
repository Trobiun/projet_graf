SRCDIR=SRC
OBJDIR=OBJ
LIBDIR=LIB
BINDIR=BIN
INCLUDEDIR=INCLUDE

EXEC=$(BINDIR)/testgraph
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIBGRAPH=$(LIBDIR)/libgraph.a
LIBLIST=$(LIBDIR)/liblist.a
LIBS=$(LIBGRAPH) $(LIBLIST)
CC=gcc
CFLAGS=-Wall -I$(INCLUDEDIR)
LDFLAGS=-L$(LIBDIR) -lgraph -llist

.PHONY: all run libs
all: $(EXEC)

run: $(EXEC)
	$(EXEC)

libs: $(LIBS)

$(EXEC): $(OBJDIR)/main.o $(OBJDIR)/menu.o $(LIBS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $^

$(LIBGRAPH): $(OBJDIR)/graph.o
	ar rcs $@ $?

$(LIBLIST): $(OBJDIR)/neighbour.o
	ar rcs $@ $?

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean veryclean
clean:
	rm -f $(OBJ)

veryclean: clean
	rm -f $(EXEC)
	rm -f $(LIBS)
