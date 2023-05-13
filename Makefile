CC = gcc
CFLAGS = -Wall -Werror

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c, %.o, $(SRCS))

all: program cleanobj

program: $(OBJS)
	$(CC) $(CFLAGS) -o store $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f store *.o

cleanobj:
	rm -f *.o