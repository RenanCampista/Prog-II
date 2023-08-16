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
    int salario;
};

struct Professor {
    char nome[100];
    char cpf[15];
    Data *data_nasc;
    int salario_base;
    int bonus;
};

struct TecAdm {
    char nome[100];
    char cpf[15];
    Data *data_nasc;
    int salario_fixo;
};

Empreiteiro *empreiteiro_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, int servicos) {
    Empreiteiro *e = (Empreiteiro *) malloc(sizeof(Empreiteiro));
    if (e == NULL) {
        printf("Problema ao criar empreiteiro\n");
        exit(1);
    }

    strcpy(e->nome, nome);
    e->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(e->cpf, cpf);
    e->salario = servicos * 0.1;
    
    return e;
}

void print_empreiteiro (Empreiteiro *e) {
    printf("%s (Empreiteiro): R$%d\n", e->nome, e->salario);
}

void free_empreiteiro (Empreiteiro *e) {
    free_data(e->data_nasc);
    free(e);
}

Professor *professor_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, int titulacao) {
    Professor *p = (Professor *) malloc(sizeof(Professor));
    if (p == NULL) {
        printf("Problema ao criar professor\n");
        exit(1);
    }

    strcpy(p->nome, nome);
    p->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(p->cpf, cpf);
    p->salario_base = SALARIO_BASE_PROF;

    if (titulacao == DOUTORADO)
        p->bonus = BONUS_TITUL_DOUT;
    else if (titulacao == MESTRADO)
        p->bonus = BONUS_TITUL_MEST;

    return p;
}

void print_professor (Professor *p) {
    printf("%s (Professor): R$: %d\n", p->nome, p->salario_base + p->bonus);
}

void free_professor (Professor *p) {
    free_data(p->data_nasc);
    free(p);
}

TecAdm *tec_adm_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf) {
    TecAdm *a = (TecAdm *) malloc(sizeof(TecAdm));
    if (a == NULL) {
        printf("Problema ao criar adm\n");
        exit(1);
    }

    strcpy(a->nome, nome);
    a->data_nasc = data_create(dia_nas, mes_nas, ano_nas);
    strcpy(a->cpf, cpf);
    a->salario_fixo = SALARIO_FIXO_ADM;

    return a;
}

void print_tec_adm (TecAdm *a) {
    printf("%s (Tec. Administracao): R$%d", a->nome, a->salario_fixo);
}

void free_tec_adm (TecAdm *a) {
    free_data(a->data_nasc);
    free(a);
}