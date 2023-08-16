#ifndef _ATAQUE_H
#define _ATAQUE_H

typedef struct Ataque tAtaque;

tAtaque *criar_ataque ();

void free_ataque (tAtaque *a);

void ler_ataque (tAtaque *a, char nome[50]);

int verifica_colisao_atq (tAtaque *a, float x_cid, float y_cid);

float retornar_dano_causado (tAtaque *a, float poder_def);

void registrar_dano_missil (tAtaque *a, float dano);

int verifica_acertou_def (tAtaque *a, float x_def, float y_def, float tam);

float retornar_poder_mis (tAtaque *a);

void imprimri_missil (tAtaque *a);

#endif