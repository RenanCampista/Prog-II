#include "paciente.h"

struct Paciente {
    char *nome, *cartaoSUS, genero, dataNascimento[12];
    int totalLesoes;
    tLesao *lesao;
};


tPaciente* cadastraPaciente (tPaciente *paciente, int totalPacientes) {
    int i = totalPacientes - 1; //Melhorar visualizacao
    char nome[100], cartao[20];

    if (totalPacientes <= 0) {
        paciente = (tPaciente *) malloc(sizeof(tPaciente));
    } else {
        paciente = (tPaciente *) realloc(paciente, totalPacientes * sizeof(tPaciente));
    }

    if (paciente == NULL) {
        // tratamento de erro, se a alocação falhar
        printf("Erro: não foi possível alocar memória\n");
        exit(1);
    }

    scanf("%s ", nome);
    scanf("%s ", paciente[i].dataNascimento);
    scanf("%20[^\n] ", cartao);
    scanf("%c ", &paciente[i].genero);

    paciente[i].nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(paciente[i].nome, nome);

    paciente[i].cartaoSUS = (char *) malloc((strlen(cartao) + 1) * sizeof(char));
    strcpy(paciente[i].cartaoSUS, cartao);
    
    paciente[i].totalLesoes = 0;
    paciente[i].lesao = NULL;

    return paciente;
}


int calculaIdade (tPaciente paciente) {
    int idade, diaNasc, mesNasc, anoNasc;

    sscanf(paciente.dataNascimento, "%d/%d/%d", &diaNasc, &mesNasc, &anoNasc);

    if (MES_ATUAL > mesNasc || (MES_ATUAL == mesNasc && DIA_HOJE >= diaNasc)) {
        idade = ANO_ATUAL - anoNasc;
    } else {
        idade = ANO_ATUAL - anoNasc - 1;
    }
    return idade;
}

int calculaMediaIdade (tPaciente *paciente, int totalPacientes) {
    int mediaIdade = 0;

    for (int i = 0; i < totalPacientes; i++) {
        mediaIdade += calculaIdade(paciente[i]);
    }

    return (mediaIdade / totalPacientes); 
}

void cadastraLesao (tPaciente *paciente, int totalPacientes) {
    int pos = -1;
    char cartaoSUS[20];

    scanf("%20[^\n] ", cartaoSUS);

    for (int i = 0; i < totalPacientes; i++) {
        if (strcmp(paciente[i].cartaoSUS, cartaoSUS) == 0) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        paciente[pos].totalLesoes++;

        paciente[pos].lesao = vincularLesao(paciente[pos].lesao, paciente[pos].totalLesoes);
    }
}

int totalLesoes (tPaciente *paciente, int totalPacientes) {
    int total = 0;

    for (int i = 0; i < totalPacientes; i++) {
        total += paciente[i].totalLesoes;
    }
    return total;
}

int contabilizaCirurgias (tPaciente *paciente, int totalPacientes) {
    int total = 0;

    for (int i = 0; i < totalPacientes; i++) {
        total += verificaCirurgia(paciente[i].lesao, paciente[i].totalLesoes);
    }

    return total;
}

void imprimeRelatorio (tPaciente *paciente, int totalPacientes) {
    for (int i = 0; i < totalPacientes; i++) {
        if (paciente[i].totalLesoes > 0) {
            printf("- %s -", paciente[i].nome);
            imprimeLesao(paciente[i].lesao, paciente[i].totalLesoes);
        }
    }
}

void liberaMemoria (tPaciente *paciente, int totalPacientes) {
    for (int i = 0; i < totalPacientes; i++) {
        liberaMemoriaLesao(paciente[i].lesao, paciente[i].totalLesoes);
        free(paciente[i].nome);
        free(paciente[i].cartaoSUS);
    }
    free(paciente);
}