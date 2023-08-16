#include "time.h"

struct Time {
    char nome[33], estado[3];
};


tTime *time_construir () {
    tTime *time = (tTime *) malloc(sizeof(tTime));
    if (time == NULL) {
        printf("Falta de memoria");
        exit(1);
    }
    return time;
}

void time_ler(tTime *time) {
   // time = time_construir();

    scanf("%s %s", time->nome, time->estado);

    
}

void time_mostrar(tTime *time) {
    printf("%s [%s]", time->nome, time->estado);
}

void time_destruir(tTime *time) {
    free(time);
}