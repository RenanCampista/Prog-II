#include <stdlib.h>
#include "data.h"
#include "constantes.h"

struct Data {
    char data[TAM_DATA];
};

tData *inicializa_data () {
    tData *d = (tData *) malloc(sizeof(tData));
    if (d == NULL) {
        printf("FALTA MEMORIA PARA REGISTAR A DATA\n");
        exit(1);
    }
    return d;
}

void le_data (tData *data) {
    scanf("\n%s", data->data);
}

int calcula_idade (tData *data_nascimento) {
    int dia, mes, ano, idade;

    sscanf(data_nascimento->data, "%d/%d/%d", &dia, &mes, &ano);
    idade = ANO_ATUAL - ano;

    if (MES_ATUAL < mes || (MES_ATUAL == mes && DIA_ATUAL < dia)) {
        idade--;
    }
    return idade;
}

void imprime_data_arq_busca (tData *data, FILE *file) {
    fprintf(file, "DATA DE NASCIMENTO: %s (%d ANOS)\n", data->data, calcula_idade(data));
}

void free_data (tData *data) {
    free(data);
}