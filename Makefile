###Makefile for mars map project


CC=gcc
CFLAGS=-O3 -Wall -g
LFLAGS= -lgdsl

dictionary: main.c Makefile dictionary.o
	$(CC) $(CFLAGS) main.c dictionary.o -o dictionary $(LFLAGS)

dictionary.o:	dictionary.h dictionary.c
	$(CC) $(CFLAGS) -c dictionary.c

clean:
	@ rm *.o
	@ rm dictionary 
