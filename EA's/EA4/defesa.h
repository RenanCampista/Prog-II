#ifndef _DEFESA_H
#define _DEFESA_H

typedef struct Defesa tDefesa;


tDefesa *criar_defesa ();

void free_defesa (tDefesa *d);

void ler_defesa (tDefesa *d, char nome[50]);

float retornar_x_def (tDefesa *d);

float retornar_y_def (tDefesa *d);

float retornar_tam_def (tDefesa *d);

float retornar_poder_def (tDefesa *d);

int retornar_qtd_def (tDefesa *d) ;

void reduzir_def (tDefesa *d);

void imprimir_def (tDefesa *d);

int verifica_sobrepos (tDefesa *d1, tDefesa *d2);

int verifica_qtd_def_disp (tDefesa *d);

#endif