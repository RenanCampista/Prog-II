all:
	gcc -Wall -Wextra -Werror -g -o EA7 *.c -lm
clean:
	rm EA7
run:
	./EA7
valgrind:
	valgrind --track-origins=yes --leak-check=full ./EA7 saida_1 <entrada/entrada_1 >saida_1