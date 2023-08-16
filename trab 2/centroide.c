#include <stdio.h>
#include <stdlib.h>
#include "constantes.h"
#include "centroide.h"


struct Centroide {
    tImagem **grupo;

    float *media_grupo;
    
    int tam_grupo;
};

tCentroide *criar_centroide () {
    tCentroide *c = (tCentroide *) malloc(sizeof(tCentroide));
    if (c == NULL) {
        printf("PROBLEMA AO ALOCAR UMA NOVA CENTROIDE\n");
        exit(1);
    }

    c->grupo = NULL;
    c->media_grupo = NULL;

    c->tam_grupo = 0;

    return c;
}

void free_centroide (tCentroide *c) {
    if (c->grupo != NULL)
        free(c->grupo);
    if (c->media_grupo != NULL)
        free(c->media_grupo);
    free(c);
}


    //DISTRIBUICAO DOS GRUPOS
void associar_centroide_inicial (tCentroide *c, tImagem *img) {
    c->media_grupo = (float *) malloc(retornar_num_pixels(img) * sizeof(float));
    guardar_pixels(img, c->media_grupo);
}

void limpar_grupo (tCentroide *c) {
    if (c->grupo != NULL) {
        free(c->grupo);
        c->tam_grupo = 0;
    }
    c->grupo = NULL;
}

float retornar_dist_centroide (tCentroide *c, tImagem *img) {
    return calcular_similaridade_img(img, c->media_grupo);
}

void adicionar_img_ao_grupo (tCentroide *c, tImagem *img) {
    c->tam_grupo++;
    c->grupo = (tImagem **) realloc(c->grupo, c->tam_grupo * sizeof(tImagem *));
    c->grupo[c->tam_grupo-1] = img;
}


    //ATUALIZACAO DOS GRUPOS
void atualizar_media_grupo (tCentroide *c) {
    int total_pixels = retornar_num_pixels(c->grupo[0]);

    float *media = (float *) calloc(total_pixels, sizeof(float));

    for (int i = 0; i < c->tam_grupo; i++) {
        acumular_pixels(c->grupo[i], media);
    }

    if (c->tam_grupo > 0) {
        for (int i = 0; i < total_pixels; i++) {
            media[i] /= (float)c->tam_grupo;
        }
    }
    
    free (c->media_grupo);
    c->media_grupo = media;
}

void imprimir_media_grupo (tCentroide *c, FILE *file) {
    int total_pixels = retornar_num_pixels(c->grupo[0]);
    int num;

    for (int i = 0; i < total_pixels; i++) {
        num = c->media_grupo[i];
        fprintf(file, "%d", num);

        if (i < total_pixels - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\n");
}
