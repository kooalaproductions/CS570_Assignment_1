#Jasmine Nelson RedID: 820233707 (cssc2157)
#Ernesto Sanchez RedID: 819323499 (cssc2123)
#
#CS570, Summer 2020
#Professor Leonard
#
#Assignment #2, Microshell

#Makefile

CC = gcc
CFLAGS = -lreadline

SRCS = test.c

OBJS = $(SRCS:.c=.o)

MAIN = test


all:	$(MAIN)
		@echo Simple compiler named test has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean:
		$(RM) *.o *~ $(MAIN)
