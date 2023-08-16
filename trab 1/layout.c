#include <stdio.h>
#include <string.h>
#include "layout.h"

void menu_inicial () {
    printf("######################### MENU INICIAL ###########################\n");
    printf("Escolha uma opcao:\n");
    printf("- Pre-cadastrar um paciente (P ou p)\n");
    printf("- Iniciar um atendimento (A ou a)\n");
    printf("- Buscar um paciente (B ou b)\n");
    printf("- Gerar relatorio (R ou r)\n");
    printf("- Finalizar programa (F ou f)\n");
    printf("###############################################################\n");
}

void string_to_upper(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}