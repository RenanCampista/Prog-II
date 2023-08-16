#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "layout.h"
#include "pad.h"

int main(int argc, char *argv[]) {
    char opcao;
    const char *caminho = argv[1];
    tPad *pad = inicializa_pad();

    if (argc < 2) {
        printf("NECESSARIO INFORMAR O CAMINHO DE ENTRADA E SAIDA EXISTENTES ATRAVES DA LINHA DE COMANDO\n");
        return 1;
    }

    cria_diretorios(caminho);

    while (1) {
        menu_inicial();
        scanf("\n%c", &opcao);
        
        if (opcao == 'P' || opcao == 'p') {
            system("clear||cls");
            cadastrar_paciente(pad);

        } else if (opcao == 'A' || opcao == 'a') {
            system("clear||cls");
            realizar_consulta(pad, caminho);

        } else if (opcao == 'B' || opcao == 'b') {
            system("clear||cls");
            buscar_paciente(pad, caminho);

        } else if (opcao == 'R' || opcao == 'r') {
            system("clear||cls");
            relatorio_final(pad, caminho);

        } else if (opcao == 'F' || opcao == 'f'){
            if (pad != NULL)
                free_pad(pad);
            break;
        } else {
            printf("POR FAVOR, DIGITE UMA OPCAO VALIDA\n");
        }
    }

    return 0;
}