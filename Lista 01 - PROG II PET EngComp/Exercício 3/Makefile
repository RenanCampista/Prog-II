all: main

main: main.o conta.o usuario.o
	gcc main.o conta.o usuario.o -o main

generateos: main.c conta.c usuario.c
	gcc -c main.c conta.c usuario.c

clean:
	rm -rf *.o main