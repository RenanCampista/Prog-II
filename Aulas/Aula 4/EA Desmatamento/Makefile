all: main

main: main.o finesdef.o mytools.o
	gcc main.o finesdef.o -lm mytools.o -o main

generateos: main.c finesdef.c mytools.c
	gcc -c main.c finesdef.c mytools.c

clean:
	rm -rf *.o main