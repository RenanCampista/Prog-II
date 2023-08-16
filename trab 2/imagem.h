#ifndef _IMAGEM_H
#define _IMAGEM_H


typedef struct Imagem tImagem;

tImagem *criar_imagem ();

void free_imagem (tImagem *img);

int total_pixels_leitura (const char *diretorio);

void ler_imagem (tImagem *img, FILE *file, int num_pixels);

void imprimir_imagem (tImagem *img, FILE *file);

int retornar_num_pixels (tImagem *img);

void guardar_pixels (tImagem *img, float *destino);

float calcular_similaridade_img (tImagem *img1, float *centro);

void acumular_pixels (tImagem *img, float *acumulador);

void gerar_histograma_imagem (const char *entrada, const char *saida, const int total_pixels);

void reconstruir_imagem (const char *entrada, const char *saida, const int total_pixels);


#endif