all:
	gcc -Wall -Wextra -Werror -g -o trab1 *.c -lm
clean:
	rm trab1
run:
	./trab1
valgrind:
	valgrind --track-origins=yes --leak-check=full ./trab1 saida_5 <testes_correcao/teste_5/entrada
