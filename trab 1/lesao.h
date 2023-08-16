#ifndef _LESAO_H
#define _LESAO_H
#include <stdio.h>
#include "constantes.h"


typedef struct Lesao tLesao;

tLesao *aloca_lesao();

void cadastra_lesao (tLesao *lesao, char cartao_sus[TAM_CARTAO_SUS], char id[100], char diagnostico[100]);

int verifica_cartao_sus_lesao (tLesao *lesao, char cartao[TAM_CARTAO_SUS]);

void imprime_log (tLesao *lesao, FILE *file);

void imprime_lesao_arq_busca (tLesao *lesao, FILE *file);

int retorna_tamanho_lesao (tLesao *lesao);

int identifica_lesao (tLesao *lesao);

int verifica_cirurgia (tLesao *lesao);

int verifica_crioterapia (tLesao *lesao);

void free_lesao (tLesao *lesao);


#endif