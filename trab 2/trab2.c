#include <stdio.h>
#include <stdlib.h>
#include "uteis.h"
#include "imagem.h"
#include "agrupamento.h"

int main (int argc, char *argv[]) {
    if (argc < 3) {
        printf("NECESSARIO INFORMAR O CAMINHO DE ENTRADA E SAIDA EXISTENTES ATRAVES DA LINHA DE COMANDO\n");
        return 1;
    }

    int k_means_executado = 0;
    char opcao;
    tAgrupamento *imgs = criar_agrupamento();
    
    const char *entradas = argv[1];
    const char *saidas = argv[2];
    const int total_imagens = total_arquivos(entradas);
    const int total_pixels = total_pixels_leitura(entradas);

    while (1) {
        menu_inicial();
        scanf("\n%c", &opcao);

        if (opcao == 'A' || opcao == 'a') {
            system("clear||cls");
            if (k_means_executado == 0)
                ler_base_imagens(imgs, entradas, total_imagens, total_pixels);
            else
                limpar_agrupamento(imgs);

            k_means(imgs);
            imprimir_centroides(imgs, saidas);

            k_means_executado = 1;
        } else if (opcao == 'G' || opcao == 'g') {
            system("clear||cls");
            if (k_means_executado == 0) {
                printf("PRIMEIRO EH NECESSARIO EXECUTAR O ALGORITMO DE AGRUPAMENTO");
                continue;
            }

            imprimir_grupo_imagem(imgs, saidas);
        } else if (opcao == 'H' || opcao == 'h') {
            system("clear||cls");
            gerar_histograma_imagem(entradas, saidas, total_pixels);
        } else if (opcao == 'R' || opcao == 'r') {
            system("clear||cls");
            reconstruir_imagem(entradas, saidas, total_pixels);
        } else if (opcao == 'F' || opcao == 'f') {
            free_agrupamento(imgs);
            break;

        } else {
            system("clear||cls");
            printf("POR FAVOR, DIGITE UMA OPCAO VALIDA\n");
        }
    }

    return 0;
}
