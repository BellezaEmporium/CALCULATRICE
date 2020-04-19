###
## Makefile skeleton
## INFO0030: Projet 3
##
###

## Variables

# Tools & flags
CC=gcc
CFLAGS=--std=c99 --pedantic -Wall -W -Wmissing-prototypes `pkg-config --cflags --libs gtk+-2.0`
LD=gcc
LDFLAGS=

# Files
EXEC=calculatrice
MODULES=main.c calculatrice.c
OBJECTS=main.o calculatrice.o

#Documentation
DOCS=Doxyfile

## Rules

all: $(EXEC)

calculatrice: $(OBJECTS)
	$(LD) -o $(EXEC) $(OBJECTS) $(LDFLAGS) `pkg-config --cflags --libs gtk+-2.0`

main.o: main.c
	$(CC) -c main.c -o main.o $(CFLAGS)

calculatrice.o: calculatrice.c
	$(CC) -c calculatrice.c -o calculatrice.o $(CFLAGS)
 
.PHONY: doc
doc: $(MODULES)
	@doxygen ./$(DOCS)
 
 
clean:
	rm -rf doc/
	rm -f *.o $(EXEC) *~
	
