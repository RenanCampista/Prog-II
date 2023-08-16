#ifndef _CARTA_H
#define _CARTA_H


typedef struct Carta tCarta;


tCarta *criar_carta ();

void free_carta (tCarta *c);

void ler_carta (tCarta *c);

int carta_valida (tCarta *c);

void registra_vitoria (tCarta *c);

int verifica_empate (tCarta *c1, tCarta *c2, char atributo);

void desempata_combate (tCarta *c1, tCarta *c2);

int realiza_combate (tCarta *c1, tCarta *c2, char atributo);

int retorna_num_vitorias (tCarta *c);

char *retornar_nome_carta (tCarta *c);

int retorna_id_carta (tCarta *c);

#endif