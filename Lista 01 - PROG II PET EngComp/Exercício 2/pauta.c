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

int calculaMedia (tPauta aluno) {
    int media = 0;
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

void liberaMemoria (tPauta *alunos, int tam) {
    for (int i = 0; i < tam; i++) {
        free(alunos[i].nome);
    }
    free(alunos);
}