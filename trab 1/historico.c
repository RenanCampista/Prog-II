#include <stdlib.h>
#include <string.h>
#include "historico.h"
#include "layout.h"

struct Historico {
    char cartao_sus[TAM_CARTAO_SUS], diabetes[4], fumante[4], alergia_medicamento[4], *remedios_alergia, historico_cancer[4], tipo_pele[4];
};

tHistorico *inicializa_historico () {
    tHistorico *t = (tHistorico *) malloc(sizeof(tHistorico));
    if (t == NULL) {
        printf("FALTA MEMORIA PARA ALOCAR O HISTORIO MEDICO DO PACIENTE\n");
        exit(1);
    }
    t->remedios_alergia = NULL;
    return t;
}

void le_hisotorico (tHistorico *historico, char cartao[TAM_CARTAO_SUS]) {
    char remedios[200];
    
    strcpy(historico->cartao_sus, cartao);

    printf("\nDIABETES: ");
    scanf("\n%s", historico->diabetes);

    printf("\nFUMANTE: ");
    scanf("\n%s", historico->fumante);

    printf("\nALERGIA A MEDICAMENTO: ");
    scanf("\n%s", historico->alergia_medicamento);
    string_to_upper(historico->alergia_medicamento);

    if (strcmp(historico->alergia_medicamento, "SIM") == 0) {
        printf("\nNOME DOS REMEDIOS: ");
        scanf("\n%200[^\n]", remedios);
        historico->remedios_alergia = (char *) malloc((strlen(remedios) + 1) * sizeof(char));
        strcpy(historico->remedios_alergia, remedios);
    }

    printf("\nHISTORICO DE CANCER: ");
    scanf("\n%s", historico->historico_cancer);
    
    printf("\nTIPO DE PELE: ");
    scanf("\n%s", historico->tipo_pele);
}

int verifica_cartao_sus_historico (tHistorico *historico, char cartao[TAM_CARTAO_SUS]) {
    if (strcmp(historico->cartao_sus, cartao) == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

void imprime_historico_arq_busca (tHistorico *historico, FILE *file) {
    string_to_upper(historico->diabetes);
    string_to_upper(historico->fumante);
    string_to_upper(historico->historico_cancer);
    //string_to_upper(historico->remedios_alergia);

    fprintf(file, "DIABETES: %s\n", historico->diabetes);
    fprintf(file, "FUMANTE: %s\n", historico->fumante);
    fprintf(file, "ALERGIA A MEDICAMENTO: %s", historico->alergia_medicamento);
    if (strcmp(historico->alergia_medicamento, "SIM") == 0) {
        if (historico->remedios_alergia != NULL) {
            string_to_upper(historico->remedios_alergia);
            fprintf(file, " - %s", historico->remedios_alergia);
        }
    }
    fprintf(file, "\nHISTORICO DE CANCER: %s\n", historico->historico_cancer);
    fprintf(file, "TIPO DE PELE: %s\n", historico->tipo_pele);
}

void free_historico(tHistorico *historico) {
    if (historico != NULL) {
        if (historico->remedios_alergia != NULL)
            free(historico->remedios_alergia);
        free(historico);
    }
}