all: main

main: main.o bankingoper.o login.o mytools.o
	gcc main.o bankingoper.o login.o mytools.o -o main

generateos: main.c bankingoper.c login.c mytools.c
	gcc -c main.c bankingoper.c login.c mytools.c

clean:
	rm -rf *.o main