#CC = gcc
#CFLAGS = -lpthread
#
#SRCS = bots.c
#
#OBJS = $(SRCS:.c=.o)
#
#MAIN = bots
#
#.PHONY: depend clean
#
#all:	$(MAIN)
#		@echo Simple compiler named bots has been compiled
#
#$(MAIN): $(OBJS)
#		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)
#
#.c.o:
#			$(CC) $(CFLAGS) -c $<	-o $@
#
#clean:
#		$(RM) *.o *~ $(MAIN)

CFLAGS = -lpthread

bots:	bots.o
		gcc $(CFLAGS) -o bots bots.o

bots.o:	bots.c
		gcc -c bots.c

clean:
		rm -f *.o bots
