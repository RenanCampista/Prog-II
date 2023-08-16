#ifndef _LUTA_H
#define _LUTA_H

typedef struct Luta tLuta;


tLuta *criar_luta();

void free_luta (tLuta *l);

void realiza_jogo (tLuta *l);

#endif