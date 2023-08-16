#ifndef _PAUTA_H
#define _PAUTA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pauta tPauta;

tPauta* registraAluno (tPauta *alunos, int tam);

void imprimeAlunosAprovados (tPauta *alunos, int tam);

void ImprimeMediaTurma (tPauta *alunos, int tam);

void imprimeMelhorPior(tPauta *alunos, int tam);

void liberaMemoria (tPauta *alunos, int tam);

#endif