#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "imagem.h"
#include "constantes.h"

struct Imagem {
    int *pixels;
    int num_pixels;
};

tImagem *criar_imagem () {
    tImagem *i = (tImagem *) malloc(sizeof(tImagem));
    if (i == NULL) {
        printf("PROBLEMA AO ALOCAR UMA NOVA IMAGEM\n");
        exit(1);
    }

    i->pixels = NULL;
    i->num_pixels = 0;

    return i;
}

void free_imagem (tImagem *img) {
    if (img->pixels != NULL)
        free(img->pixels);
    free(img);
}


    //LEITURA E IMPRESSAO
int total_pixels_leitura (const char *diretorio) {
    int pixel, cont_pixels = 0;
    
    char diretorio_completo[100];
    snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/imagem_0.csv", diretorio);
    FILE *arquivo = fopen(diretorio_completo, "r");
    if (arquivo == NULL) {
        printf("ARQUIVO NAO ENCONTRADO\n");
        return 0;
    }

    while(fscanf(arquivo, "%d,", &pixel) == 1) {
        cont_pixels++;
    }

    fclose(arquivo);

    return cont_pixels;
}

void ler_imagem (tImagem *img, FILE *file, int num_pixels) {

    img->pixels = (int *) malloc(num_pixels * sizeof(int));
    img->num_pixels = num_pixels;
    
    for (int i = 0; i < num_pixels; i++) {
        fscanf(file, "%d,", &img->pixels[i]);
    }
}

void imprimir_imagem (tImagem *img, FILE *file) {
    for (int i = 0; i < img->num_pixels; i++) {
        fprintf(file, "%d", img->pixels[i]);

        if (i < img->num_pixels - 1)
            fprintf(file, ",");
    }
    fprintf(file, "\n");
}


    //FUNCIONALIDADE 1
int retornar_num_pixels (tImagem *img) {
    return img->num_pixels;
}

void guardar_pixels (tImagem *img, float *destino) {
    for (int i = 0; i < img->num_pixels; i++) {
        destino[i] = (float)img->pixels[i];
    }
}

float calcular_similaridade_img (tImagem *img1, float *centro) {
    float soma = 0;
    float conversor;
    for (int i = 0; i < img1->num_pixels; i++) {
        conversor = (float)img1->pixels[i];
        soma += (conversor - centro[i]) * (conversor - centro[i]);
    }

    return soma;
}

void acumular_pixels (tImagem *img, float *acumulador) {
    for (int i = 0; i < img->num_pixels; i++) {
        acumulador[i] += (float)img->pixels[i];
    }
}


    //FUNCIONALIDADE 3
void gerar_histograma_imagem (const char *entrada, const char *saida, const int total_pixels) {
    while (1) {
        char nome_img[20];
        printf("\nDIGITE O NOME DA IMAGEM OU 'M' PARA RETORNAR AO MENU PRINCIPAL: ");
        scanf("\n%s", nome_img);

        if (strcmp(nome_img, "M") == 0 || strcmp(nome_img, "m") == 0)
            break;

        char diretorio_completo[100];
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/%s.csv", entrada, nome_img);

        FILE *file = fopen(diretorio_completo, "r");
        if (file == NULL) {
            printf("ARQUIVO NAO ENCONTRADO\n");
            return;
        }
            

        tImagem *im = criar_imagem();
        ler_imagem(im, file, total_pixels);
        fclose(file);

        int num_bins;
        printf("\nDIGITE A QUANTIDADE DE BINS: ");
        scanf("\n%d", &num_bins);

        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/hist_%d_%s.csv", saida, num_bins, nome_img);
        file = fopen(diretorio_completo, "w");
        if (file == NULL) {
            printf("PROBLEMA AO CRIAR O ARQUIVO\n");
            return;
        }

        float intervalo_max = 0, intervalo_min = 0, tam_barra = 0;
        if (num_bins > 0) {
            intervalo_max = INTENS_MAX_PIXEL / (float)num_bins;
            tam_barra = intervalo_max;
       
            for (int i = 1; i <= num_bins; i++) {
                int cont_pixels = 0;

                for (int j = 0; j < im->num_pixels; j++) {
                    if (i < num_bins && (float)im->pixels[j] >= intervalo_min && im->pixels[j] < intervalo_max) 
                        cont_pixels++;
                    else if (i == num_bins && (float)im->pixels[j] >= intervalo_min && im->pixels[j] <= intervalo_max) 
                        cont_pixels++;
                }
                
                fprintf(file, "BIN %d, %d\n", i, cont_pixels);

                intervalo_min = intervalo_max;
                intervalo_max += tam_barra;
            }

            
        }
        fclose(file);
        free_imagem(im);

        printf("\nHISTOGRAMA DA IMAGEM DEFINIDO. ACESSE O ARQUIVO GERADO PARA VERIFICAR\n\n");

    }
}


    //FUNCIONALIDADE 4
