#ifndef _IMAGEM_H
#define _IMAGEM_H

typedef struct Imagem tImagem;

tImagem *criar_imagem ();

void free_imagem (tImagem *img);

void ler_arqv_imagem (tImagem *img, FILE *file);

int retorna_maior_pixel (tImagem *img);

int retorna_menor_pixel (tImagem *img);

int retorna_pixel_medio (tImagem *img);

#endif