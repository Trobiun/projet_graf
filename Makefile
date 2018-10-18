SRCDIR=SRC
OBJDIR=OBJ
LIBDIR=LIB
BINDIR=BIN
INCLUDEDIR=INCLUDE

EXEC=$(BINDIR)/testgraph
SRC=$(wildcard $(SRCDIR)/*.c)
OBJ=$(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CC=gcc
CFLAGS=-Wall -I$(INCLUDEDIR)
LDFLAGS=-lm

all: $(EXEC)
	

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(EXEC) $^

$(OBJ): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: clean veryclean
clean:
	rm -f $(OBJ)

veryclean: clean
	rm -f $(EXEC)
