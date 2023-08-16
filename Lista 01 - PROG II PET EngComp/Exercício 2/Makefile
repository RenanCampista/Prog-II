all: main

main: main.o pauta.o
	gcc main.o pauta.o -o main

generateos: main.c pauta.c
	gcc -c main.c pauta.c

clean:
	rm -rf *.o main