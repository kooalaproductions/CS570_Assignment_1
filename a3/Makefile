#Jasmine Nelson RedID: 820233707 (cssc2157)
#Ernesto Sanchez RedID: 819323499 (cssc2123)
#
#CS570, Summer 2020
#Professor Leonard
#
#Assignment #3, Management of Threads (mot)

#Makefile

CC = gcc
CFLAGS = -lpthread

SRCS = mot.c

OBJS = $(SRCS:.c=.o)

MAIN = mot


all:	$(MAIN)
		@echo Simple compiler named mot has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean:
		$(RM) *.o *~ $(MAIN)
