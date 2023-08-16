#include <stdio.h>
#include <stdlib.h>
#include "imagem.h"

int main() {
    tImagem *img = criar_imagem();
    FILE *file = fopen("img-1-int.bin", "rb");
    if (file == NULL) {
        printf("Problema ao tentar abrir o arquivo\n");
        exit(1);
    }
    ler_arqv_imagem(img, file);
    fclose(file);

    int maior = retorna_maior_pixel(img);
    int menor = retorna_menor_pixel(img);
    int medio = retorna_pixel_medio(img);

    printf("Maior pixel: %d\n", maior);
    printf("Menor pixel: %d\n", menor);
    printf("Pixel medio: %d\n", medio);

    free_imagem(img);
    return 0;
}