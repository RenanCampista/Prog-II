#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "ataque.h"

struct Ataque {
    char nome[50];
    float x, y;
    float poder;
    float dano_causado;
};

tAtaque *criar_ataque () {
    tAtaque *a = (tAtaque *) malloc(sizeof(tAtaque));
    if (a == NULL) {
        printf("Problema alocar ataque\n");
        exit(1);
    }
    a->dano_causado = 0;
    return a;
}

void free_ataque (tAtaque *a) {
    free (a);
}

void ler_ataque (tAtaque *a, char nome[50]) {
    strcpy(a->nome, nome);

    scanf("%f %f %f", &a->x, &a->y, &a->poder);
}

int verifica_colisao_atq (tAtaque *a, float x_cid, float y_cid) {
    if (a->x > x_cid || a->y > y_cid)
        return 0;
    return 1;
}

int verifica_acertou_def (tAtaque *a, float x_def, float y_def, float tam) {
    float dist = sqrt(pow(x_def - a->x, 2) + pow(y_def - a->y, 2));

    if (tam > dist)
        return 1;
    return 0;
}

float retornar_dano_causado (tAtaque *a, float poder_def) {
    if (poder_def >= a->poder) {
        return 0;
    } else {
        return a->poder - poder_def;
    }
}


float retornar_poder_mis (tAtaque *a) {
    return a->poder;
}

void registrar_dano_missil (tAtaque *a, float dano) {
    a->dano_causado += dano;
}

void imprimri_missil (tAtaque *a) {
    printf("%s: %.2f\n", a->nome, a->dano_causado);
}