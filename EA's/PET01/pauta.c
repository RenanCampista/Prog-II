#include "pauta.h"

struct pauta {
    char *nome;
    int matricula, n1, n2, n3;
};


tPauta* registraAluno (tPauta *alunos, int tam) {
    char nome[20];

    alunos = (tPauta *) realloc(alunos, tam * sizeof(tPauta));

    scanf("%20[^\n] ", nome);
    scanf("%d ", &alunos[tam-1].matricula);
    scanf("%d %d %d ", &alunos[tam-1].n1, &alunos[tam-1].n2, &alunos[tam-1].n3);

    alunos[tam-1].nome = (char *) malloc((strlen(nome) + 1) * sizeof(char));
    strcpy(alunos[tam-1].nome, nome);

    return alunos;
}

void ordenaMatricula (tPauta *alunos, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        for (int j = i + 1; j < tam; j++) {
            if (alunos[i].matricula > alunos[j].matricula) {
                tPauta aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

float calculaMedia (tPauta aluno) {
    float media = 0;
    media = (aluno.n1 + aluno.n2 + aluno.n3) / 3;
    
    return media;
}

void imprimeAlunosAprovados (tPauta *alunos, int tam) {
    ordenaMatricula(alunos, tam);
    
    printf("Alunos Aprovados:\n");
    for (int i = 0; i < tam; i++) {
        if (calculaMedia(alunos[i]) >= 7) {
            printf("%s\n", alunos[i].nome);
        }
    }
}

void ImprimeMediaTurma (tPauta *alunos, int tam) {
    float mediaGeral = 0;

    for (int i = 0; i < tam; i++) {
        mediaGeral += calculaMedia(alunos[i]);
    }
    mediaGeral /= tam;
    printf("Media da turma: %.2f", mediaGeral);
}

void imprimeMelhorPior(tPauta *alunos, int tam) {
    tPauta melhor = alunos[0], pior = alunos[0];

    for (int i = 0; i < tam; i++) {
        if (calculaMedia(melhor) < calculaMedia(alunos[i])) {
            melhor = alunos[i];
        } else if (calculaMedia(melhor) == calculaMedia(alunos[i])) {
            if (alunos[i].n3 > melhor.n3) {
                melhor = alunos[i];
            } else if (alunos[i].n3 == melhor.n3) {
                if (strcmp(melhor.nome, alunos[i].nome) == 1) {
                    melhor = alunos[i];
                }
            }
        }
    }

    for (int i = 0; i < tam; i++) {
        if (calculaMedia(pior) > calculaMedia(alunos[i])) {
            pior = alunos[i];
        } else if (calculaMedia(pior) == calculaMedia(alunos[i])) {
            if (alunos[i].n3 < pior.n3) {
                pior = alunos[i];
            } else if (alunos[i].n3 == pior.n3) {
                if (strcmp(pior.nome, alunos[i].nome) == 1) {
                    pior = alunos[i];
                }
            }
        }
    }
    printf("\nMelhor aluno: %s\n", melhor.nome);
    printf("Pior aluno: %s\n\n", pior.nome);
}

void liberaMemoria (tPauta *alunos, int tam) {
    for (int i = 0; i < tam; i++) {
        free(alunos[i].nome);
    }
    free(alunos);
}