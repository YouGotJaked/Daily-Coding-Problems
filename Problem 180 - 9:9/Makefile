CC	= gcc
CFLAGS	= -g -Wall

all:	p180

p180:	p180.o stack.o queue.o
	$(CC) -o p180 p180.o stack.o queue.o -lm

clean:;	rm -f *.o p180 core
