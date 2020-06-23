#Jasmine Nelson RedID: 820233707 (cssc2157)
#Ernesto Sanchez RedID: 819323499 (cssc2123)
#
#CS570, Summer 2020
#Professor Leonard
#
#Assignment #2, Microshell

#Makefile

CC = gcc
CFLAGS = -lpthread

SRCS = msh.c

OBJS = $(SRCS:.c=.o)

MAIN = pam


all:	$(MAIN)
		@echo Simple compiler named msh has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)


clean:
		$(RM) *.o *~ $(MAIN)
