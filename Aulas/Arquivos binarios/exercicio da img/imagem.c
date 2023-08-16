#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

struct Imagem {
    int l, c;
    int tipo;
    int *pixels;
};

tImagem *criar_imagem () {
    tImagem *img = (tImagem *) malloc(sizeof(tImagem));
    if (img == NULL) {
        printf("ERRO AO ALOCAR IMAGEM\n");
        exit(1);
    }
    img->pixels = NULL;

    return img;
}

void free_imagem (tImagem *img) {
    if (img->pixels != NULL) {
        free(img->pixels);
    }
    free(img);
}

void ler_arqv_imagem (tImagem *img, FILE *file) {
    fread (&img->l, sizeof(int), 1, file);
    fread (&img->c, sizeof(int), 1, file);

    fread (&img->tipo, sizeof(int), 1, file);

    img->pixels = (int *) realloc (img->pixels, (img->c * img->l) * sizeof(int));

    fread(img->pixels, sizeof(int), img->c * img->l, file);
}

int retorna_maior_pixel (tImagem *img) {
    int maior = 0;
    for (int i = 0; i < img->c * img->l; i++) {
        if (img->pixels[i] > maior) {
            maior = img->pixels[i];
        }
    }
    return maior;
}

int retorna_menor_pixel (tImagem *img) {
    int menor = img->pixels[0];
    for (int i = 1; i < img->c * img->l; i++) {
        if (img->pixels[i] < menor) {
            menor = img->pixels[i];
        }
    }
    return menor;
}

int retorna_pixel_medio (tImagem *img) {
    int soma = 0;

    for (int i = 0; i < img->c * img->l; i++) {
        soma += img->pixels[i];
    }

    soma /= img->c * img->l;

    return soma;

}