#ifndef _AGRUPAMENTO_H
#define _AGRUPAMENTO_H


typedef struct Agrupamento tAgrupamento;

tAgrupamento *criar_agrupamento ();

void free_agrupamento (tAgrupamento *a);

void limpar_agrupamento (tAgrupamento *a);

void ler_base_imagens (tAgrupamento *a, const char *diretorio, const int total_imgs, const int total_pixels);

void k_means (tAgrupamento *a);

void imprimir_centroides (tAgrupamento *a, const char *diretorio);

void imprimir_grupo_imagem (tAgrupamento *a, const char *saida);


#endif