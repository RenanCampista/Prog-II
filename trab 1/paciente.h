#ifndef _PACIENTE_H
#define _PACIENTE_H
#include <stdio.h>
#include "constantes.h"


typedef struct Paciente tPaciente;

tPaciente *aloca_paciente();

void le_paciente (tPaciente *paciente, char nome_paciente[101], char cartao_sus[TAM_CARTAO_SUS]);

char *retorna_cartao_sus_paciente  (tPaciente *paciente);

int verifica_consulta (tPaciente *paciente);

int verifica_cartao_sus_paciente (tPaciente *paciente, char cartao[TAM_CARTAO_SUS]);

void atribui_consulta(tPaciente *paciente);

void imprime_paciente_arq_busca (tPaciente *paciente, FILE *file);

int retorna_idade (tPaciente *paciente);

int identifica_genero (tPaciente *paciente);

void free_paciente (tPaciente *paciente);


#endif