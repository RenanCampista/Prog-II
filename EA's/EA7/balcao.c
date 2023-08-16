#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "balcao.h"
#include "constantes.h"


struct Balcao {
    int **matriz;
    
    int num_linhas;
    int num_colunas;

    int x_inicial, y_inicial;
    int x_final, y_final;

    int x_ant, y_ant;

    char prioridade[5];
};


tBalcao *criar_balcao () {
    tBalcao *b = (tBalcao *) malloc(sizeof(tBalcao));
    if (b == NULL) {
        printf("Erro alocar memoria balao\n");
        exit(1);
    }

    b->num_colunas = 0;
    b->num_linhas = 1;
    b->matriz = (int **) malloc( sizeof(int *));
    b->matriz[b->num_linhas-1] = NULL;
    b->x_ant = -1;
    b->y_ant = -1;

    return b;
}

void free_balcao (tBalcao *b) {
    for (int i = 0; i < b->num_linhas; i++) {
        free(b->matriz[i]);
    }
    free(b->matriz);
    free(b);
}

void ler_balcao (tBalcao *b) {
    int cont = 0;
    char valor;
    int aux = 0;

    while (1) {
        scanf("%c", &valor);
        if (valor == '1' || valor == '0'){
            cont++;
            b->matriz[b->num_linhas-1] = (int *) realloc(b->matriz[b->num_linhas-1], (cont+1) * sizeof(int));
            b->matriz[b->num_linhas-1][cont-1] = valor - '0';

        } else if (valor == '\n') {
            if (aux == 0)
                b->num_colunas = cont+1;
            cont = 0;
            b->num_linhas++;
            b->matriz = (int **) realloc(b->matriz, b->num_linhas * sizeof(int *));
            b->matriz[b->num_linhas-1] = NULL;
            aux = 1;
        } else if (valor == 'F')
            break;
    }

    scanf("\n%d %d", &b->x_inicial, &b->y_inicial);
    scanf("\n%d %d", &b->x_final, &b->y_final);
    scanf("\n%s", b->prioridade);
}

void imprimir_balcao (tBalcao *b) {
    for (int i = 0; i < b->num_linhas-1; i++) {
        for (int j = 0; j < b->num_colunas; j++) {
            printf("%d ", b->matriz[i][j]);
        }
        printf("\n");
    }
}


int verifica_objetivo (tBalcao *b) {
    if (b->x_inicial == b->x_final && b->y_inicial == b->y_final)
        return 1;
    return 0;
}

void realiza_movimentos (tBalcao *b) {
    int aux = 0;

    printf("(%d,%d) ", b->x_inicial, b->y_inicial);
    while (1) {
        aux = 0;

        for (int i = 0; i < MAX_PRIORIDADE; i++) {
            if (b->prioridade[i] == 'B'){
                //BAIXO
                if (b->x_inicial+1 < b->num_linhas-1) {
                    if (b->matriz[b->x_inicial+1][b->y_inicial] == LIVRE && b->x_inicial+1 != b->x_ant) {
                        b->x_ant = b->x_inicial;
                        b->y_ant = b->y_inicial;

                        b->x_inicial++;
                        printf("(%d,%d) ", b->x_inicial, b->y_inicial);
                        aux = 1;
                        break;
                    }
                }
            } else if (b->prioridade[i] == 'C') {
                //CIMA
                if (b->x_inicial >= 0) {
                    if (b->matriz[b->x_inicial-1][b->y_inicial] == LIVRE && b->x_inicial-1 != b->x_ant) {
                        b->x_ant = b->x_inicial;
                        b->y_ant = b->y_inicial;

                        b->x_inicial--;
                        printf("(%d,%d) ", b->x_inicial, b->y_inicial);
                        aux = 1;
                        break;
                    }
                }
            } else if (b->prioridade[i] == 'D') {
                //DIREITA
                if (b->y_inicial + 1 < b->num_colunas-1) {
                    if (b->matriz[b->x_inicial][b->y_inicial+1] == LIVRE && b->y_inicial+1 != b->y_ant) {
                        b->x_ant = b->x_inicial;
                        b->y_ant = b->y_inicial;

                        b->y_inicial++;
                        printf("(%d,%d) ", b->x_inicial, b->y_inicial);
                        aux = 1;
                        break;
                    }
                }
            } else if (b->prioridade[i] == 'E') {
                //ESQUERDA
                if (b->y_inicial -1 >= 0) {
                    if (b->matriz[b->x_inicial][b->y_inicial-1] == LIVRE && b->y_inicial-1 != b->y_ant) {
                        b->x_ant = b->x_inicial;
                        b->y_ant = b->y_inicial;

                        b->y_inicial--;
                        printf("(%d,%d) ", b->x_inicial, b->y_inicial);
                        aux = 1;
                        break;
                    }
                }
            }
        }

        if (verifica_objetivo(b) || aux == 0)
            break;
        
    }
}