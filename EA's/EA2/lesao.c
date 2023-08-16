#include "lesao.h"

struct Lesao {
    char *id, *diagnostico, *regCorpo;
    int malignidade;
};

tLesao* vincularLesao (tLesao *lesao, int totalLesoes) {
    char id[10], diag[100], regCorp[100];

    lesao = (tLesao*) realloc(lesao, totalLesoes*sizeof(tLesao));

    scanf("%s ", id);
    scanf("%100[^\n] ", diag);
    scanf("%100[^\n] ", regCorp);
    scanf("%d ", &lesao[totalLesoes-1].malignidade);

    lesao[totalLesoes-1].id = (char*) malloc((strlen(id) + 1) * sizeof(char));
    strcpy(lesao[totalLesoes-1].id, id);

    lesao[totalLesoes-1].diagnostico = (char*) malloc((strlen(diag) + 1) * sizeof(char));
    strcpy(lesao[totalLesoes-1].diagnostico, diag);

    lesao[totalLesoes-1].regCorpo = (char*) malloc((strlen(regCorp) + 1) * sizeof(char));
    strcpy(lesao[totalLesoes-1].regCorpo, regCorp);

    return lesao;
}

int verificaCirurgia (tLesao *lesao, int totalLesoes) {
    int qtd = 0;

    for (int i = 0; i < totalLesoes; i++) {
        if (lesao[i].malignidade > 50) {
            qtd++;
        }
    }

    return qtd; 
}

void imprimeLesao (tLesao *lesao, int totalLesoes) {
    for (int i = 0; i < totalLesoes; i++) {
        printf(" %s", lesao[i].id);
    }
    printf("\n");
}

void liberaMemoriaLesao (tLesao *lesao, int totalLesoes) {
    for (int i = 0; i < totalLesoes; i++) {
        free(lesao[i].id);
        free(lesao[i].diagnostico);
        free(lesao[i].regCorpo);
    }
    free(lesao);
}