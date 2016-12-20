CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: rogue run clean

rogue:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./rogue

clean:
	rm rogue