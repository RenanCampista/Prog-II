#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    float raioAlvo, raioTiro, xAlvo, yAlvo, xTiro, yTiro;
    float dist;
    //teste no labgrad III

    printf("\nRaio do alvo: ");
    scanf("%f", &raioAlvo);

    printf("\nPosicao do alvo (x e y): ");
    scanf("%f %f", &xAlvo, &yAlvo);

    printf("\nRaio do tiro: ");
    scanf("%f", &raioTiro);

    printf("\nPosicao do alvo (x e y): ");
    scanf("%f %f", &xTiro, &yTiro);

    dist = sqrt(pow(xAlvo-xTiro, 2) + pow(yAlvo-yTiro, 2));

    if ((raioAlvo + raioTiro) > dist) {
        printf("\nColisao detectada");
    } else printf("\nNao houve colisao");
}