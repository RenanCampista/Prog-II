#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "uteis.h"

void menu_inicial () {
    printf("######################### MENU INICIAL ###########################\n");
    printf("Escolha uma opcao:\n");
    printf("- Executar algoritmo de agrupamento (A ou a)\n");
    printf("- Determinar o grupo de uma imagem (G ou g)\n");
    printf("- Obter o histograma de uma imagem (H ou h)\n");
    printf("- Reconstruir uma imagem (R ou r)\n");
    printf("- Finalizar programa (F ou f)\n");
    printf("###############################################################\n");
}

int total_arquivos (const char *diretorio) {
    DIR *dir;
   struct dirent *ent;
   int num_arquivos = 0;

   dir = opendir(diretorio);

    if (dir != NULL) {
        while((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                num_arquivos++;
            }
        }
        closedir(dir);
   } else {
        printf("NAO FOI POSSIVEL ABRIR O DIRETORIO DAS IMAGENS.\n");
        exit(1);
   }
   return num_arquivos;
}