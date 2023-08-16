#ifndef _HISTORICO_H
#define _HISTORICO_H
#include <stdio.h>
#include "constantes.h"


typedef struct Historico tHistorico;

tHistorico *inicializa_historico ();

void le_hisotorico (tHistorico *historico, char cartao[TAM_CARTAO_SUS]);

int verifica_cartao_sus_historico (tHistorico *historico, char cartao[TAM_CARTAO_SUS]);

void imprime_historico_arq_busca (tHistorico *historico, FILE *file);

void free_historico(tHistorico *historico);

#endif