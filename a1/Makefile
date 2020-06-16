#Jasmine Nelson RedID: 820233707 (cssc2157)
#Ernesto Sanchez RedID: 819323499 (cssc2123)
#
#CS570, Summer 2020
#Professor Leonard
#
#Assignment #1, Write to File Using Threads

#Makefile

CC = gcc
CFLAGS = -lpthread

SRCS = bots.c

OBJS = $(SRCS:.c=.o)

MAIN = bots

.PHONY: depend clean

all:	$(MAIN)
		@echo Simple compiler named bots has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) -c $<	-o $@

clean:
		$(RM) *.o *~ $(MAIN) QUOTE.txt bots.exe


#all:
#		gcc bots.c -o bots -lpthread
#
#clean:
#		rm bots bots.o QUOTE.txt
