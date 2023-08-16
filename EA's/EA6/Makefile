all:
	gcc -Wall -Wextra -Werror -g -o EA6 *.c -lm
clean:
	rm EA6
run:
	./EA6
valgrind:
	valgrind --track-origins=yes --leak-check=full ./EA6