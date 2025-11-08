# Makefile
     
CFLAGS = -Wall # flags de compilacao
CC = gcc

all: arraysRacionais.o racionais.o
	$(CC) -o arraysRacionais arraysRacionais.o racionais.o

racionais.o: racionais.c
	$(CC) -c $(CFLAGS) racionais.c

arraysRacionais.o: arraysRacionais.c
	$(CC) -c $(CFLAGS) arraysRacionais.c

clean:
	rm -f *.o *~ arraysRacionais
