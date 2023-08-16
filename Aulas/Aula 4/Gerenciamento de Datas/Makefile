all: main

main: main.o date.o mytools.o
	gcc main.o date.o mytools.o -o main

generateos: main.c date.c mytools.c
	gcc -c main.c date.c mytools.c

clean:
	rm -rf *.o main