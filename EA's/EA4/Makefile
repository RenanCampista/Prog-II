all:
	gcc -Wall -Wextra -Werror -g -o EA4 *.c -lm
clean:
	rm EA4
run:
	./EA4
valgrind:
	valgrind --track-origins=yes --leak-check=full ./EA4 saida_3 <entrada/entrada_2 >saida_2