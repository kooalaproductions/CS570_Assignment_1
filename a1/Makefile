CC = gcc
CFLAGS = -Wall -g
LFLAGS = -g
LIBS = -lpthread

SRCS = bots.c

OBJS = $(SRCS:.c=.o)

MAIN = bots

.PHONY: depend clean

all:	$(MAIN)
		@echo Simple compliter named bots has been compiled

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
			$(CC) $(CFLAGS) -c $<	-o $@

clean:
		$(RM) *.o *~ $(MAIN)