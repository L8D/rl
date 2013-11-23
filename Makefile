CC=gcc
CFLAGS=-Wall -std=c99 -Werror
LDFLAGS=
SOURCES=rl.c
OBJECTS=$(SOURCES:.c=.o)

all: objects
	ln -s rl.o rl

objects:
	$(CC) $(CFLAGS) $(SOURCES) -o $(OBJECTS)

clean:
	rm -f rl *.o
