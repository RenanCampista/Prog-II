#include <stdio.h>
#include <stdlib.h>
#include "carta.h"


struct Carta {
    int id;
    char nome[51];
    int magia;
    int forca;
    int fogo;
    int vitorias;
};

tCarta *criar_carta () {
    tCarta *c = (tCarta *) malloc(sizeof(tCarta));
    c->vitorias = 0;
    return c;
}

void free_carta (tCarta *c) {
    free(c);
}

void ler_carta (tCarta *c) {
    scanf("\n%d", &c->id);
    scanf("\n%50[^\n]", c->nome);
    scanf("\n%d %d %d", &c->magia, &c->forca, &c->fogo);
}

int carta_valida (tCarta *c) {
    if (c->magia > 30 || c->forca > 30 || c->fogo > 30) {
        return 0;
    }

    if (c->magia + c->forca + c->fogo > 80) {
        return 0;
    }

    return 1;
}

void registra_vitoria (tCarta *c) {
    c->vitorias++;
}

int verifica_empate (tCarta *c1, tCarta *c2, char atributo) {
    if (atributo == 'M') {
        if (c1->magia == c2->magia)
            return 1;
    } else if (atributo == 'F') {
        if (c1->forca == c2->forca)
            return 1;
    } else if (atributo == 'G') {
        if (c1->fogo == c2->fogo)
            return 1;
    }
    return 0;
}

void desempata_combate (tCarta *c1, tCarta *c2) {
    if (c1->id < c2->id) 
        registra_vitoria(c1);
    else
        registra_vitoria(c2);
}

int retorna_num_vitorias (tCarta *c) {
    return c->vitorias;
}

char *retornar_nome_carta (tCarta *c) {
    return c->nome;
}

int retornar_diferenca_luta (tCarta *c1, tCarta *c2, char atributo) {
    if (atributo == 'M' || atributo == 'm') {
        return (c1->magia - c2->magia);
    } else if (atributo == 'F' || atributo == 'f') {
        return (c1->forca - c2->forca);
    } else if (atributo == 'G' || atributo == 'g') {
        return (c1->fogo - c2->fogo);
    }
    return 0;
}

int realiza_combate (tCarta *c1, tCarta *c2, char atributo) {
    if (atributo == 'M') {
        if (c1->magia > c2->magia) {
            registra_vitoria(c1);
            return retornar_diferenca_luta(c1, c2, atributo);
        }
        else {
            registra_vitoria(c2);
            return retornar_diferenca_luta(c2, c1, atributo);
        }
    } else if (atributo == 'F') {
        if (c1->forca > c2->forca) {
            registra_vitoria(c1);
            return retornar_diferenca_luta(c1, c2, atributo);
        }
        else {
            registra_vitoria(c2);
            return retornar_diferenca_luta(c2, c1, atributo);
        }
    } else if (atributo == 'G') {
        if (c1->fogo > c2->fogo) {
            registra_vitoria(c1);
            return retornar_diferenca_luta(c1, c2, atributo);
        }
        else {
            registra_vitoria(c2);
            return retornar_diferenca_luta(c2, c1, atributo);
        }
    }  
    return 0;
}


int retorna_id_carta (tCarta *c) {
    return c->id;
}
