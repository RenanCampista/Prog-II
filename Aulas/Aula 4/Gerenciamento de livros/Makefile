all: main

main: main.o manbooks.o mytools.o
	gcc main.o manbooks.o mytools.o -o main

generateos: main.c manbooks.c mytools.c
	gcc -c main.c manbooks.c mytools.c

clean:
	rm -rf *.o main