void reconstruir_imagem (const char *entrada, const char *saida, const int total_pixels) {
    while (1) {
        char nome_img[20];
        printf("DIGITE O NOME DA IMAGEM: ");
        scanf("\n%s", nome_img);

        if (strcmp(nome_img, "M") == 0 || strcmp(nome_img, "m") == 0)
            break;

        char diretorio_completo[100];
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/%s.csv", entrada, nome_img);

        FILE *file = fopen(diretorio_completo, "r");
        if (file == NULL) {
            printf("ARQUIVO NAO ENCONTRADO\n");
            return;
        }

        tImagem *im = criar_imagem();
        ler_imagem(im, file, total_pixels);
        fclose(file);

        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/rec_%s.csv", saida, nome_img);
        file = fopen(diretorio_completo, "w");
        if (file == NULL) {
            printf("PROBLEMA AO CRIAR O ARQUIVO\n");
            return;
        }

        int res_x, res_y;
        printf("\nRESOLUCAO: ");
        scanf("\n%d x %d", &res_x, &res_y);
        
        if (res_x * res_y == im->num_pixels) {
            int pos = 0;
            for (int i = 0; i < res_x; i++) {
                for (int j = 0; j < res_y; j++) {
                    fprintf(file, "%d", im->pixels[pos]);
                    pos++;
                    if (pos >= im->num_pixels)
                        pos = 0;
                    if (j < res_y - 1)
                        fprintf(file, ",");
                }
                fprintf(file, "\n");
            }
        } else {
            printf("RESOLUCAO INCOMPATIVEL COM A IMAGEM\n");
        }

        fclose(file);
        free_imagem(im);

        printf("\nIMAGEM RECONSTRUIDA COM SUCESSO. ACESSE O ARQUIVO GERADO PARA VERIFICAR\n\n");
    }
}



    //POSSIVEL VERSAO COM HISTOGRAMA COM ESCALA LOGARITMICA
/*void gerar_histograma_imagem (const char *entrada, const char *saida, const int total_pixels) {
    while (1) {
        char nome_img[20];
        printf("\nDIGITE O NOME DA IMAGEM OU 'M' PARA RETORNAR AO MENU PRINCIPAL: ");
        scanf("\n%s", nome_img);

        if (strcmp(nome_img, "M") == 0 || strcmp(nome_img, "m") == 0)
            break;

        char diretorio_completo[100];
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/%s.csv", entrada, nome_img);

        FILE *file = fopen(diretorio_completo, "r");
        if (file == NULL) {
            printf("ARQUIVO NAO ENCONTRADO\n");
            return;
        }
            

        tImagem *im = criar_imagem();
        ler_imagem(im, file, total_pixels);
        fclose(file);

        int num_bins;
        printf("\nDIGITE A QUANTIDADE DE BINS: ");
        scanf("\n%d", &num_bins);

        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/hist_%d_%s.csv", saida, num_bins, nome_img);
        file = fopen(diretorio_completo, "w");
        if (file == NULL) {
            printf("PROBLEMA AO CRIAR O ARQUIVO\n");
            return;
        }


        float intervalo_min = 0;
        float intervalo_max = log10((float)INTENS_MAX_PIXEL);
        float tam_barra = intervalo_max / (float)num_bins;
        float pixel;

        for (int i = 0; i < num_bins; i++) {
            int cont_pixels = 0;

            for (int j = 0; j < im->num_pixels; j++) {
                pixel = (float)im->pixels[j];
                if (pixel >= intervalo_min && pixel < intervalo_max)
                    cont_pixels++;
            }
                
            fprintf(file, "BIN %d, %d\n", i, cont_pixels);

            intervalo_min = intervalo_max;
            intervalo_max += tam_barra;
        }

        fclose(file);
        free_imagem(im);

        printf("\nHISTOGRAMA DA IMAGEM DEFINIDO. ACESSE O ARQUIVO GERADO PARA VERIFICAR\n\n");

    }
}*/


    //POSSIVEL VERSAO DO HISTOGRAMA QUE SEJA NECESSARIO DIGITAR OS INTERVALOS
/*void gerar_histograma_imagem (const char *entrada, const char *saida, const int total_pixels) {
    while (1) {
        char nome_img[20];
        printf("\nDIGITE O NOME DA IMAGEM OU 'M' PARA RETORNAR AO MENU PRINCIPAL: ");
        scanf("\n%s", nome_img);

        if (strcmp(nome_img, "M") == 0 || strcmp(nome_img, "m") == 0)
            break;

        char diretorio_completo[100];
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/%s.csv", entrada, nome_img);

        FILE *file = fopen(diretorio_completo, "r");
        if (file == NULL) {
            printf("ARQUIVO NAO ENCONTRADO\n");
            return;
        }
            

        tImagem *im = criar_imagem();
        ler_imagem(im, file, total_pixels);
        fclose(file);

        int num_bins;
        printf("\nDIGITE A QUANTIDADE DE BINS: ");
        scanf("\n%d", &num_bins);

        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/hist_%d_%s.csv", saida, num_bins, nome_img);
        file = fopen(diretorio_completo, "w");
        if (file == NULL) {
            printf("PROBLEMA AO CRIAR O ARQUIVO\n");
            return;
        }


        float intervalo_min = 0;
        float intervalo_max = 0;
        //float tam_barra = intervalo_max / (float)num_bins;
        float pixel;

        for (int i = 0; i < num_bins; i++) {
            intervalo_min = intervalo_max;

            printf("DIGITE O INTERVALO MAXIMO DA BIN %d: ", i);
            scanf("\n%f", &intervalo_max);
            
            int cont_pixels = 0;

            for (int j = 0; j < im->num_pixels; j++) {
                pixel = (float)im->pixels[j];
                if (pixel >= intervalo_min && pixel < intervalo_max)
                    cont_pixels++;
            }
                
            fprintf(file, "BIN %d, %d\n", i, cont_pixels);
        }

        fclose(file);
        free_imagem(im);

        printf("\nHISTOGRAMA DA IMAGEM DEFINIDO. ACESSE O ARQUIVO GERADO PARA VERIFICAR\n\n");

    }
}*/