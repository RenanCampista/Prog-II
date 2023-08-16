#include <stdlib.h>
#include <string.h>
#include "lesao.h"
#include "constantes.h"
#include "layout.h"

struct Lesao {
    char cartao_sus[TAM_CARTAO_SUS], *id, *diagnostico, *regiao_corpo, cirurgia[4], crioterapia[4];
    int tamanho;
};

tLesao *aloca_lesao() {
    tLesao *l = (tLesao *) malloc(sizeof(tLesao));

    if (l == NULL) {
        printf("FALTA MEMORIA PARA ALOCAR UM PACIENTE\n");
        exit(1);
    }
    return l;
}

void cadastra_lesao (tLesao *lesao, char cartao_sus[TAM_CARTAO_SUS], char id[100], char diagnostico[100]) {
    char reg_corpo[100];
    
    strcpy(lesao->cartao_sus, cartao_sus);

    lesao->id = (char *) malloc((strlen(id) + 1) * sizeof(char));
    strcpy(lesao->id, id);

    
    lesao->diagnostico = (char *) malloc((strlen(diagnostico) + 1) * sizeof(char));
    strcpy(lesao->diagnostico, diagnostico);

    printf("\nREGIAO DO CORPO: ");
    scanf("\n%s", reg_corpo);
    lesao->regiao_corpo = (char *) malloc((strlen(reg_corpo) + 1) * sizeof(char));
    strcpy(lesao->regiao_corpo, reg_corpo);

    printf("\nTAMANHO: ");
    scanf("\n%d", &lesao->tamanho);

    printf("\nCIRURGIA: ");
    scanf("\n%s", lesao->cirurgia);

    printf("\nCRIOTERAPIA: ");
    scanf("\n%s", lesao->crioterapia);
}

int verifica_cartao_sus_lesao (tLesao *lesao, char cartao[TAM_CARTAO_SUS]) {
    if (strcmp(lesao->cartao_sus, cartao) == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

void imprime_log (tLesao *lesao, FILE *file) {
    string_to_upper(lesao->diagnostico);
    string_to_upper(lesao->regiao_corpo);
    string_to_upper(lesao->cirurgia);
    string_to_upper(lesao->crioterapia);

    fprintf(file, "%s\n", lesao->id);
}

void imprime_lesao_arq_busca (tLesao *lesao, FILE *file) {
    fprintf(file, "%s - %s - %s - %dMM", lesao->id, lesao->diagnostico, lesao->regiao_corpo, lesao->tamanho);
    if (verifica_cirurgia(lesao) == VERDADEIRO) 
        fprintf(file, " - ENVIADA PARA CIRURGIA");
    else if (verifica_crioterapia(lesao) == VERDADEIRO) 
        fprintf(file, " - ENVIADA PARA CRIOTERAPIA");
    
    fprintf(file, "\n");
}

int retorna_tamanho_lesao (tLesao *lesao) {
    return lesao->tamanho;
}

int identifica_lesao (tLesao *lesao) {
    if (strcmp(lesao->diagnostico, "CARCINOMA BASOCELULAR") == 0) 
        return CARC_BASOCELULAR;
    else if (strcmp(lesao->diagnostico, "CARCINOMA ESPINOCELULAR") == 0) 
        return CARC_ESPINOCELULAR;
    else if (strcmp(lesao->diagnostico, "MELANOMA") == 0) 
        return MELANOMA;
    else if (strcmp(lesao->diagnostico, "CERATOSE ACTINICA") == 0) 
        return CER_ACTINICA;
    else if (strcmp(lesao->diagnostico, "CERATOSE SEBORREICA") == 0) 
        return CER_SEBORREICA;
    else
        return NEVO;
}

int verifica_cirurgia (tLesao *lesao) {
    if (strcmp(lesao->cirurgia, "SIM") == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

int verifica_crioterapia (tLesao *lesao) {
    if (strcmp(lesao->crioterapia, "SIM") == 0)
        return VERDADEIRO;
    else
        return FALSO;
}

void free_lesao (tLesao *lesao) {
    free(lesao->id);
    free(lesao->diagnostico);
    free(lesao->regiao_corpo);
    free(lesao);
}