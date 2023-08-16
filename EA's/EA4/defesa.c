#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "defesa.h"

struct Defesa {
    char nome[50], tipo;
    float x, y;
    float tam;
    float poder;
    int qtd;
};

tDefesa *criar_defesa () {
    tDefesa *d = (tDefesa *) malloc (sizeof(tDefesa));
    if (d == NULL) {
        printf("Problema alocar defesa\n");
        exit(1);
    }
    d->qtd = 0;
    return d;
}

void free_defesa (tDefesa *d) {
    free (d);
}

void ler_defesa (tDefesa *d, char nome[50]) {
    strcpy(d->nome, nome);

    scanf("%f %f %c %f %f %d", &d->x, &d->y, &d->tipo, &d->tam, &d->poder, &d->qtd);
}

float retornar_x_def (tDefesa *d) {
    return d->x;
}

float retornar_y_def (tDefesa *d) {
    return d->y;
}

float retornar_tam_def (tDefesa *d) {
    return d->tam;
}

float retornar_poder_def (tDefesa *d) {
    return d->poder;
}

int retornar_qtd_def (tDefesa *d) {
    return d->qtd;
}

void reduzir_def (tDefesa *d) {
    d->qtd--;
    if (d->qtd < 0)
        d->qtd = 0;
}

int verifica_qtd_def_disp (tDefesa *d) {
    if (d->qtd > 0)
        return 1;
    return 0;
}

void imprimir_def (tDefesa *d) {
    printf("%s: %d\n", d->nome, d->qtd);
}

/*int verifica_sobrepos (tDefesa *d1, tDefesa *d2) {
    float dist = sqrt(pow(d1->x - d2->x, 2) + pow(d1->y - d2->y, 2));

    if ((d1->tam + d2->tam) > dist)
        return 1;
    return 0;
}*/

int verifica_sobrepos (tDefesa *d1, tDefesa *d2) {
    if (d1->tipo == 'Q' && d2->tipo == 'Q') {
        float dist_x = fabs(d1->x - d2->x);
        float dist_y = fabs(d1->y - d2->y);
        float diag_1 = d1->tam * sqrt(2);
        float diag_2 = d2->tam * sqrt(2);

        if (dist_x <= (diag_1 + diag_2) / 2 && dist_y <= (diag_1 + diag_2) / 2)
            return 1;

    } else if (d1->tipo == 'C' && d2->tipo == 'C') {
        float dist = sqrt(pow(d1->x - d2->x, 2) + pow(d1->y - d2->y, 2));
        float soma_raios = d1->tam + d2->tam;

        if (dist <= soma_raios)
            return 1;
    } else if ((d1->tipo == 'C' && d2->tipo == 'Q') || (d1->tipo == 'Q' && d2->tipo == 'C')){
        
        if (d1->tipo == 'D') {
            float square_d = d1->tam / 2;
            float delta_x = fabs (d1->x - d2->x);
            float delta_y = fabs (d1->y - d2->y);

            if (delta_x <= (square_d + d2->tam) && delta_y <= (square_d + d2->tam))
                return 1;
        }  else if (d2->tipo == 'D') {
            float square_d = d2->tam / 2;
            float delta_x = fabs (d1->x - d2->x);
            float delta_y = fabs (d1->y - d2->y);

            if (delta_x <= (square_d + d1->tam) && delta_y <= (square_d + d1->tam))
            return 1;
        }
        
        
        
        
        
        /*float dist = sqrt(pow(d1->x - d2->x, 2) + pow(d1->y - d2->y, 2));

        if ((d1->tam + d2->tam) > dist)
            return 1;*/
    }

    return 0;

}