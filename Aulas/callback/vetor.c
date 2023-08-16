#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "vetor.h"
#include "constantes.h"

typedef struct Vetor {
    void *elementos;
    int quantidade;
    int tipo;
} tVetor;

tVetor *criar(int tam, int tipo) {
    tVetor *v = (tVetor *)malloc(sizeof(tVetor));
    if (v == NULL) {
        printf("Problema ao alocar um vetor!\n");
        exit(1);
    }

    v->quantidade = tam;
    v->tipo = tipo;

    if (v->tipo == INT) {
        v->elementos = malloc(v->quantidade * sizeof(int));
    } else if (v->tipo == FLOAT) {
        v->elementos = malloc(v->quantidade * sizeof(float));
    } else if (v->tipo == DOUBLE) {
        v->elementos = malloc(v->quantidade * sizeof(double));
    } else {
        printf("Tipo definido é inválido!\n");
        free(v);
        return NULL;
    }

    return v;
}

void preencher(tVetor *v) {
    srand(time(NULL));

    if (v->tipo == INT) {
        for (int i = 0; i < v->quantidade; i++)
            ((int *)v->elementos)[i] = rand() % 10;
    } else if (v->tipo == FLOAT) {
        for (int i = 0; i < v->quantidade; i++)
            ((float *)v->elementos)[i] = (float)rand() / 100000;
    } else if (v->tipo == DOUBLE) {
        for (int i = 0; i < v->quantidade; i++)
            ((double *)v->elementos)[i] = (double)rand() / 100000;
    } else {
        printf("Tipo inválido!\n");
    }
}

void imprimir_vetor (tVetor *v) {
    if (v->tipo == INT) {
        for (int i = 0; i < v->quantidade; i++)
            printf("%d ", ((int*)v->elementos)[i]);
        printf("\n");
    } else if (v->tipo == FLOAT) {
        for (int i = 0; i < v->quantidade; i++)
            printf("%f ", ((float*)v->elementos)[i]);
        printf("\n");
    } else if (v->tipo == DOUBLE) {
        for (int i = 0; i < v->quantidade; i++)
            printf("%lf ", ((double*)v->elementos)[i]);
        printf("\n");
    } else {
        printf("Tipo invalido!\n");
    }
}

double media_int(tVetor *v) {
    double soma = 0;

    for (int i = 0; i < v->quantidade; i++)
        soma += ((int *)v->elementos)[i];

    soma /= (double)v->quantidade;
    return soma;
}

double media_float(tVetor *v) {
    double soma = 0;

    for (int i = 0; i < v->quantidade; i++) {
        soma += ((float *)v->elementos)[i];
    }

    soma /= (double)v->quantidade;
    return soma;
}

double media_double(tVetor *v) {
    double soma = 0;

    for (int i = 0; i < v->quantidade; i++) {
        soma += ((double *)v->elementos)[i];
    }

    soma /= (double)v->quantidade;
    return soma;
}

double media(tVetor *v) {
    if (v->tipo == INT)
        return media_int(v);
    else if (v->tipo == FLOAT)
        return media_float(v);
    else if (v->tipo == DOUBLE)
        return media_double(v);
    else {
        printf("Tipo inválido!\n");
        return 0;
    }
}

double variancia_int(tVetor *v) {
    double soma = 0, valor_media = media(v);

    for (int i = 0; i < v->quantidade; i++)
        soma += pow(((int *)v->elementos)[i] - valor_media, 2);

    soma /= (double)(v->quantidade - 1);
    return soma;
}

double variancia_float(tVetor *v) {
    double soma = 0, valor_media = media(v);

    for (int i = 0; i < v->quantidade; i++)
        soma += pow(((float *)v->elementos)[i] - valor_media, 2);

    soma /= (double)(v->quantidade - 1);
    return soma;
}

double variancia_double(tVetor *v) {
    double soma = 0, valor_media = media(v);

    for (int i = 0; i < v->quantidade; i++)
        soma += pow(((double *)v->elementos)[i] - valor_media, 2);

    soma /= (double)(v->quantidade - 1);
    return soma;
}

double variancia(tVetor *v) {
    if (v->tipo == INT)
        return variancia_int(v);
    else if (v->tipo == FLOAT)
        return variancia_float(v);
    else if (v->tipo == DOUBLE)
        return variancia_double(v);
    else {
        printf("Tipo inválido!\n");
        return 0;
    }
}
/*
double desvio_padrao_int(tVetor *v) {
    double var = variancia_int(v);
    return sqrt(var);
}

double desvio_padrao_float(tVetor *v) {
    double var = variancia_float(v);
    return sqrt(var);
}

double desvio_padrao_double(tVetor *v) {
    double var = variancia_double(v);
    return sqrt(var);
}*/

double desvio_padrao (tVetor *v) {
    double var = variancia(v);
    return sqrt(var);
}

double operacao(tVetor *v, double (*f)(tVetor *)) {
    return f(v);
}

double calcula_op(tVetor *v, char o) {
    if (o == 'm') {
        return operacao(v, media);
    } else if (o == 'v') {
        return operacao(v, variancia);
    } else if (o == 'd') {
        return operacao (v, desvio_padrao);
    } else {
        printf("Operacao invalida!\n");
        return 0;
    }
}

void free_vetor(tVetor *v) {
    free(v->elementos);
    free(v);
}
