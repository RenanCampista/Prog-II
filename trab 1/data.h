#ifndef _DATA_H
#define _DATA_H
#include <stdio.h>


typedef struct Data tData;

tData *inicializa_data ();

void le_data (tData *data);

int calcula_idade (tData *data_nascimento);

void imprime_data_arq_busca (tData *data, FILE *file);

void free_data (tData *data);


#endif