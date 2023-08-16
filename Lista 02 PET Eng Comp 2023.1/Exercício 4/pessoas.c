#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pessoas.h"
#include "data.h"
#include "constantes.h"
#include "item.h"

struct Empreiteiro {
    char nome[100];
    char cpf[15];
    Data *data_nasc;
    CalculaSalario calculaSalario;
};

struct Professor {
    char nome[100];
    char cpf[15];
    Data *data_nasc;
    CalculaSalario calculaSalario;
};

struct TecAdm {
    char nome[100];
    char cpf[15];
    Data *data_nasc;
    CalculaSalario calculaSalario;
};

Empreiteiro *empreiteiro_criar(char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, CalculaSalario calculaSalario) {
    Empreiteiro *e = (Empreiteiro *)malloc(sizeof(Empreiteiro));
    if (e == NULL) {
        printf("Problema ao criar empreiteiro\n");
        exit(1);
    }

    strcpy(e->nome, nome);
    e->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(e->cpf, cpf);
    e->calculaSalario = calculaSalario;

    return e;
}

void print_empreiteiro(Empreiteiro *e) {
    int salario = e->calculaSalario(EMPREITEIRO);
    printf("%s (Empreiteiro): R$%d\n", e->nome, salario);
}

void free_empreiteiro(Empreiteiro *e) {
    free_data(e->data_nasc);
    free(e);
}

Professor *professor_criar(char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, CalculaSalario calculaSalario) {
    Professor *p = (Professor *)malloc(sizeof(Professor));
    if (p == NULL) {
        printf("Problema ao criar professor\n");
        exit(1);
    }

    strcpy(p->nome, nome);
    p->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(p->cpf, cpf);
    p->calculaSalario = calculaSalario;

    return p;
}

void print_professor(Professor *p) {
    int salario = p->calculaSalario(PROFESSOR);
    printf("%s (Professor): R$%d\n", p->nome, salario);
}

void free_professor(Professor *p) {
    free_data(p->data_nasc);
    free(p);
}

TecAdm *tec_adm_criar(char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, CalculaSalario calculaSalario) {
    TecAdm *a = (TecAdm *)malloc(sizeof(TecAdm));
    if (a == NULL) {
        printf("Problema ao criar adm\n");
        exit(1);
    }

    strcpy(a->nome, nome);
    a->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(a->cpf, cpf);
    a->calculaSalario = calculaSalario;

    return a;
}

void print_tec_adm(TecAdm *a) {
    int salario = a->calculaSalario(TECADM);
    printf("%s (Tec. Administracao): R$%d\n", a->nome, salario);
}

void free_tec_adm(TecAdm *a) {
    free_data(a->data_nasc);
    free(a);
}