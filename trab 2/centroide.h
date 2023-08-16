#ifndef _CENTROIDE_H
#define _CENTROIDE_H
#include "imagem.h"


typedef struct Centroide tCentroide;

tCentroide *criar_centroide ();

void free_centroide (tCentroide *c);

void associar_centroide_inicial (tCentroide *c, tImagem *img);

void limpar_grupo (tCentroide *c);

float retornar_dist_centroide (tCentroide *c, tImagem *img);

void adicionar_img_ao_grupo (tCentroide *c, tImagem *img);

void atualizar_media_grupo (tCentroide *c);

void imprimir_media_grupo (tCentroide *c, FILE *file);


#endif