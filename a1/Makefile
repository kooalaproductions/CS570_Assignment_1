#Jasmine Nelson RedID: 820233707 (cssc2157)
#Ernesto Sanchez RedID: 819323499 (cssc2123)
#
#CS570, Summer 2020
#Professor Leonard
#
#Assignment #1, Write to File Using Threads

#Makefile

CC = gcc
CFLAGS = -lpthread -std=c99 -pthread -lm

SRCS = bots.c

OBJS = $(SRCS:.c=.o)

MAIN = bots


all:	$(MAIN)
		@echo Simple compiler named bots has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean:
		$(RM) *.o *~ $(MAIN) QUOTE.txt


