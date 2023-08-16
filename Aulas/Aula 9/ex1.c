#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int *notas = (int*) malloc(sizeof(int)), qtdNotas = 0, valor = 0;
    float dp = 0, media = 0;


    while(valor >= 0) {
        scanf("%d", &valor);
        qtdNotas++;
        notas = (int*) realloc(notas, qtdNotas * sizeof(int));
        notas[qtdNotas-1] = valor;
    }

    for (int i = 0; i < qtdNotas; i++) {
        media += notas[i];
    }
    media /= qtdNotas-1;

    for (int i = 0; i < qtdNotas; i++) {
        dp += pow(notas[i] - media, 2);
    }
    dp /= qtdNotas;
    sqrt(dp);
    free(notas);
    printf("Dp = %f", dp);

    return 0;
}