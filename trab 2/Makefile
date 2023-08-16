all:
	gcc -Wall -Wextra -Werror -g -o trab2 *.c -lm
clean:
	rm trab2
run:
	./trab2
valgrind:
	#time valgrind --track-origins=yes --leak-check=full ./trab2 testes/cifar10/imagens_cifar10 minhas_saidas/cifar10 <testes/cifar10/testes_imagens_cifar10/teste_4/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 testes/fashion/imagens_fashion_mnist minhas_saidas/fashion/teste_1 <testes/fashion/testes_imagens_fashion_mnist/teste_1/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 testes/fashion/imagens_fashion_mnist minhas_saidas/fashion/teste_2 <testes/fashion/testes_imagens_fashion_mnist/teste_2/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 testes/minist/imagens_mnist minhas_saidas/minist <testes/minist/testes_imagens_mnist/teste_3/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 banco_imagens_1/imagens minhas_saidas/banco_imagens_1/teste_1 <banco_imagens_1/teste_1/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 banco_imagens_1/imagens minhas_saidas/banco_imagens_1/teste_2 <banco_imagens_1/teste_2/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 banco_imagens_1/imagens minhas_saidas/banco_imagens_1/teste_3 <banco_imagens_1/teste_3/entrada
	#time valgrind --track-origins=yes --leak-check=full ./trab2 banco_imagens_1/imagens minhas_saidas/banco_imagens_1/teste_4 <banco_imagens_1/teste_4/entrada
	time valgrind --track-origins=yes --leak-check=full ./trab2 banco_imagens_2/imagens minhas_saidas/banco_imagens_2/teste_1 <banco_imagens_2/teste_1/entrada