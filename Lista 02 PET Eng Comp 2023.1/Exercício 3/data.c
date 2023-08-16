#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data {
    int dia, mes, ano;
};

Data *data_create (int dia, int mes, int ano) {
    Data *d = (Data *) malloc(sizeof(Data));
    if (d == NULL) {
        printf("Problema ao criar data\n");
        exit(1);
    }

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void free_data (Data *d) {
    free(d);
}