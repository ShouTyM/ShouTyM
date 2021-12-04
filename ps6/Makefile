# variables
CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LDLIBS=-lm -lncurses
OUTPUT=$@

# targets
%: %.c
	$(CC) $(CFLAGS) $@.c $(LDLIBS) -o $(OUTPUT)


