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
#		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
#
#.c.o:
#			$(CC) $(CFLAGS) -c $<	-o $@
#
#clean:
#		$(RM) *.o *~ $(MAIN)


all:
		gcc bots.c -o bots -lpthread

clean:
		rm bots bots.o QUOTE.txt
