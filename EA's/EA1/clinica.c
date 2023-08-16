#include "clinica.h"

void cleanBuffer() {
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void cadastraPaciente (tPaciente paciente[MAXPACIENTES]) {
    int i;

    for (i = 0; i < MAXPACIENTES; i++) {
        if (paciente[i].registrado != VERDADEIRO) {
            break;
        }
    }

    cleanBuffer();
    scanf("%s", paciente[i].nome);
    cleanBuffer();
    scanf("%d/%d/%d", &paciente[i].nasc.dia, &paciente[i].nasc.mes, &paciente[i].nasc.ano);
    cleanBuffer();
    scanf("%s", paciente[i].cartaoSus);
    cleanBuffer();
    scanf("%c", &paciente[i].genero);
    cleanBuffer();
    paciente[i].registrado = VERDADEIRO;
}

void cadastraLesao (tPaciente paciente[MAXPACIENTES]) {
    int i, j, aux = 0;
    char cartaoS[20];

    scanf("%s", cartaoS);

    for (i = 0; i < MAXPACIENTES; i++) {
        if (strcmp(paciente[i].cartaoSus, cartaoS) == 0) {
            aux = VERDADEIRO;
            break;
        }
    }
    if (aux == VERDADEIRO) {
        for (j = 0; j < MAXLESOES; j++) {
            if (paciente[i].lesao[j].situacao != VERDADEIRO) {
                cleanBuffer();
                scanf("%s", paciente[i].lesao[j].id);
                cleanBuffer();
                scanf("%100[^\n]", paciente[i].lesao[j].diagnostico);
                cleanBuffer();
                scanf("%s", paciente[i].lesao[j].regCorpo);
                cleanBuffer();
                scanf("%d", &paciente[i].lesao[j].malignidade);
                cleanBuffer();
                paciente[i].lesao[j].situacao = VERDADEIRO;
                break;
            }
        }
    }
}

int idadePaciente (tPaciente paciente) {
    if (paciente.nasc.mes < MESATUAL) {
        return ANOATUAL - paciente.nasc.ano;
    } else if (paciente.nasc.mes == MESATUAL) {
        if (paciente.nasc.dia <= DIAHOJE) {
            return ANOATUAL - paciente.nasc.ano;
        } else {
            return ANOATUAL - paciente.nasc.ano - 1;
        }
    } else {
        return ANOATUAL - paciente.nasc.ano - 1;
    }
}

int contaCirurgia (tPaciente paciente) {
    int i, cont = 0;

    for (i = 0; i < MAXLESOES; i++) {
        if (paciente.lesao[i].situacao == VERDADEIRO && paciente.lesao[i].malignidade > 50) {
            cont++;
        }
    }
    return cont;
}

int contaLesao (tPaciente paciente) {
    int i, cont = 0;

    for (i = 0; i < MAXLESOES; i++) {
        if (paciente.lesao[i].situacao == VERDADEIRO) {
            cont++;
        }
    }
    return cont;
}


void dadosGerais (tPaciente paciente[MAXPACIENTES]) {
    int totalPacientes = 0, mediaIdade = 0, totalCirurgias = 0, totalLesoes = 0, i;

    for (i = 0; i < MAXPACIENTES; i++) {
        if (paciente[i].registrado == VERDADEIRO) {
            totalPacientes++;
            mediaIdade += idadePaciente(paciente[i]);
            totalLesoes += contaLesao(paciente[i]);
            totalCirurgias += contaCirurgia(paciente[i]);
        }
    }

    mediaIdade = mediaIdade / totalPacientes;

    printf("TOTAL PACIENTES: %d\n", totalPacientes);
    printf("MEDIA IDADE (ANOS): %d\n", mediaIdade);
    printf("TOTAL LESOES: %d\n", totalLesoes);
    printf("TOTAL CIRURGIAS: %d\n", totalCirurgias);
}


void imprimePacientes (tPaciente paciente[MAXPACIENTES]) {
    int i, j, aux;

    printf("LISTA DE PACIENTES:\n");

    for (i = 0; i < MAXPACIENTES; i++) {
        if (paciente[i].registrado == VERDADEIRO) {
            aux = 0;
            for (j = 0; j < MAXLESOES; j++) {
                if (paciente[i].lesao[j].situacao == VERDADEIRO) {
                    if (aux == 0) {
                        printf("- %s - ", paciente[i].nome);
                    }
                    printf("%s ", paciente[i].lesao[j].id);
                    aux = 1;
                }
            }
            if (aux == 1) {
                printf("\n");
            }
        }
    }
}
