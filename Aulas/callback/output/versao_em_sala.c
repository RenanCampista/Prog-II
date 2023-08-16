#include <stdio.h>

typedef int (*opCallback)(int, int);

opCallback operacoes[128] = {NULL};

int calculadora(char op_cod, int num1, int num2) {
    opCallback op;
    op = operacoes[op_cod];
    if (op == NULL) {
        printf("Operação inválida!\n");
        return 0;
    }
    return op(num1, num2);
}

int soma(int a, int b) {
    return a + b;
}

int subtracao(int a, int b) {
    return a - b;
}

int multiplicacao(int a, int b) {
    return a * b;
}

int divisao(int a, int b) {
    if (b == 0) {
        printf("Divisão por zero não é permitida!\n");
        return 0;
    }
    return a / b;
}

void inicializa_array_operacoes() {
    operacoes['+'] = soma;      // ‘+’ = 43
    operacoes['-'] = subtracao; // ‘-’ = 45
    operacoes['*'] = multiplicacao; // '*' = 42
    operacoes['/'] = divisao;   // '/' = 47
}

int main() {
    char op;
    int num1, num2;

    inicializa_array_operacoes();

    printf("Digite o operador (+, -, *, /): ");
    scanf(" %c", &op);

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);

    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    int resultado = calculadora(op, num1, num2);

    printf("Resultado: %d\n", resultado);

    return 0;
}
