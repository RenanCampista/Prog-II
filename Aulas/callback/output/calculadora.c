#include <stdio.h>

// Definição do tipo de função callback
typedef int (*OperationCallback)(int, int);

// Funções de operação
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

// Função principal
int main() {
    int num1, num2;
    char operator;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &operator);

    // Ponteiro para a função de callback
    OperationCallback callback;

    // Seleciona a função de callback com base no operador
    switch (operator) {
        case '+':
            callback = add;
            break;
        case '-':
            callback = subtract;
            break;
        case '*':
            callback = multiply;
            break;
        case '/':
            callback = divide;
            break;
        default:
            printf("Operador inválido!\n");
            return 1;
    }

    // Executa a operação usando a função de callback selecionada
    int result = callback(num1, num2);

    printf("Resultado: %d\n", result);

    return 0;
}
