all:
	gcc -Wall -Wextra -Werror -g -o EA5 *.c -lm
clean:
	rm EA5
run:
	./EA5
valgrind:
	valgrind --track-origins=yes --leak-check=full ./EA5 saida_1 <entrada/entrada_1 >saida_1