all: EA2

EA2: EA2.o paciente.o lesao.o
	gcc EA2.o paciente.o lesao.o -o EA2

generateos: EA2.c paciente.c lesao.c
	gcc -c EA2.c paciente.c lesao.c

clean:
	rm -rf *.o EA2