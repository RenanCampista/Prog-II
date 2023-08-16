#ifndef _PACIENTE_H
#define _PACIENTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lesao.h"


#define DIA_HOJE 13
#define MES_ATUAL 4
#define ANO_ATUAL 2023

typedef struct Paciente tPaciente;

tPaciente* cadastraPaciente (tPaciente *paciente, int totalPacientes);

int calculaIdade (tPaciente paciente);

int calculaMediaIdade (tPaciente *paciente, int totalPacientes);

void cadastraLesao (tPaciente *paciente, int totalPacientes);

int totalLesoes (tPaciente *paciente, int totalPacientes);

int contabilizaCirurgias (tPaciente *paciente, int totalPacientes);

void imprimeRelatorio (tPaciente *paciente, int totalPacientes);

void liberaMemoria (tPaciente *paciente, int totalPacientes);


#endif