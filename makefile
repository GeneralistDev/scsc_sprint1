# Compile C Chat server and all dependencies
CC=gcc
CFLAGS=-c -pthread -Wall
DEBUGCFLAGS= -c -pthread -Wall -ggdb
SOURCES=source/main.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bin/scschat

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -ggdb $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
