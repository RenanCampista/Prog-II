#ifndef _VETOR_H
#define _VETOR_H


typedef struct Vetor tVetor;

tVetor *criar (int tam, int tipo);

void preencher(tVetor *v);

void imprimir_vetor (tVetor *v);

double calcula_op(tVetor *v, char o);

void free_vetor(tVetor *v);


#endif