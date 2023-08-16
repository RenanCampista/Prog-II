#include "partida.h"

struct Partida {
   int time1, time2, gols1, gols2;
};

tPartida *paratida_construir () {
    tPartida *partida = (tPartida *) malloc(sizeof(tPartida));
    if (partida == NULL) {
        printf("Falta de memoria");
        exit(1);
    }
    return partida;
}

void partida_ler(tPartida *partida) {

    scanf("%d %d %d %d ", &partida->time1, &partida->time2, &partida->gols1, &partida->gols2);
}

void partida_destruir(tPartida *partida) {
    free(partida);
}

int partida_jogou(tPartida *partida, int indice) {
    if (partida->time1 == indice || partida->time2 == indice) {
        return 1;
    } else return 0;
}

int partida_vencedor (tPartida *partida) {
    if (partida->gols1 > partida->gols2) {
        return partida->time1;
    } else if (partida->gols2 > partida->gols1) {
        return partida->time2;
    } else {
        return -1;
    }
} 