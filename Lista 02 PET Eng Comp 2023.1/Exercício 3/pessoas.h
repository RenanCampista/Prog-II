#ifndef _PESSOAS_H
#define _PESSOAS_H


typedef struct Empreiteiro Empreiteiro;

typedef struct Professor Professor;

typedef struct TecAdm TecAdm;

Empreiteiro *empreiteiro_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, int servicos);

void print_empreiteiro (Empreiteiro *e);

void free_empreiteiro (Empreiteiro *e);

Professor *professor_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf, int titulacao);

void print_professor (Professor *p);

void free_professor (Professor *p);

TecAdm *tec_adm_criar (char *nome, int dia_nas, int mes_nas, int ano_nas, char *cpf);

void print_tec_adm (TecAdm *a);

void free_tec_adm (TecAdm *a);


#endif