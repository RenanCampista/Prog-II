#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constantes.h"
#include "imagem.h"
#include"centroide.h"
#include "agrupamento.h"

struct Agrupamento {
    tCentroide **grupos;
    tImagem **imagens;

    int num_imagens;
    int num_grupos;

    int *grupo_da_img;
};

tAgrupamento *criar_agrupamento () {
    tAgrupamento *a = (tAgrupamento *) malloc(sizeof(tAgrupamento));
    if (a == NULL) {
        printf("PROBLEMA AO ALOCAR AGRUPAMENTO.\n");
        exit(1);
    }
    
    a->num_imagens = 0;
    a->num_grupos = 0;
    
    a->imagens = NULL;
    a->grupos = NULL;
    a->grupo_da_img = NULL;

    return a;
}

void free_agrupamento (tAgrupamento *a) {
    for (int i = 0; i < a->num_grupos; i++) {
        free_centroide(a->grupos[i]);
    }

    for (int i = 0; i < a->num_imagens; i++) {
        free_imagem(a->imagens[i]);
    }

    if (a->imagens != NULL)
        free(a->imagens);
    if (a->grupos != NULL)
        free(a->grupos);
    if (a->grupo_da_img != NULL)
        free(a->grupo_da_img);
    free(a);
}

void limpar_agrupamento (tAgrupamento *a) {
    /*
        ESSA FUNCAO TAMBEM LIBERA MEMORIA, MAS NAO POR COMPLETO
        APENAS DISPONIBILIZA O PONTEIRO PARA EXECUTAR O ALGORITMO MAIS DE UMA VEZ
    */
    for (int i = 0; i < a->num_grupos; i++) {
        free_centroide(a->grupos[i]);
    }

    if (a->grupos != NULL) {
        free(a->grupos);
        a->grupos = NULL;
        a->num_grupos = 0;
    }

   if (a->grupo_da_img != NULL) {
        free(a->grupo_da_img);
        a->grupo_da_img = NULL;
   }
}

void ler_base_imagens (tAgrupamento *a, const char *diretorio, const int total_imgs, const int total_pixels) {
    a->imagens = (tImagem **) malloc(total_imgs * sizeof(tImagem *));
    if (a->imagens == NULL) {
        printf("PROBLEMA AO ALOCAR PONTEIRO DUPLO DAS IMAGENS.\n");
        exit(1);
    }
    char diretorio_completo[100];
    FILE *arquivo;

    for (int i = 0; i < total_imgs; i++) {
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/imagem_%d.csv", diretorio, a->num_imagens);
        
        arquivo = fopen(diretorio_completo, "r");
        if (arquivo == NULL) {
            printf("ARQUIVO NAO ENCONTRADO\n");
            continue;
        }
        
        tImagem *im = criar_imagem();
        ler_imagem(im, arquivo, total_pixels);
        fclose(arquivo);

        a->imagens[a->num_imagens] = im;
        a->num_imagens++;
    }
}


    //FUNCIONALIDADE 1
void definir_centroides_iniciais (tAgrupamento *a) {
    printf("\nDEFINA A QUANTIDADE DE GRUPOS: ");
    scanf("\n%d", &a->num_grupos);

    if (a->num_grupos > 0)
        a->grupos = (tCentroide **) malloc( a->num_grupos * sizeof(tCentroide *));
    
    char nome_img[50];
    int id;
    for (int i = 0; i < a->num_grupos; i++) {
        
        printf("\nIMAGEM DA CENTROIDE %d: ", i+1);
        scanf("\n%s", nome_img);
        
        sscanf(nome_img, "%*[^0-9]%d", &id);

        a->grupos[i] = criar_centroide();

        if (id < a->num_imagens)
            associar_centroide_inicial(a->grupos[i], a->imagens[id]);
    }
}

void distribuir_grupos (tAgrupamento *a) {
    float dist, menor_dist;
    
    for (int i = 0; i < a->num_grupos; i++) {
        limpar_grupo(a->grupos[i]);
    }

    for (int i = 0; i < a->num_imagens; i++) {
        menor_dist = retornar_dist_centroide(a->grupos[0], a->imagens[i]);
        a->grupo_da_img[i] = 0;

        for (int j = 1; j < a->num_grupos; j++) {
            dist = retornar_dist_centroide(a->grupos[j], a->imagens[i]);

            if (dist < menor_dist) {
                menor_dist = dist;
                a->grupo_da_img[i] = j;
            }
        }
        adicionar_img_ao_grupo(a->grupos[a->grupo_da_img[i]], a->imagens[i]);
    }
}

void atualizar_grupos (tAgrupamento *a) {
    for (int i = 0; i < a->num_grupos; i++) {
        atualizar_media_grupo(a->grupos[i]);
    }
}

void k_means (tAgrupamento *a) {
    definir_centroides_iniciais(a);

    a->grupo_da_img = (int *) malloc(a->num_imagens * sizeof(int));

    int max_interacoes;
    printf("\nDEFINA A QUANTIDADE MAXIMA DE INTERACOES: ");
    scanf("\n%d", &max_interacoes);

    if (a->num_grupos > 0 && max_interacoes > 0) {
        for (int i = 0; i < max_interacoes; i++) {
            distribuir_grupos(a);
            atualizar_grupos(a);
        }
    }

    char voltar_menu;
    scanf("\n%c", &voltar_menu);
    //PROFESSOR DISSE QUE SEMPRE SERA O CARACTER 'M' ENTAO NAO PRECISA FAZER TRATAMENTO DE ERRO
}

void imprimir_centroides (tAgrupamento *a, const char *diretorio) {
    char diretorio_completo[100];
    snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/centroides.csv", diretorio);
    
    FILE *file = fopen(diretorio_completo, "w");
    if (file == NULL) {
        printf("\nERRO AO ABRIR O ARQUIVO.\n");
        return;
    }

    for (int i = 0; i < a->num_grupos; i++) {
        imprimir_media_grupo(a->grupos[i], file);
    }

    fclose(file);
}


    //FUNCIONALIDADE 2
void imprimir_grupo_imagem (tAgrupamento *a, const char *saida) {
    while(1) {
        char nome_img[20];
        printf("\nDIGITE O NOME DA IMAGEM OU 'M' PARA RETORNA AO MENU PRINCIPAL: ");
        scanf("\n%s", nome_img);

        if (strcmp(nome_img, "M") == 0 || strcmp(nome_img, "m") == 0)
            break;

        char diretorio_completo[100];
        snprintf(diretorio_completo, sizeof(diretorio_completo), "%s/grupo_%s.csv", saida, nome_img);

        int id;
        sscanf(nome_img, "%*[^0-9]%d", &id);

        if (id < a->num_imagens) {
            FILE *file = fopen(diretorio_completo, "w");
            if (file == NULL) {
                printf("PROBLEMA AO CRIAR O ARQUIVO\n");
                return;
            }
            fprintf(file, "%d\n", a->grupo_da_img[id]);
            fclose(file);

            printf("\nGRUPO DA IMAGEM DEFINIDA. ACESSE O ARQUIVO GERADO PARA VERIFICAR\n\n");
        }
    }
}
