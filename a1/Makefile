EXEC = bots
CC = gcc
CFLAGS = -g -c
LFALGS = -g
FILES = bots.c
LIBS = -lpthread

OBJECTS = $(FILES:.c=.o)

$(EXEC):$(OBJECTS)
 $(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS) $(LFLAGS) $(LIBS)
 rm -f *.o

.c.o:
 $(CC) $(CFLAGS) $<


clean:
 rm -f *.o $(EXEC)
