#include "mytools.h"

void cleanBuffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

char passwordImput (char password[10]) {
   char c;
   int i = 0;
   
   while ((c = getchar()) != '\r') { // lê caracteres até o usuário pressionar Enter
      if (c == 8) { // se o caractere digitado for backspace
         if (i > 0) { // se houver caracteres para apagar
            i--; // retrocede um caractere na string
            printf("\b \b"); // apaga o caractere anterior digitado na tela
         }
      }
      else {
         password[i++] = c;
         printf("*"); // exibe asterisco no lugar do caractere digitado
      }
   }
   
   password[i] = '\0'; // adiciona o caractere nulo no final da senha
}

char charForceOption (char op1, char op2) {
    char value;

    printf("\nOpcao: ");
    while (1) {
        scanf("%c", &value);

        if (value == op1 || value == op2) {
            return value;
            break;
        }
        printf("\nPor favor, digite uma opcao valida: ");
    }
}

int intFoceOption (int op1, int op2) {
    int value;

    printf("\nOpcao: ");
    while (1) {
        scanf("%d", &value);
        cleanBuffer();

        if (value == op1 || value == op2) {
            return value;
            break;
        }
        printf("\nPor favor, digite uma opcao valida: ");
    }
}