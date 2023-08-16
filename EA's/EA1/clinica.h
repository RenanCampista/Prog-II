#ifndef _CLINICA_H
#define _CLINICA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define MAXPACIENTES 100
#define MAXLESOES 10
#define DIAHOJE 13
#define MESATUAL 4
#define ANOATUAL 2023

typedef struct lesao {
    char id[10], diagnostico[100], regCorpo[100];
    int situacao, malignidade;
} tLesao;

typedef struct data {
    int dia, mes, ano;
} tData;

typedef struct paciente{
    char nome[100], cartaoSus[20], genero;
    int registrado;
    tLesao lesao[MAXLESOES];
    tData nasc;
} tPaciente;

void cleanBuffer ();

void cadastraPaciente (tPaciente paciente[MAXPACIENTES]);

void cadastraLesao(tPaciente paciente[MAXPACIENTES]);

int idadePaciente (tPaciente paciente);

void dadosGerais (tPaciente paciente[MAXPACIENTES]);

int contaCirurgia (tPaciente paciente);

int contaLesao (tPaciente paciente);

void imprimePacientes (tPaciente paciente[MAXPACIENTES]); 


#endif