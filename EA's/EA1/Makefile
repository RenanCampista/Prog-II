all: EA1

EA1: EA1.o clinica.o
	gcc EA1.o clinica.o -o EA1

generateos: EA1.c clinica.c
	gcc -c EA1.c clinica.c

clean:
	rm -rf *.o EA1