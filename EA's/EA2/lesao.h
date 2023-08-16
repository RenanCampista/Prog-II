#ifndef _LESAO_H
#define _LESAO_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Lesao tLesao;

tLesao* vincularLesao (tLesao *lesao, int totalLesoes);

int verificaCirurgia (tLesao *lesao, int totalLesoes);

void imprimeLesao (tLesao *lesao, int totalLesoes);

void liberaMemoriaLesao (tLesao *lesao, int totalLesoes);


#endif