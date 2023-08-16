all: main

main: main.o loja.o vendedor.o
	gcc main.o loja.o vendedor.o -o main

generateos: main.c loja.c vendedor.c
	gcc -c main.c loja.c vendedor.c

clean:
	rm -rf *.o main