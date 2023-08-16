#include "manbooks.h"

int forceOption (int val1, int val2) {
    int value;

    printf("\nOpcao: ");
    while (1) {
        scanf("%d", &value);
        cleanBuffer();

        if (value == val1 || value == val2) {
            return value;
            break;
        }
        printf("\nPor favor, digite uma opcao valida: ");
    }

}

int freePositionBook (tLibrary books[CAPACITY]) {
    int i, aux = FALSE;

    for (i = 0; i < CAPACITY; i++) {
        if (books[i].availbility != 1 && books[i].availbility != 0) {
            aux = TRUE;
            break;
        }
    }
    if (aux == TRUE)
        return i;
    else
        return FALSE;
}

void registerBook (tLibrary books[CAPACITY]) {
    int pos;

    pos = freePositionBook(books);

    if (pos != FALSE) {
        printf("\nTitulo do livro: ");
        fgets(books[pos].title, 50, stdin);

        printf("\nAutor: ");
        fgets(books[pos].author, 50, stdin);

        printf("\nAno de publicacao: ");
        scanf("%d", &books[pos].pubYear);

        printf("\nLivro registrado com sucesso!\n");
        books[pos].availbility = 1;
    } else
        printf("\nCapacidade maxima da biblioteca atingida\n");
}

int searchBook (tLibrary books[CAPACITY]) {
    int pos = FALSE, i, option;
    char bookName[50];


    printf("\nNome do livro: ");
    fgets(bookName, 50, stdin);
    cleanBuffer();

    for (i = 0; i < CAPACITY; i++) {
        if (strcmp(books[i].title, bookName) == 0) {
            pos = i;
            break;
        }
    }
    return pos;
}

void printBooks (tLibrary books[CAPACITY], int pos) {
    printf("\nLIVRO: %s\n", books[pos].title);
    printf("AUTOR: %s\n", books[pos].author);
    printf("ANO DE PUBLICACAO: %d\n", books[pos].pubYear);
}

void removeBook (tLibrary books[CAPACITY], int pos) {
    int option;

    pos = searchBook(books);
    if (pos != FALSE) {
        printBooks(books, pos);
        printf("\nTem certeza que deseja fazer a remocao?\n");
        printf("Digite 1 para confirmar e 0 para cancelar");
        option = forceOption(0, 1);

        if (option == 1) {
            books[pos].title[0] = '\0';
            books[pos].author[0] = '\0';
            books[pos].availbility = FALSE;
            books[pos].pubYear = FALSE;
        } else {
            printf("\nOperacao cancelada\n");
        }
    }
}

void loanBook (tLibrary books[CAPACITY], int pos) {
    books[pos].availbility = UNAVAILABLE;
}

void bookReturn (tLibrary books[CAPACITY], int pos) {
    books[pos].availbility = AVAILABLE;
}

void printAllBooks (tLibrary books[CAPACITY]) {
    int i;

    printf("\n\t\tLIVROS DISPONIVEIS\n");
    for (i = 0; i < CAPACITY; i++) {
        if (books[i].availbility == AVAILABLE) {
            printf("%s\n", books[i].title);
        }
    }

    printf("\n\t\tLIVROS EMPRESTADOS\n");
    for (i = 0; i < CAPACITY; i++) {
        if (books[i].availbility == UNAVAILABLE) {
            printf("%s\n", books[i].title);
        }
    }
}

void initializeLibrary () {
    tLibrary books[CAPACITY];
    int option, pos;

    while (1) {
        printf("\t\tMENU PRINCIPAL\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Remover livro\n");
        printf("3 - Exibir livros cadastrados\n");
        printf("4 - Emprestimo de livro\n");
        printf("5 - Devolucao de livro\n");
        printf("6 - Encerrar secao\n\n");

        printf("Opcao escolhida: ");
        while (1) {
            scanf("%d", &option);
            cleanBuffer();

            if (option == 1 || option == 2 || option == 3 || option == 4 || option == 5 || option == 6) {
                break;
            }

            printf("\nPor favor, digite um opcao valida: ");
        }
        system("clear||cls");

        if (option == 1) {
            registerBook(books);
            continue;
        } else if (option == 2) {
            while (1) {
                pos = searchBook(books);

                if (pos != FALSE) {
                    printBooks(books, pos);
                    removeBook(books, pos);
                    break;
                } else {
                    printf("\nLivro nao encontrado\n");
                    printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
                    option = forceOption(0, 1);

                    if (option == 0) {
                        printf("\nOperacao cancelada\n");
                        break;
                    }
                    system("clear||cls");
                }
            }
            system("clear||cls");
            continue;
        } else if (option == 3) {
            printAllBooks(books);
        } else if (option == 4) {
            while (1) {
                pos = searchBook(books);

                if (pos != FALSE) {
                    printBooks(books, pos);
                    loanBook(books, pos);
                    printf("\nLivro emprestado\n");
                    break;
                } else {
                    printf("\nLivro nao encontrado\n");
                    printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
                    option = forceOption(0, 1);

                    if (option == 0) {
                        printf("\nOperacao cancelada\n");
                        break;
                    }
                    system("clear||cls");
                }
            }
            system("clear||cls");
            continue;
        } else if (option == 5) {
            while (1) {
                pos = searchBook(books);

                if (pos != FALSE) {
                    printBooks(books, pos);
                    bookReturn(books, pos);
                    printf("\nLivro devolvido\n");
                    break;
                } else {
                    printf("\nLivro nao encontrado\n");
                    printf("Digite 1 para realizar uma nova busca ou 0 para cancelar a operacao (voltar para o menu principal)");
                    option = forceOption(0, 1);

                    if (option == 0) {
                        printf("\nOperacao cancelada\n");
                        break;
                    }
                    system("clear||cls");
                }
            }
            system("clear||cls");
        } else break;
    }
}