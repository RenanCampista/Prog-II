#include "pauta.h"

int main() {
    int qtd;
    tPauta *alunos = NULL;

    scanf("%d ", &qtd);

    for (int i = 1; i <= qtd; i++) {
        alunos = registraAluno(alunos, i);
    }

    imprimeAlunosAprovados(alunos, qtd);
    imprimeMelhorPior(alunos, qtd);
    ImprimeMediaTurma(alunos, qtd);
    liberaMemoria(alunos, qtd);

    return 0;
}