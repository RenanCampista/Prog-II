all: main

main: main.o matrix.o mytools.o
	gcc main.o matrix.o mytools.o -o main

generateos: main.c matrix.c mytools.c
	gcc -c main.c matrix.c mytools.c

clean:
	rm -rf *.o main