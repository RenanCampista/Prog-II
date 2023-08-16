all:
	gcc -Wall -Wextra -Werror -g -o main *.c -lm
clean:
	rm main
run:
	./mian
valgrind:
	valgrind --track-origins=yes --leak-check=full ./main