#ifndef _BALCAO_H
#define _BALCAO_H


typedef struct Balcao tBalcao;

tBalcao *criar_balcao ();

void free_balcao (tBalcao *b);

void ler_balcao (tBalcao *b);

void imprimir_balcao (tBalcao *b);

void realiza_movimentos (tBalcao *b);

#endif